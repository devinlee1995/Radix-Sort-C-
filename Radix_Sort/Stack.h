//
//  Stack.h
//  Radix_Sort
//
//  Created by Devin Lee on 10/14/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#ifndef Radix_Sort_Stack_h
#define Radix_Sort_Stack_h

#include <iostream>
using namespace std;

class node;

class Stack {

public:
    Stack (); 
    void push(node* n);
    node* pop();
    bool isEmpty();
    void printStack(ostream &out);
    
private:
    node* Top;
    
};


#endif
