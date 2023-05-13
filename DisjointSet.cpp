#include "DisjointSet.h"

DisjointSet::DisjointSet(int n)
{
    int sz = n + 1;
    rank.resize(sz);
    parent.resize(sz);

    for (int i = 1; i <= n; i++)
    {
        rank[i] = 1;
        parent[i] = i;
    }
}

int DisjointSet::findSet(int node)
{
    if (node == parent[node])
        return node;

    return parent[node] = findSet(parent[node]); // path compression together with finding parent
}

void DisjointSet::link(int node1, int node2)
{
    if (rank[node1] > rank[node2])
        swap(node1, node2);

    parent[node1] = node2;

    if (rank[node1] == rank[node2])
        rank[node2]++;
}

bool DisjointSet::unionSets(int node1, int node2)
{
    node1 = findSet(node1), node2 = findSet(node2);

    if (node1 != node2)
        link(node1, node2);

    return node1 != node2;
}
