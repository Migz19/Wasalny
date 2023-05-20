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

void GraphAlgorithm::bfs(int source, vector<vector<pair<int, int>>>& adjList, vector<pair<pair<int, int>, int>>& v)
{

    queue<int> q;
    
    q.push(source);

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

void GraphAlgorithm::dfs(int source, vector<vector<pair<int, int>>>& adjList, vector<pair<pair<int, int>, int>>& v)
{

    stack<int> s;
    
    s.push(source);

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



vector<pair<pair<int, int>, int>> GraphAlgorithm::getConnections(vector<vector<pair<int, int>>>& adjList, int AlgorithmUsed)
{
    vector<int> isolated;
    vector<pair<pair<int, int>, int>> res;
    
    for (int node = 1; node < adjList.size(); node++) // adj size
    {
        if (!adjList[node].empty())
        {
            for (pair<int, int> p : adjList[node])
            {
                int edge = p.second;
                if (!visited[edge])
                {
                    if (AlgorithmUsed == 0)  // useDfs
                        dfs(node, adjList, res);
                    else                     // useBfs
                        bfs(node, adjList, res);
                }
            }
        }
        else if (adjList[node].empty())
        {
            isolated.push_back(node);
        }
    }


    clr();//
    
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