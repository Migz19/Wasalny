#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include <unordered_map>
#include <string>
#include "GraphException.h"
#include "NodeMapper.h"
#include "EdgeMapper.h"

using namespace std;

class Graph
{
private:

	int sizeOfList;
	vector< vector<pair<int, int>> > adjList;

	NodeMapper nodeMapper;
	EdgeMapper edgeMapper;

	Graph();

	void addDirectedEdgeHelper(string from, string to, string edgeName, int distance);
	pair<bool, string> canAddEdge(string from, string to, string edgeName, int distance);

	bool nodeExists(string node);
	bool edgeExists(string edge);

	//bool vis[500];

public:

	Graph(const Graph& graph) = delete;
	static Graph* getInstance();

	int getMaxNode();

	void addNode(string node);
	void removeNode(string node);

	void addUnDirectedEdge(string from, string to, string edgeName, int distance);
	void addDirectedEdge(string from, string to, string edgeName, int distance);
	void removeEdge(string node1, string node2, string edgeName);

	int getDistance(int edgeId);

	//void test(int n);
	~Graph();


};

