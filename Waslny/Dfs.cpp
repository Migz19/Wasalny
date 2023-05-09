#include "Dfs.h"

bool Dfs::isPathExisted(int start,int end){
    isVisitedSt.push(start);
    int iter =0;
    unordered_map<int ,bool > visitedMap;
    visitedMap[0]=true;
    
        // point to start adj_list[start]
        
    while (!isVisitedSt.empty())
    {
        int temp =isVisitedSt.top();
        isVisitedSt.pop();
        for (pair <int,int> neighbor:adj_list[temp]) //loop on adjacency list till reach temp node
        {
            if (!visitedMap[neighbor.first])
            {
                visitedMap[neighbor.first]=true;    
                isVisitedSt.push(neighbor.first);
            }
            if(neighbor.first==end)
                return true;
        }
        
    }
    return false;
    
}
Dfs::Dfs()
{
    graph=Graph::getInstance();
    listSize=graph->getMaxNode();
    adj_list=graph->getList();
}

