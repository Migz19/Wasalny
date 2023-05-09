#include <vector>
#include <utility>
#include <iostream>
#include <stack>
#include "Graph.h"
using namespace std;
class Dfs{
private:
    Graph * graph;
    int listSize;
    stack<int> isVisitedSt;
vector< vector<pair<int, int>> > adj_list;
public:
    Dfs();
    bool isPathExisted(int start,int end);
    
};