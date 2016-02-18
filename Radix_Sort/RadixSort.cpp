//
//  RadixSort.cpp
//  Radix_Sort
//
//  Created by Devin Lee on 10/15/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#include "RadixSort.h"
#include "hashTable.h"
#include "Stack.h"
#include "node.h"
#include "Queue.h"

RadixSort::RadixSort() {
    array_hash = new hashTable[2];
    for (int i = 0; i < 2; i++) {
        array_hash[i] = *new hashTable();
    }
    
 
}

int RadixSort::hashFunction(string digit) {
    index = stoi(digit);
    return index;
}

void RadixSort::totalDigit(string max_number) {
    total_number_of_Digit = max_number.size();
    
}

string RadixSort::currentDigit(string value) { //takes number in and returns right digit for current
    int number = value.length()-(currentDigit_value+1);
    if (number < 0) {
        return "0";
    }
    else {
        return value.substr((value.length())-(currentDigit_value+1), 1);

    }

}

void RadixSort::add_from_stack(Stack stack1, ostream& output_file) {
    
    currentDigit_value = 0;//which digit in the number
    currentTable = 0; //index of currentTable in array of hash tables
    
    
    output_file << "ADDTAIL QUEUE Process: " << endl;
    while (!stack1.isEmpty()) {//Step 3
        node* popped = stack1.pop();
        string digit = currentDigit(popped->data); //gets the specified digit needed
        hashFunction(digit); //gets index value
        
        
        array_hash[currentTable].d[index].addTail(popped->data); //adding popped node to tail of queue
    }
    
    output_file << endl << endl;
    
    array_hash[currentTable].printTable(output_file);
}

void RadixSort::sort_rest_of_table (ostream &output_file) {
    
    currentDigit_value++;
    currentTable = 1;
    previousTable = 0;
    int currentQueue = 0;
    
    while (currentDigit_value < total_number_of_Digit) {
        output_file << "Previous: " << endl;
        array_hash[previousTable].printTable(output_file);
        
        while (currentQueue < array_hash[previousTable].size) {
            while (!array_hash[previousTable].d[currentQueue].isEmpty() && array_hash[previousTable].d[currentQueue].head->next != NULL && array_hash[previousTable].d[currentQueue].head != array_hash[previousTable].d[currentQueue].head->next)  {
                node* deleted = new node(array_hash[previousTable].d[currentQueue].deleteHead());
                string current_digit = currentDigit(deleted->data);
                hashFunction(current_digit);
                array_hash[currentTable].d[index].addTail(deleted->data);//adding popped node to tail of queue
            }
            currentQueue++;
        }
        
        
        if (currentDigit_value+1 != total_number_of_Digit) {
            int temp = currentTable;
            currentTable = previousTable;
            previousTable = temp;
            currentQueue = 0;
            currentDigit_value++;
        }
        else {
            break;
        }
    }
    
    output_file << "Current: " << endl;
    array_hash[currentTable].printTable(output_file);

    
}





