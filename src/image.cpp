#include "image.h"

Image::Image(QString filename)
{
    QImage _img = QImage(filename);
    uchar *bits = _img.convertToFormat(QImage::Format_RGB888).bits();

    height = _img.height();
    width = _img.width();

    img = new Pixel* [height];
    for (int i = 0 ; i < height ; i++)
        img[i] = new Pixel[width];

    for (int i = 0 ; i < height * width; i++ )
    {
        img[i]->r = (int) bits[i*3];
        img[i]->g = (int) bits[i*3 + 1];
        img[i]->r = (int) bits[i*3 + 2];
    }

    interest();
    tograph();
}

void Image::interest()
{
}

void Image::tograph()
{

}
