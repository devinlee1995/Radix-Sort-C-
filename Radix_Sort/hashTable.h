//
//  hashTable.h
//  Radix_Sort
//
//  Created by Devin Lee on 10/15/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#ifndef Radix_Sort_hashTable_h
#define Radix_Sort_hashTable_h

#include <iostream>
using namespace std;
class node;
class Queue;
class Stack;

class hashTable {
    friend class RadixSort; 
public:
    
    hashTable ();
    void printTable(ostream &out);
    int size = 10;
    
private:
    typedef Queue* Hash_Pointer;
    Hash_Pointer d;
    
    
};



#endif
