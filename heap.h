// Muhtasim Ahmed, ma2qf
// 11/17/17
// heap.h

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
    void buildTree();
    void print(string a, node *n);
    void print();
    void printCode(int i, char c, string a, node *n);
    int printCode(char c);

private:
    vector<node *> h;
    unsigned int heap_size;
    int counter;

    void percolateUp(int hole);
    void percolateDown(int hole);
    
    void set(int i);
};

#endif
