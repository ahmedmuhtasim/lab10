// Muhtasim Ahmed, ma2qf
// huffmanenc.cpp
// 11/12/17
// Resources used: fileio.cpp, binaryheap.h, binaryheap.cpp

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include "heap.h"
#include "node.h"
using namespace std;


class Huff{                 // Data structure to contain frequencies and chars
public:
  vector <char> c;
  vector <int> f;

  int indexof(char i){
  for (int x = 0; x < c.size(); x++)
    if (c.at(x)==i)
      return x;
  return -1;
  }

  void add(char i){
    int x = indexof(i);
    if (x==-1){
      c.push_back(i);
      f.push_back(1);
    }
    else
      f.at(x)++;
  }
};

int main (int argc, char **argv) {
    
    if ( argc != 2 ) {
        cout << "Only filename!" << endl;
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");

    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }

    Huff huff;
    char g;
    while ( (g = fgetc(fp)) != EOF )
      huff.add(g);
    
    rewind(fp); 
    fclose(fp);

    heap h;

    // insertion and automatic sorting process
    for (int i = 0; i < huff.c.size(); i++){
      h.insert(new node(huff.c.at(i), huff.f.at(i)));
         cout << huff.c.at(i) << " : " << huff.f.at(i) << endl;
    }

        h.print();

    
    cout << "----------------------------------------" << endl;

}
