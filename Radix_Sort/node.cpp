//
//  node.cpp
//  Radix_Sort
//
//  Created by Devin Lee on 10/14/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#include "node.h"
#include <iostream>
#include <fstream>
#include <string> 

node::node(string x) {
    data = x;
    next = NULL;
}

node::node() {
    next = NULL;
}

node::~node() {
    delete next;
}