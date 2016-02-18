//
//  hashTable.cpp
//  Radix_Sort
//
//  Created by Devin Lee on 10/15/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#include "hashTable.h"
#include "node.h"
#include "Queue.h"
#include<fstream>


hashTable::hashTable () {
    d = new Queue[size];
    for (int i = 0; i < size; i++) {
        d[i] = *new Queue();
    }
}

void hashTable:: printTable (ostream &output_file) {
    
    output_file << "ENTIRE Queue: " << endl; 
    
    for (int i = 0; i < size; i++) {
        if (!d[i].isEmpty() && d[i].head->next != NULL) {
            
                node* spot = d[i].head;
                output_file << "Queue w/ index: " << i << endl;
                output_file << "HEAD --> (" << spot->data << " , " << spot->next->data << ")";
            

                while (spot->next != NULL /*&& spot->next != d[i].tail*/) {
                    if (spot->next != d[i].tail) {
                    spot = spot->next;
                    output_file << "--> (" << spot->data << " , " << spot->next->data << ")";
                    }
                    else {
                        spot = spot->next;
                        output_file << "--> (" << spot->data << " ,  NULL)";
                        break;

                    }
                }
            
            output_file << endl << endl;
            
        }
    
        
        else {
            
            output_file << "Queue w/ index: " << i << endl;
            output_file << "HEAD --> (dummy ,  NULL)" << endl << endl;
                
            
        }
        
    }

    output_file << endl << endl << endl;
    
    
}




