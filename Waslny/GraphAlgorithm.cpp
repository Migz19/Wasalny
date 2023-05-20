#include "GraphAlgorithm.h"


GraphAlgorithm::GraphAlgorithm()
{
    clr();
}

void GraphAlgorithm::dijkstra(int source, int end, vector<vector<pair<int, int>>>& adj, EdgeMapper& edgeMappper)
{                    // distance , node
    priority_queue<pair<long long, int>> pq;
    pq.push({ 0,source });
    previousNode[source].second = 0;                   //first node 

    while (!pq.empty())
    {
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (node == end)
            break;
        if (cost > previousNode[node].second)
            continue;
        for (int i = 0; i < adj[node].size(); i++)
        {
            long long newCost = cost + edgeMappper.getDistance(adj[node][i].second);  // pass the id to get the distance 
            if ( newCost < previousNode[adj[node][i].first].second)
            {
                previousNode[adj[node][i].first].first = node;
                previousNode[adj[node][i].first].second = newCost;
                pq.push({ -newCost, adj[node][i].first });
            }
        }

    }

}

stack<pair<string, int>> GraphAlgorithm::getPath(int start, int end, vector<vector<pair<int, int>>>& adj, EdgeMapper& edgeMappper, NodeMapper& nodeMapper)
{
    dijkstra(start, end, adj, edgeMappper); // run GraphAlgorithm's algorithm
    stack<pair<string, int>> path;
    for (int node = end; node != -1; node = previousNode[node].first) {
        path.push({ nodeMapper.getName(node) , previousNode[node].second }); // trace back the path from end to start
    }

    return path;
}



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
            result |= dfs(adjList[start][i].first, target, adjList);
        }
    }
    return result;
}

void GraphAlgorithm::bfs(vector<int> sources, vector<vector<pair<int, int>>>& adjList, vector<pair<pair<int, int>, int>>& v)
{
    //multi source bfs  ===> faster 

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
    previousNode = vector<pair<int, int>>(N, { -1 , inf });
    visited = vector<bool>(N, 0);
}