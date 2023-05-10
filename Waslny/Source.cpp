
#include <iostream>
#include "Graph.h"

using namespace std;
int main()
{
    Graph* g = Graph::getInstance();
    g->addNode("cairo");
    g->addNode("alex");
    g->addNode("luxor");
    g->addNode("aswan");
    g->addNode("portsaid");
    g->addNode("sina");
    g->addNode("ff");
    g->addNode("sharqia");


    g->addUnDirectedEdge("cairo", "sina", "e1", 5);
    g->addUnDirectedEdge("alex", "luxor", "e2", 5);
    g->addUnDirectedEdge("luxor", "aswan", "e3", 5);
    g->addUnDirectedEdge("aswan", "cairo", "e4", 10);
    g->addUnDirectedEdge("cairo", "portsaid", "e5", 9);
    g->addUnDirectedEdge("sina", "alex", "e6", 5);
    g->addUnDirectedEdge("ff", "sharqia", "e7", 5);

    vector<string>v = g->display();
    for (auto i : v)
    {
        cout << i << " \n";
    }

}
