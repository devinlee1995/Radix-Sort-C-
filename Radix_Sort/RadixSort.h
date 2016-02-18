//
//  RadixSort.h
//  Radix_Sort
//
//  Created by Devin Lee on 10/15/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#ifndef Radix_Sort_RadixSort_h
#define Radix_Sort_RadixSort_h

#include <iostream>
#include <fstream>
using namespace std;

class hashTable;
class Stack;
class node;

class RadixSort {

public:
    RadixSort();//ask where it should be
    int hashFunction(string digit);
    string currentDigit(string value);
    void totalDigit(string max_number);
    void add_from_stack (Stack stack1, ostream& outputfile);
    void sort_rest_of_table (ostream& outputfile); 
    
private:
    int currentTable; //index of currentTable in hashtable array
    int currentDigit_value; //value of which digit is wanted
    int previousTable;
    int total_number_of_Digit; //determines the number of digits in the largest value
    int index; //index value determined from what the value of the right digit is
    
    typedef hashTable* Hash_TPointer;
    Hash_TPointer array_hash;

};

#endif
