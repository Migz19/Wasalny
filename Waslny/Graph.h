#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
#include "GraphException.h"
#include "NodeMapper.h"
#include "EdgeMapper.h"
#include "GraphAlgorithm.h"
#include "MstAlgorithm.h"

using namespace std;

enum { useDfs, useBfs };

class Graph
{
private:

	friend class File;
	int sizeOfList;
	vector< vector<pair<int, int>> > adjList;
	vector< pair<bool, bool> > edgeDirections;

	NodeMapper nodeMapper;
	EdgeMapper edgeMapper;
	GraphAlgorithm graphAlgorithm;
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
	vector<string> display(int algorithmUsed);
	bool areNodesConnected(string start, string target);
	stack<pair<string, int>> getShortestPath(string start, string target);
	
	vector<string>getMST(int algorithmUsed);
	

	//void test(int n);
	~Graph();


};
