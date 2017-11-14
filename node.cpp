#include "node.h"
using namespace std;

node::node(node *a, node *b){
  l = a;
  r = b;
  f = l->f + r->f;
}

node::node(char a, int b){
  c = a;
  f = b;
  l = NULL;
  r = NULL;
}

node::~node(){}

bool node::operator<(node source){
  return f < source.f;
}

bool node::operator>(node source){
  return f > source.f;
}

bool node::isBlank(){       // If it had a character, its children would be NULL
  return l!=NULL;
}


