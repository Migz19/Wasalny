#pragma once

#include<vector>
using namespace std;

class DisjointSet
{

    vector<int> rank, parent;

public:

    DisjointSet(int n);
    int findSet(int node);
    void link(int node1, int node2);
    bool unionSets(int node1, int node2);

};

