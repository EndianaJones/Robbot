//
//  customer.cpp
//  project_rob
//
//  Created by Gerve-Endy Pluviose on 10/20/16.
//  Copyright © 2016 Gerve-Endy Pluviose. All rights reserved.
//

#include "customer.hpp"
#include <fstream>
#include "std_lib_facilitie.h"
#include "find_cust.hpp"
void add_cust(string,string);
void new_cust();
//void put_cust(char );
void customer(){
    cout << "\t========== CUSTOMER ========== "<< endl;
    cout << "\t1: New Customer\t\t 2: Search For Existing Customer" << endl;
    int ans;
    cout <<"Enter Answer Here: ";
    cin >> ans;
    if (ans == 1){
        new_cust();
    } else if (ans == 2){
        string name;
        cout << "\tEnter Full Name (F&L): ";
        cin.ignore();
        getline(cin, name);
        string result = find_cust(name);
        cout << result<< endl;
        
    } else {
        customer();
    }
}

void new_cust(){
    
    string name,address;
    
    cout << "\t========== NEW CUSTOMER ========== "<< endl;
    cout << "\tEnter Full Name (F&L): ";
    cin.ignore();
    getline(cin, name);
    cout <<"\tEnter Full Address: ";
    cin.ignore();
    getline(cin, address);
    
    add_cust(name, address);
    
}


void put_cust(string arr[][2], int m){
    int i;
    m++;
    cout << arr[0][0] << endl;
    
    fstream put_in;
    put_in.open("store_customer.txt");
    
    
    
    for( i = 0; i < m; i++){
        put_in << arr[i][0] <<" * "<< arr[i][1]<<" * ";
    }
    put_in.close();
    
    
}





void add_cust(string new_cust_name, string new_cust_add){
    string arr[100][2];
    
    //int rows =  sizeof arr / sizeof arr[0]; // 2 rows
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
    
    arr[i][0] = new_cust_name;
    arr[i][1] = new_cust_add;
    //int rows =  sizeof arr / sizeof arr[0];
    cout << arr[0][0] << endl;
    
    
    put_cust(arr, i);
}

