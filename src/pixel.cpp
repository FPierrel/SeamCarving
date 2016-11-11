#include <cmath>
#include "pixel.h"

Pixel::Pixel()
{

}

Pixel::Pixel(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}
void Pixel::setColor(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

int Pixel::interest(Pixel *left, Pixel *right)
{
    int itr;

    if (!left)
        itr = round((abs(r - ((r + right->r)/2)) + abs(g - ((g + right->g)/2)) + abs(b - ((b + right->b)/2))))/3;
    else if (!right)
        itr = round((abs(r - ((r + left->r)/2)) + abs(g - ((g + left->g)/2)) + abs(b - ((b + left->b)/2))))/3;
    else
        itr = round((abs(r - ((left->r + right->r)/2)) + abs(g - ((left->g + right->g)/2)) + abs(left->b - ((b + right->b)/2))))/3;

    return itr;
}
