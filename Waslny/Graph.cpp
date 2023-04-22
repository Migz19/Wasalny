#include "Graph.h"

Graph::Graph()
{
	sizeOfList = 100;
	adjList.resize(sizeOfList);

	maxNodeMappingId = 1;
	maxEdgeMappingId = 1;
}

void Graph::addNode(string node)
{
	if (NodeExists(node))
		throw GraphException("Node already exists");

	if (!freeNodeMappingIds.empty())  // when a node is removed its Id can be reused so the all the ids of deleted nodes are stored in freeNodeMappingIds
	{
		int lastAvailable = freeNodeMappingIds.size() - 1;
		nodeMapper[node] = freeNodeMappingIds[lastAvailable];
		freeNodeMappingIds.pop_back();
	}
	else
	{
		nodeMapper[node] = maxNodeMappingId++;
	}

	if (maxNodeMappingId == adjList.size())
		adjList.resize(adjList.size() * 2);


}

void Graph::addDirectedEdge(string from, string to, string edgeName ,int distance)
{
	if (!NodeExists(from) || !NodeExists(to))
		throw GraphException("Node doesn't exist");
	else if (EdgeExists(edgeName))
		throw GraphException("Edge already exists");
	else if(distance <= 0)
		throw GraphException("Invalid distance");

	int node1 = nodeMapper[from];
	int node2 = nodeMapper[to];
	
	if (!edgeMappingResults.empty())  // when an edge is removed its Id can be reused so the all the ids of deleted edges are stored in edgeMappingResults
	{
		int lastAvailable = edgeMappingResults.size() - 1;
		edgeMapper[edgeName] = edgeMappingResults[lastAvailable];
		edgeMappingResults.pop_back();
	}
	else
	{
		edgeMapper[edgeName] = maxEdgeMappingId++;
	}

	int currEdgeId = edgeMapper[edgeName];
	edgeDistance[currEdgeId] = distance;
	adjList[node1].push_back({ node2, currEdgeId });

}

void Graph::addUnDirectedEdge(string from, string to, string edgeName, int distance)
{
	if (!NodeExists(from) || !NodeExists(to))
		throw GraphException("Node doesn't exist");
	else if (EdgeExists(edgeName))
		throw GraphException("Edge already exists");
	else if (distance <= 0)
		throw GraphException("Invalid distance");

	addDirectedEdge(from, to, edgeName,distance);

	int node1 = nodeMapper[to];
	int node2 = nodeMapper[from];
	int currEdgeId = edgeMapper[edgeName];
	adjList[node1].push_back({ node2, currEdgeId });

}

void Graph::removeNode(string node)
{
	if(!NodeExists(node))
		throw GraphException("Node doesn't exist");

	int targetNode = nodeMapper[node];
	adjList[targetNode].clear();
	freeNodeMappingIds.push_back(targetNode);

	for (int i = 0; i < adjList.size(); i++)
	{
		for (int j = 0; j < adjList[i].size(); j++)
		{
			int currNode = adjList[i][j].first;

			if(currNode == targetNode)
				adjList[i].erase(adjList[i].begin() + j);
		}
	}

	nodeMapper.erase(node);
}

void Graph::removeEdge(string node1, string node2, string edgeName)
{
	
	if (!NodeExists(node1) || !NodeExists(node2))
		throw GraphException("Node doesn't exist");
	else if (!EdgeExists(edgeName))
		throw GraphException("Edge doesn't exist");

	int counter = 0;
	int targetNode1 = nodeMapper[node1], targetNode2 = nodeMapper[node2];
	int edgeId = edgeMapper[edgeName];

	for (int i = 0; i < adjList.size(); i++)
	{
		for (int j = 0; j < adjList[i].size(); j++)
		{
			int currNode = adjList[i][j].first;
			int currEdge = adjList[i][j].second;

			if (( (i == targetNode1 && currNode == targetNode2) || (i == targetNode2 && currNode == targetNode1) ) && currEdge == edgeId)
			{
				adjList[i].erase(adjList[i].begin() + j);
				counter++;
			}

			if (counter == 2) // if cnt == 2 then i removed the edge so no need to continue looping
			{
				edgeMappingResults.push_back(edgeId);
				edgeMapper.erase(edgeName);
				return;

			}
		}

	}

	if (!counter)
	{
		throw GraphException("Edge doesn't exist");
	}
	else
	{
		edgeMapper.erase(edgeName);
		edgeMappingResults.push_back(edgeId);

	}
}

bool Graph::NodeExists(string node)
{
	return nodeMapper.find(node) != nodeMapper.end();
}

bool Graph::EdgeExists(string edge)
{
	return edgeMapper.find(edge) != edgeMapper.end();
}

int Graph::getDistance(int edgeID)
{
	return edgeDistance[edgeID];
}

//void Graph::test(int n)
//{
//	vis[n] = 1;
//	cout << n << " ";
//	for (auto i : adjList[n])
//	{
//		if (!vis[i.first])
//			test(i.first);
//	}
//}

Graph::~Graph()
{
	sizeOfList = 0;
	maxNodeMappingId = 0;
	maxEdgeMappingId = 0;
	adjList.clear();
	freeNodeMappingIds.clear();
    nodeMapper.clear();
	edgeMappingResults.clear();
	edgeMapper.clear();
	edgeDistance.clear();
}

