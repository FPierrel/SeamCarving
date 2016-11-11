#include "graph.h"

Graph::Graph(int N)
{
    V = N;
    E = 0;

    adj = new vector<Edge>[N];
}

void Graph::addEdge(Edge e)
{
    adj[e.from].push_back(e);
    adj[e.to].push_back(e);
}

vector<Edge> Graph::adjacent(int v)
{
    return adj[v];
}

vector<Edge> Graph::next(int v)
{
    vector<Edge> list;

    for (Edge e : adj[v])
        if (e.to != v)
            list.push_back(e);

    return list;
}

vector<Edge> Graph::edges()
{
    vector<Edge> list;
    for (int v = 0 ; v < V ; v++)
        for (Edge e : adj[v])
            if (e.to != v)
                list.push_back(e);

    return list;
}

Graph::~Graph()
{
    delete[] adj;
}

