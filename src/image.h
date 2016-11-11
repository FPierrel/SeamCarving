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
    void resize(int new_width, int new_height);

    QImage toQImage();

    Graph *graph = NULL;
    Pixel **img = NULL; // img[y][x] from top-left corner
    int height, width;
    int maxVal;
    int **itr = NULL;

    //zone to exclude
    int x1Zone, x2Zone, y1Zone, y2Zone;

private:
    void delete_img();
    void transpose();
    void interest();
    void tograph();
    void update(vector<int> list);
};

#endif // IMAGE_H
