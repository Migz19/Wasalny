#include "MstAlgorithm.h"

void MstAlgorithm::dfs(int node)
{
    tempAdjVisited[node] = 1;

    for (int child : tempAdjList[node])
    {
        if (!tempAdjVisited[child])
            dfs(child);
    }
}

MstAlgorithm::MstAlgorithm(int adjListSize)
{
    maxNodeID = adjListSize;
    totalDistance = 0;
    nodesCnt = 0;
    edgeListPrim.resize(maxNodeID);
    tempAdjList.resize(maxNodeID);
    tempAdjVisited.resize(maxNodeID);
}

void MstAlgorithm::kruskal()
{
    DisjointSet dSet(maxNodeID + 1);
    vector<bool> vis(maxNodeID, 0);

    priority_queue<edge> q;
    for (edge e : edgeListKruskal)
        q.push(e);

    while (!q.empty())
    {
        edge e = q.top();
        q.pop();

        if (dSet.unionSets(e.node1, e.node2))
        {
            if (!vis[e.node1])
                nodesCnt++, vis[e.node1] = 1;
            if (!vis[e.node2])
                nodesCnt++, vis[e.node2] = 1;

            totalDistance += e.distance;
            answer.push_back(e);
        }
    }

    if (nodesCnt - 1 != answer.size())
    {
        totalDistance = -1;
        answer.clear();
    }
}

void MstAlgorithm::prim(edge source, int otherSourcesCnt)
{
    vector<bool> vis(maxNodeID, 0);

    set<int> nodes;

    priority_queue<edge> qu;
    qu.push(source);

    while (!qu.empty())
    {
        edge e = qu.top();
        qu.pop();

        if (vis[e.node1])
            continue;

        vis[e.node1] = 1;
        nodes.insert(e.node1);
        nodes.insert(e.node2);


        if (!(e.node1 == source.node1 && e.node2 == source.node2 && e.distance == source.distance))
            totalDistance += e.distance, answer.push_back(e);

        for (edge child : edgeListPrim[e.node1])
        {
            int t = child.node1;
            if (!vis[child.node1])
                qu.push(child), nodesCnt++;
        }
    }
    //cout << nodesCnt << " " << answer.size() << endl;

    nodesCnt = nodes.size();
    if (nodesCnt - 1 != answer.size())
    {
        totalDistance = -1;
        answer.clear();
    }
}

vector<pair<pair<int, int>, int>> MstAlgorithm::getPath(vector<vector<pair<int, int>>> adjList, vector<pair<bool, bool>>& edgeDirections, EdgeMapper& edgeMapper, int algorithmUsed)
{
    vector<pair<pair<int, int>, int>> res;

    edge source(0, 0, 0, 0);
    bool foundSource = 0;

    for (int i = 1; i < adjList.size(); i++) ///adj.size
    {
        int node1 = i;
        for (pair<int, int> p : adjList[i])
        {
            int node2 = p.first;
            int edgeID = p.second;

            if (edgeDirections[edgeID].first == 1 && edgeDirections[edgeID].second == 1)
            {
                edge e(node1, node2, edgeMapper.getDistance(edgeID), edgeID);

                edgeListKruskal.push_back(e);

                edgeListPrim[node1].push_back(e);
                edgeListPrim[node2].push_back(e);

                if (!foundSource)
                {
                    foundSource = 1;
                    source = e;
                }
            }
        }
    }

    if (algorithmUsed == useKruskal)
    {
        kruskal();
    }
    else
    {
        int otherSourcesCnt = -1;

        for (int i = 1; i < maxNodeID; i++)
        {
            if (!tempAdjVisited[i] && !tempAdjList[i].empty())
            {
                otherSourcesCnt++;
                dfs(i);
            }
        }

        if (otherSourcesCnt > 1)
        {
            totalDistance = -1;
            answer.clear();
        }
        else
        {
            prim(source, otherSourcesCnt);
        }
    }

    if (answer.empty())
    {
        res.push_back({ {-1, -1}, -1 });
    }
    else
    {
        for (edge e : answer)
            res.push_back({ { e.node1, e.node2 }, e.edgeId });
    }

    return res;

}

void MstAlgorithm::clr()
{
    maxNodeID = 0;
    totalDistance = 0;
    nodesCnt = 0;
    edgeListKruskal.clear();
    answer.clear();

    for (vector<edge> v : edgeListPrim)
        v.clear();
}

MstAlgorithm::~MstAlgorithm()
{
    clr();
}
