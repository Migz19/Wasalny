#pragma once
#include<queue>
#include<vector>
#include<string>
#include <deque>
#include"DisjointSet.h"
#include "EdgeMapper.h"
#include "NodeMapper.h"

using namespace std;

enum { useKruskal, usePrim };

struct edge
{
    int node1, node2, distance, edgeId;

    edge(int node1, int node2, int distance, int edgeId) : node1(node1), node2(node2), distance(distance), edgeId(edgeId) {}

    bool operator < (const edge& e) const
    {
        return distance > e.distance;
    }
};

class MstAlgorithm
{
private:
    int maxNodeID, nodesCnt;

    vector<edge> edgeListKruskal;
    vector<vector<edge>> edgeListPrim;

    vector<vector<int>> tempAdjList;
    vector<bool> tempAdjVisited;

    int totalDistance;
    deque<edge> answer;

    void dfs(int node);
public:

    MstAlgorithm(int adjListSize);

    void kruskal();
    void prim(edge source, int otherSourcesCnt);
    vector<pair<pair<int, int>, int>> getPath(vector< vector<pair<int, int>> > adjList, vector< pair<bool, bool> >& edgeDirections, EdgeMapper& edgeMapper, int algorithmUsed);

    void clr();
    ~MstAlgorithm();


};

