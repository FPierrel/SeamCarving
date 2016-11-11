#include "image.h"

Image::Image(QString filename)
{
    QImage _img = QImage(filename);
    uchar *bits = _img.convertToFormat(QImage::Format_RGB888).bits();

    height = _img.height();
    width = _img.width();

    // img and itr allocation
    img = new Pixel*[height];
    itr = new int*[height];
    for (int i = 0 ; i < height ; i++)
    {
        img[i] = new Pixel[width];
        itr[i] = new int[width];
    }

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
    for (int i = 0 ; i < height ; i++)
        for (int j = 0 ; j < width ; j++)
        {
            if (j == 0) //left
                itr[i][j] = img[i][j].interest(NULL, &img[i][j+1]);
            else if (j == width-1)
                itr[i][j] = img[i][j].interest(&img[i][j-1], NULL);
            else
                itr[i][j] = img[i][j].interest(&img[i][j-1], &img[i][j+1]);
        }
}

void Image::tograph()
{

}

Image::~Image()
{
    for (int i = 0 ; i < height ; i++)
    {
        delete[] img[i];
        delete[] itr[i];
    }

    delete[] img;
    delete[] itr;
}
