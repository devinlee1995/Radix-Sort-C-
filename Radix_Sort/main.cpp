//
//  main.cpp
//  Radix_Sort
//
//  Created by Devin Lee on 10/13/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#include <iostream>
#include<fstream>
#include"node.h"
#include"Stack.h"
#include "RadixSort.h"
#include "hashTable.h"
#include "Queue.h"
using namespace std;



int main(int argc,char * argv[]){
    
    try{
        
        if (argc < 2) {
            throw argc;
        }
        
        
        ifstream the_input_file; //input file
        string input_file_name = argv[1];
        the_input_file.open(input_file_name);
        
        ofstream the_output_file;
        string output_file_name = argv[2];//output file name
        the_output_file.open(output_file_name,std::ios_base::app);
       
        if (!the_input_file.is_open()) { //if input file did not open
            cout<< "Did not open!";
        }
        
        //Step 0: create a new stack
        Stack stack1;
        
        //Step 1: Read data from input and push into stack
        string num;
        string max;
        the_input_file >> max;
        node* data_in = new node(max);
        stack1.push(data_in);
        while (the_input_file >> num) { //reads numbers in file
            if (std::stoi(num) > std::stoi(max)) {
                max = num;
            }
            node* data_in = new node(num);
            stack1.push(data_in);
        }
        stack1.printStack(the_output_file);
        
    
        RadixSort radix;
        //Step 2: Determines digits in max number
        radix.totalDigit(max);
        
        //Step 3: Take nodes from stack and addTail to Queue of currentTable
        radix.add_from_stack(stack1, the_output_file);
        
        //Steps 4, 5, 6, 7, 8: Make currentTable into previousTable, delete nodes from previousTable and sort them by the next digit in currentTable and keep doing this until current_digit_value >= total_digit_value
        radix.sort_rest_of_table(the_output_file);

        
        the_input_file.close();
        the_output_file.close();
        
        
        

    }
    catch (int e) {
        std::cout << "Not enough arguments provided! Argument(s) used: ";
        for (int i = 0; i < argc; ++i)
            std::cout << "argv["<< i << "] : " << argv[i] << "\n";
    }
    return 0;


}

