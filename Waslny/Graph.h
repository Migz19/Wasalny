#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include <unordered_map>
#include <string>
#include "GraphException.h"

using namespace std;

class Graph
{
private:

	int sizeOfList;
	vector< vector<pair<int, int>> > adjList;
	
	vector<int> freeNodeMappingIds;
	int maxNodeMappingId;
	unordered_map<string, int> nodeMapper;   // NodeString -> NodeId

	vector<int> edgeMappingResults;
	int maxEdgeMappingId;
	unordered_map<string, int> edgeMapper; // EdgeString -> EdgeId
	unordered_map<int, int> edgeDistance;  // EdgeId -> EdgeDis

	bool NodeExists(string node);
	bool EdgeExists(string edge);

	//bool vis[500]; 
public:

    Graph();
	void addNode(string node); 

	void addUnDirectedEdge(string from, string to, string edgeName, int distance); 
	void addDirectedEdge(string from, string to, string edgeName, int distance); 

	void removeNode(string node);
	void removeEdge(string node1, string node2, string edgeName); 
	int getDistance(int edgeId);
	//void test(int n);
	~Graph();

	
};

