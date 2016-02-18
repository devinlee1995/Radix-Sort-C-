//
//  Stack.cpp
//  Radix_Sort
//
//  Created by Devin Lee on 10/14/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#include "Stack.h"
#include "node.h"
#include<fstream>

Stack::Stack() {
    Top = NULL;
}

void Stack::push(node* n) {
    n->next = Top;
    Top = n;
    
}


node* Stack::pop() {
    if (!isEmpty()) {
        node* temp = Top;
        node* value = temp;
        Top = Top->next;
        return value;
    }
    else {
        exit(0);
    }
}


bool Stack:: isEmpty() {
    if (Top == NULL) {
        return true;
    }
    return false;
}


void Stack:: printStack(ostream &output_file) {
    node* spot = Top;

    output_file << "STACK: " << endl; 
    output_file << "TOP --> (" << spot->data << " , " << spot->next->data << ")";
    
    while (spot!= NULL) {
        spot = spot->next;
        if (spot->next == NULL) {
            output_file << "--> (" << spot->data << ", NULL)";
            break;
        }
        else {
            output_file << "--> (" << spot->data << " , " << spot->next->data << ")";
        }
    }
    output_file << endl << endl << endl;
    
}