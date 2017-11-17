// Muhtasim Ahmed, ma2qf
// 11/17/17
// node.h

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class node {
public:
  node(node *a, node *b);
  node(char a, int b);
  ~node();
  bool operator<(node source);
  bool operator>(node source);
  bool isBlank();  

private:
    char c;
    int f;
    node *l, *r;   
    friend class heap;
    friend class node;
};

#endif
