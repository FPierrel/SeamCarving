#include "seamcarving.h"
#include "heap.h"

SeamCarving::SeamCarving()
{

}

vector<int> SeamCarving::CCMDAG(Graph *g, int s, int t)
{
    int *pred = new int[g->V + 1];
    vector<int> list;
    Heap heap(g->V);
    heap.decreaseKey(s,0);

    // Calculation of shortest path in DAG from source
    for (int i = 0 ; i < g->V - 1 ; i++) // topological ordering
    {
        for (Edge e : g->adjacent(i))
        {
            if (heap.priority(e.to) > heap.priority(e.from) + e.cost)
            {
                heap.decreaseKey(e.to, heap.priority(e.from) + e.cost);
                pred[e.to] = e.from;
            }
        }
    }

    int pos = t-1;
    list.push_back(pred[pos]);
    pos = pred[pos];

    while (pos != 0)
    {
        list.push_back(pred[pos]);
        pos = pred[pos];
    }

    delete[] pred;

    return list;
}

SeamCarving::~SeamCarving()
{

}

