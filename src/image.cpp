#include "image.h"
#include "seamcarving.h"

Image::Image(QString filename)
{
    QImage _img = QImage(filename);
    _img.convertToFormat(QImage::Format_RGB888).bits();

    this->height = _img.height();
    this->width = _img.width();

    // img allocation
    img = new Pixel*[height];
    for (int i = 0 ; i < height ; i++)
        img[i] = new Pixel[width];

    for (int y = 0 ; y < height ; y++)
        for (int x = 0 ; x < width ; x++)
        {
            QRgb pix = _img.pixel(x,y);
            img[y][x].r = qRed(pix);
            img[y][x].g = qGreen(pix);
            img[y][x].b = qBlue(pix);
        }

    interest();
    tograph();
}

void Image::resize(int new_width, int new_height)
{
    int del_x = new_width - width;
    int del_y = new_height - height;

    if (del_x > 0)
        for (int i = 0; i < del_x ; i++)
            update(SeamCarving::CCMDAG(graph,0, graph->V));

    if (del_y > 0)
    {
        transpose();
        interest();
        tograph();

        for (int i = 0; i < del_y ; i++)
            update(SeamCarving::CCMDAG(graph, 0, graph->V));

        transpose();
    }
}

void Image::update(vector<int> list)
{
    Pixel** newImg = new Pixel*[height];
    for (int i = 0 ; i < height ; i++)
        newImg[i] = new Pixel[width-1];

    int index;
    int step = 0;
    for (int i = height-1 ; i >= 0; i--)
    {
        index = 0;
        while (index < (list[i]-1) - (step*width)) // before pix. to del
        {
            newImg[step][index] = img[step][index];
            index++;
        }
        index++;

        while(index < width) //fill the rest of the line
        {
            newImg[step][index-1] = img[step][index];
            index++;
        }
        step++;
    }

    for (int i = 0; i < height ; i++)
        delete[] img[i];
    delete[] img;

    img = newImg;
    width--;
    interest();
    tograph();
}

void Image::interest()
{
    if (itr)
    {
        for (int i = 0 ; i < height ; i++)
            delete[] itr[i];
        delete[] itr;
    }

    itr = new int*[height];

    for (int i = 0 ; i < height ; i++)
    {
        itr[i] = new int[width];
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
}

void Image::tograph()
{
    int V = (height*width*2) - (width*2) + 2;
    int count = 1;
    if (graph)
        delete graph;
    graph = new Graph(V);

    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            if ( i == 0) // first line
                graph->addEdge(Edge(0,count,0));
            else if (i == 1)
            {
                if (j==0) // left side
                {
                    graph->addEdge(Edge(count-width,count,itr[i-1][j])); // top pixel
                    graph->addEdge(Edge((count-width+1),count,itr[i-1][j+1])); // top right pixel
                }
                else if (j == (width-1)) // right side
                {
                    graph->addEdge(Edge(count-width-1,count,itr[i-1][j-1])); // top left pixel
                    graph->addEdge(Edge((count-width),count,itr[i-1][j])); // top pixel
                }
                else // middle
                {
                    graph->addEdge(Edge((count-width-1),count,itr[i-1][j-1])); // top left pixel
                    graph->addEdge(Edge((count-width),count,itr[i-1][j])); // top pixel
                    graph->addEdge(Edge((count-width+1),count,itr[i-1][j+1])); // top right pixel
                }

                if (i != (height-1))
                {
                    //on place la duplication de sommet
                    graph->addEdge(Edge(count,count+width,0));


                }
            }
            else
            {
                if (j==0) // left side
                {
                    graph->addEdge(Edge(count-width,count,itr[i-1][j])); // top pixel
                    graph->addEdge(Edge(count-width+1,count,itr[i-1][j+1])); // top right pixel
                }
                else if (j == (width-1)) // right side
                {
                    graph->addEdge(Edge(count-width-1,count,itr[i-1][j-1])); // top right pixel
                    graph->addEdge(Edge(count-width,count,itr[i-1][j])); // top pixel
                }
                else // middle
                {
                    graph->addEdge(Edge(count-width-1,count,itr[i-1][j-1])); // top left pixel
                    graph->addEdge(Edge(count-width,count,itr[i-1][j])); // top pixel
                    graph->addEdge(Edge(count-width+1,count,itr[i-1][j+1])); // top right pixel
                }

                if (i != (height-1))
                {
                    //Edge duplication
                    graph->addEdge(Edge(count,count+width,0));
                }
            }
            count++;
        }
        if ((i>=1) && (i < (height-1)))
            count = count + width ;
    }

    // last line
    for (int i = 1 ; i <= width ; i++)
        graph->addEdge(Edge(count-i,count,itr[(height-1)][width-i]));
}

void Image::transpose()
{
    if (height > 0) {
        Pixel** tmp = new Pixel*[width];
        for (int i = 0; i < width; i++)
            tmp[i] = new Pixel[height];

        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                tmp[j][i] = img[i][j];

        int tmpTaille = height ;
        height = width ;
        width = tmpTaille ;

        for (int i = 0 ; i < height ; i++)
            delete[] img[i];
        delete[] img;

        img = tmp ;
    }
}

Image::~Image()
{
    if (img)
    {
        for (int i = 0 ; i < height ; i++)
            delete[] img[i];
        delete img;
    }

    if (itr)
    {
        for (int i = 0 ; i < height ; i++)
            delete[] itr[i];
        delete[] itr;
    }

    if (graph)
        delete graph;
}

QImage Image::toQImage()
{
    QImage _img(width, height, QImage::Format_RGB888);
    for (int x = 0 ; x < width ; x++)
        for(int y = 0 ; y < height ; y++)
        {
            QRgb rgb = qRgb(img[y][x].r, img[y][x].g, img[y][x].b);
            _img.setPixel(x,y,rgb);
        }

    return _img;
}
