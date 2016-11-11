#ifndef HEAP_H
#define HEAP_H


class Heap
{
public:
    Heap(int N);
    ~Heap();

    int priority(int x);
    bool isEmpty();
    int getSize();
    void decreaseKey(int x, int p);
    int pop();

    int *cor;
    int *item;
    int *heap;
    int size;
};

#endif // HEAP_H
