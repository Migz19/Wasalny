#include "GraphAlgorithm.h"


GraphAlgorithm::GraphAlgorithm()
{
    clr();
}

void GraphAlgorithm::dijkstra(int n, int end, vector<vector<pair<int, int>>>& adj, EdgeMapper& edgeMappper)
{                    // distance        node
    priority_queue<pair<long long, int>> pq;
    pq.push({ 0,n });
    dist[n] = 0;
    while (!pq.empty())
    {
        int node = pq.top().second;
        int cost = -edgeMappper.getDistance(pq.top().first);
        pq.pop();
        if (node == end)
            break;
        if (cost > dist[node])
            continue;
        for (int i = 0; i < adj[node].size(); i++)
        {
            long long newCost = cost + edgeMappper.getDistance(adj[node][i].second);
            if (dist[adj[node][i].first] > newCost)
            {
                dist[adj[node][i].first] = newCost;
                pr[adj[node][i].first].first = node;
                pr[adj[node][i].first].second = newCost;
                pq.push({ -newCost, adj[node][i].first });
            }
        }

    }

}

stack<pair<string, int>> GraphAlgorithm::getPath(int start, int end, vector<vector<pair<int, int>>>& adj, EdgeMapper& edgeMappper, NodeMapper& nodeMapper)
{
    dijkstra(start, end, adj, edgeMappper); // run GraphAlgorithm's algorithm
    stack<pair<string, int>> path;
    for (int node = end; node != -1; node = pr[node].first) {
        path.push({ nodeMapper.getName(node) , pr[node].second }); // trace back the path from end to start
    }

    return path;
}

//vector<pair<pair<int, int>, int>> GraphAlgorithm::bfs(int start)
//{
//    
//}

bool GraphAlgorithm::dfs(int start, int target, vector<vector<pair<int, int>>>& adjList)
{
    if (start == target)
    {
        return true;
    }

    visited[start] = true;
    bool result = false;
    for (int i = 0; i < adjList[start].size(); i++)
    {
        if (!visited[adjList[start][i].first])
        {
            result = dfs(adjList[start][i].first, target, adjList);
        }
    }
    return result;
}

void GraphAlgorithm::bfs(vector<int> sources, vector<vector<pair<int, int>>>& adjList, vector<pair<pair<int, int>, int>>& v)
{

    queue<int> q;
    for (int i : sources)
        q.push(i);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (pair<int, int> p : adjList[node])
        {
            int child = p.first;
            int edge = p.second;

            if (!visited[edge])
            {
                q.push(child);
                v.push_back({ {node,child} , edge });
                visited[edge] = 1;
            }
        }
    }
}

void GraphAlgorithm::dfs(vector<int> sources, vector<vector<pair<int, int>>>& adjList, vector<pair<pair<int, int>, int>>& v)
{

    stack<int> s;
    for (int i : sources)
        s.push(i);

    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        for (pair<int, int> p : adjList[node])
        {
            int child = p.first;
            int edge = p.second;

            if (!visited[edge])
            {
                s.push(child);
                v.push_back({ {node,child} , edge });
                visited[edge] = 1;
            }
        }
    }
}

void GraphAlgorithm::dfs(int node, vector<vector<pair<int, int>>>& adjList)
{
    visited[node] = true;

    for (int i = 0; i < adjList[node].size(); i++)
    {
        if (!visited[adjList[node][i].first])
        {
            dfs(adjList[node][i].first, adjList);
        }
    }
}

vector<pair<pair<int, int>, int>> GraphAlgorithm::getConnections(vector<vector<pair<int, int>>>& adjList, int AlgorithmUsed)
{
    vector<int> sources, isolated;

    for (int i = 1; i < adjList.size(); i++) /// adj size
    {
        if (!visited[i] && !adjList[i].empty())
        {
            sources.push_back(i);
            dfs(i, adjList);
        }
        else if (adjList[i].empty())
        {
            isolated.push_back(i);
        }
    }

    clr();
    vector<pair<pair<int, int>, int>> res;

    if (AlgorithmUsed == 0)  // useDfs
        dfs(sources, adjList, res);
    else // useBfs
        bfs(sources, adjList, res);

    for (int i : isolated)
    {
        res.push_back({ {i,-1}, -1 });
    }
    return res;
}

void GraphAlgorithm::clr()
{
    dist = vector<long long>(N, inf);
    pr = vector<pair<int, int>>(N, { -1 , 0 });
    visited = vector<bool>(N, 0);
}
