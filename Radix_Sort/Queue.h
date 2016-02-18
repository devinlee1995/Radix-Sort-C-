//
//  Queue.h
//  Radix_Sort
//
//  Created by Devin Lee on 10/15/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#ifndef Radix_Sort_Queue_h
#define Radix_Sort_Queue_h

#include <iostream>
using namespace std;

class node;

class Queue {
    friend class hashTable;
    friend class RadixSort; 
    
public:
    
    Queue();
    void addTail(string x);
    string deleteHead();
    bool isEmpty();
    void makeEmpty(); 
    void printQueue();
    
private:
    node* head;
    node* tail;
    node* dummy;
    
    
};

#endif
