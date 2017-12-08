//
//  find_cust.cpp
//  project_rob
//
//  Created by Gerve-Endy Pluviose on 10/20/16.
//  Copyright © 2016 Gerve-Endy Pluviose. All rights reserved.
//

#include "find_cust.hpp"
#include "std_lib_facilitie.h"


string find_cust (string name_s){
    string arr[100][2];
    
    char N[100000];
    char word[100000];
    char *breaking;
    //int cols = sizeof arr[0] / sizeof(int); // 5 cols
    
    
    fstream cust;
    cust.open("store_customer.txt");
    cust >> N;
    while (cust.good()) {
        strcat(word, N);
        strcat(word, " ");
        cust >> N;
    }
    
    cust.close();
    string name;
    string address;
    
    breaking = strtok(word, "*");
    int x = 1;
    int i = 0;
    while (breaking != NULL) {
        if (x == 1){
            name = breaking;
            arr[i][0] = name;
        } else if (x == 2){
            address = breaking;
            x = 0;
            arr[i][1] = address;
            i++;
        }
        x++;
        
        breaking = strtok(NULL, "*");
    }
    string done;
    
    int j;
    for( j = 0; j < i+1; j++){
        cout << arr[j][0]<< endl;
        if (arr[j][0].compare(name_s) == 0){
            done = arr[j][1];
        } else {
            done = "No custormer found!";
        }
        
        
    }
    

    
    return done;
}