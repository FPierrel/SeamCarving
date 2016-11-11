#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
public:
    Pixel();
    Pixel(int r, int g, int b);
    void setColor(int r, int g, int b);
    int interest(Pixel left, Pixel right);

    int r;
    int g;
    int b;
};

#endif // PIXEL_H
