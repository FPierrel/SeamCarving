#ifndef IMAGE_H
#define IMAGE_H

#include "graph.h"
#include "pixel.h"

#include <string>
#include <QImage>

using namespace std;

class Image
{
public:
    Image(QString filename);
    ~Image();

    void setZone(int x1Zone,int x2Zone,int y1Zone,int y2Zone);
    Image resize(int width, int height);
    operator QImage(); // cast

    Graph graph;
    Pixel **img; // img[y][x] from top-left corner
    int height, width;
    int maxVal;
    int **itr;

    //zone to exclude
    int x1Zone, x2Zone, y1Zone, y2Zone;

private:
    void transpose();
    void interest();
    void tograph();
};

#endif // IMAGE_H
