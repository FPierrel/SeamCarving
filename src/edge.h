#ifndef EDGE_H
#define EDGE_H


class Edge
{
public:
    Edge(int from, int to, int cost);

    int from;
    int to;
    int cost;
};

#endif // EDGE_H
