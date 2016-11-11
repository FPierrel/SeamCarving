#ifndef GRAPH_H
#define GRAPH_H

#include <cstddef>
#include <vector>
#include "edge.h"

using namespace std;

class Graph
{
public:
    Graph(int N);
    ~Graph();

    void addEdge(Edge e);
    vector<Edge> adjacent(int v);
    vector<Edge> next(int v);
    vector<Edge> edges();

    vector<Edge> *adj = NULL;
    int V;
private:
    int E;
};

#endif // GRAPH_H
