#ifndef SEAMCARVING_H
#define SEAMCARVING_H

#include <vector>

#include "image.h"
#include "graph.h"

class SeamCarving
{
public:
    SeamCarving();
    ~SeamCarving();

    static vector<int> CCMDAG(Graph* g, int s, int t);
};

#endif // SEAMCARVING_H
