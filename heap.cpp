#include <iostream>
#include "heap.h"
using namespace std;

heap::heap() : heap_size(0) {
    h.push_back(NULL);
}

// consider removing.. don't need this functionality
/*
heap::heap(vector<node *> vec) : heap_size(vec.size()) {
    h = vec;
    h.push_back(h[0]);
    h[0] = 0;
    for ( int i = heap_size/2; i > 0; i-- )
        percolateDown(i);
}  
*/
heap::~heap() {
}

void heap::insert(node *x) {
    h.push_back(x);
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    node *x = h[hole];

    for ( ; (hole > 1) && (*x < *h[hole/2]); hole /= 2 )
        h[hole] = h[hole/2];
    
    h[hole] = x;
}

node *heap::deleteMin() {
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";

    node *ret = h[1];
    h[1] = h[heap_size--];
    h.pop_back();
    percolateDown(1);
    return ret;
}

void heap::percolateDown(int hole) {
    node *x = h[hole];
    
    while ( hole*2 <= heap_size ) {
        int child = hole*2;
        
        if ( (child+1 <= heap_size) && (*h[child+1] < *h[child]) )
            child++;
       
        if ( *x > *h[child] ) {
            h[hole] = h[child]; 
            hole = child;             
        } else
            break;
    }   
    h[hole] = x;
}

node *heap::findMin() {
    if ( heap_size == 0 )
        throw "findMin() called on empty heap";
    return h[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::buildTree() {
  while (heap_size != 2){
    node *a = deleteMin();
    node *b = deleteMin();
    insert(new node(a, b));
  }
}

string heap::toString(node *n){
  if (!(n->isBlank())){
    string a = " ";
    a += n->c;
    return a + "\n";
  }

  return "0" + toString(n->l) + "1" + toString(n->r);
}

void heap::print() {    
  buildTree();          // just for safety
  cout << toString(h[1]) << endl;
}
