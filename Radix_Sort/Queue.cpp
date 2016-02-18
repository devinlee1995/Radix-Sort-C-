//
//  Queue.cpp
//  Radix_Sort
//
//  Created by Devin Lee on 10/15/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#include "Queue.h"
#include "node.h"

Queue::Queue () {
    dummy = new node("dummy");
    head = dummy;
    tail = dummy;
}


void Queue::addTail(string x) {
    node* added = new node(x);
    if (isEmpty()) {
        head = dummy;
        head->next = added;
        tail = added;
        tail->next = NULL;
    }
        tail->next = added;
        tail = tail->next;
}

string Queue::deleteHead() {
    if (!isEmpty()) {
        string return_data = head->next->data;
        head = head->next;
        if (head == tail) {
            head = head->next;
        }
        return return_data;
    }
    else {
        throw "no!";
    }
}


bool Queue::isEmpty() {
    return (head == NULL);

}
