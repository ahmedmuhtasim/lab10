#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "node.h"
using namespace std;

class heap {
public:
    heap();
    heap(vector<node *> vec);
    ~heap();

    void insert(node *x);
    node *findMin();
    node *deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    string toString(node *n);
    void buildTree();
    void print();

private:
    vector<node *> h;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif