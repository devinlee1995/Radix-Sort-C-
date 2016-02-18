//
//  node.h
//  Radix_Sort
//
//  Created by Devin Lee on 10/14/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#ifndef Radix_Sort_node_h
#define Radix_Sort_node_h

#include <iostream>
using namespace std;

class node {
    friend class Stack;
    friend class Queue;
    friend class hashTable;
    friend class RadixSort; 
    
public:
    node (string x);
    node ();
    ~node();
    
private:
    string data;
    node * next;
};



#endif
