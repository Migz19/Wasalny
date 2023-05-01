#include "Graph.h"

static Graph* instancePtr = NULL;

Graph::Graph()
{
	sizeOfList = 100;
	adjList.resize(sizeOfList);
}

Graph* Graph::getInstance()
{
	if (instancePtr == NULL)
		instancePtr = new Graph;

	return instancePtr;
}

void Graph::addNode(string node)
{
	if (nodeExists(node))
		throw GraphException("Node already exists");

	int id = nodeMapper.getId(node);

	if (id == adjList.size())
		adjList.resize(adjList.size() * 2);

}

int Graph::getMaxNode()
{
	return adjList.size();
}	

void Graph::removeNode(string node)
{
	if (!nodeExists(node))
		throw GraphException("Node doesn't exist");
		
		int targetNode = nodeMapper.getId(node);
		for (int i = 0; i < adjList[targetNode].size(); i++)
		{
			int connectingEdge = adjList[targetNode][i].second;
			if (edgeMapper.idExists(connectingEdge))
				edgeMapper.remove(connectingEdge);
		}

		adjList[targetNode].clear();
		
		for (int i = 0; i < adjList.size(); i++)
		{
			for (int j = 0; j < adjList[i].size(); j++)
			{
				int currNode = adjList[i][j].first;
				int connectingEdge = adjList[i][j].second;
				if (currNode == targetNode)
				{
					if (edgeMapper.idExists(connectingEdge))
						edgeMapper.remove(connectingEdge);
					adjList[i].erase(adjList[i].begin() + j);
				}
			}
		}
		
		nodeMapper.remove(targetNode);
}

void Graph::addUnDirectedEdge(string from, string to, string edgeName, int distance)
{
	pair<bool, string> canAdd = canAddEdge(from, to, edgeName, distance);

	if (!canAdd.first)
		throw GraphException(canAdd.second);

	addDirectedEdgeHelper(from, to, edgeName, distance);
	addDirectedEdgeHelper(to, from, edgeName, distance);

}

void Graph::addDirectedEdge(string from, string to, string edgeName, int distance)
{
	pair<bool, string> canAdd = canAddEdge(from, to, edgeName, distance);

	if (!canAdd.first)
		throw GraphException(canAdd.second);

	addDirectedEdgeHelper(from, to, edgeName, distance);
	
}

void Graph::removeEdge(string node1, string node2, string edgeName)
{
		
	if (!nodeExists(node1) || !nodeExists(node2))
		throw GraphException("Node doesn't exist");
	else if (!edgeExists(edgeName))
		throw GraphException("Edge doesn't exist");

	int counter = 0;
	int targetNode1 = nodeMapper.getId(node1), targetNode2 = nodeMapper.getId(node2);
	int edgeId = edgeMapper.getId(edgeName, -1);  // -1 doesn't affect anything (edge already exists)

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
				edgeMapper.remove(edgeId);
				return;

			}
		}

	}

	if (!counter) // if nodes and edge exist but the edge doesn't connect those two
		throw GraphException("Edge doesn't exist");
	else
		edgeMapper.remove(edgeId);
}

int Graph::getDistance(int edgeId)
{
	return edgeMapper.getDistance(edgeId);
}

void Graph::addDirectedEdgeHelper(string from, string to, string edgeName, int distance)
{
	int node1 = nodeMapper.getId(from);
	int node2 = nodeMapper.getId(to);

	int currEdgeId = edgeMapper.getId(edgeName, distance);
	adjList[node1].push_back({ node2, currEdgeId });
}

pair<bool, string> Graph::canAddEdge(string from, string to, string edgeName, int distance)
{
	bool flag = 1;
	string message = "No errors";

	if (!nodeExists(from) || !nodeExists(to))
	{
		flag = 0;
		message = "Node doesn't exist";
	}
	else if (edgeExists(edgeName))
	{
		flag = 0;
		message = "Edge already exists";
	}
	else if (distance <= 0)
	{
		flag = 0;
		message = "Invalid distance";

	}

	return { flag, message };
}

bool Graph::nodeExists(string node)
{
	return nodeMapper.nameExists(node);
}

bool Graph::edgeExists(string edge)
{
	return edgeMapper.nameExists(edge);
}

//void Graph::test(int n)
//{
//	vis[n] = 1;
//	cout << nodeMapper.getName(n) << " ";
//	for (auto i : adjList[n])
//	{
//		if (!vis[i.first])
//			test(i.first);
//	}
//}

Graph::~Graph()
{
	sizeOfList = 0;
	adjList.clear();
	if(instancePtr != nullptr)
		delete instancePtr;
}
