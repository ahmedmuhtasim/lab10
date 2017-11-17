// Muhtasim Ahmed, ma2qf
// 11/17/17
// heap.cpp

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
  while (heap_size != 1){
    node *a = deleteMin();
    node *b = deleteMin();
    insert(new node(a, b));
  }
}

void heap::print(string a, node *n){
  if(!(n->isBlank())){
    cout << n->c << " " << a << endl;
    return;
  }

  string retL = a, retR = a;
  retL += "0";
  retR += "1";

  print(retL, n->l);
  print(retR, n->r);

}

void heap::print() {
     buildTree();          // just for safety
     print("", h[1]);
}

void heap::printCode(int i, char c, string a, node *n){
  if(!(n->isBlank())){
    if (n->c==c){
      cout << a << " ";
      set(i);
    }
    return;
  }
  

  string retL = a, retR = a;
  retL += "0";
  retR += "1";

  printCode(i+1, c, retL, n->l);
  printCode(i+1, c, retR, n->r);

}

void heap::set(int i){
  counter = i;
}

int heap::printCode(char c) {
     buildTree();          // just for safety
     printCode(0, c, "", h[1]);
     return counter;
}
