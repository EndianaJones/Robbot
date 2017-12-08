#include <iostream>
//#include <windows.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include "torsos.h"
#include "product_mas.h"
#include "arm.h"
#include "battery.h"
#include "locomoto.h"
#include "std_lib_facilitie.h"
#include "user_inputs.h"
#include "Mains.h"
#include "model_creator.hpp"
//#include "std_lib_facilities.h"
/*

void save_head (vector<robot_part> );
void save_arm (vector<arm>& );
void save_torso (vector<torso>& );
void save_battery (vector<battery>& );
void save_locomotor (vector<locomotor>& );
*/
//int all_input_part();

void save_it(int);
void which();
void save_model();


vector<robot_part> new_head;
vector<torso> new_torso;
vector<locomotor> new_locomotor;
vector<battery> new_battery;
vector<arm> new_arm;
vector<model> new_model;




int all_input_part() {




    system("cls");
    string name;
    int num;
    string type;
    double price;
    double weight;
    string des;
    int type_ans;

    cout << "\t========== Part Creator ========== "<< endl;
    cout << "\tEnter Part Name: ";
    cin.ignore();
    getline(cin, name);

    //cin.ignore();
    cout << "\tEnter Part Number: ";
    cin >> num;
    cout << "\tEnter Part price: ";
    cin >> price;
    cout << "\tEnter Part Weight: ";
    cin >> weight;
    cout << "\tEnter Part Description: ";
    cin.ignore();
    getline(cin, des);

    cout <<"\t1.Torso\t\t\t2.Head\n\t3.Locomotor\t\t4.Arm\n\t5.Battery"<<endl;
            cout << "Enter Here: ";
            cin>> type_ans;

    if (type_ans == 1){
        int comp;
        type = "Torso";

        cout << "\tEnter Power Consumed: ";
        cin >> comp;

        torso oject(name, num, type, price, weight, des, comp);

        new_torso.push_back(oject);

    } else if(type_ans == 2){
        type = "Head";

        robot_part object(name, num, type, price, weight, des);

        new_head.push_back(object);

       // cout << "print it"<< endl;
        //cout << object.get_name();

    } else if (type_ans == 3){
        double power;
        double speed;

        cout << "\tEnter Speed: ";
        cin >> speed;
        cout << "\tEnter Power: ";
        cin >> power;


        type = "Locomotor";

        locomotor object(name, num, type, price, weight, des,speed,power);
        //object.set_locomotor(speed, power);

        new_locomotor.push_back(object);
    } else if (type_ans == 4){
        type = "Arm";
        double power;

        cout <<"\tEnter power:" ;
        cin >> power;

        arm object(name, num, type, price, weight, des,power);


        new_arm.push_back(object);

    } else if (type_ans == 5){
        double energy;
        type = "Battery";

        cout << "\tEnter Energy: ";
        cin >> energy;

        battery object(name, num, type, price, weight, des, energy);

        new_battery.push_back(object);

    } else {
        system("cls");
        cout << "WRONG INPUT, TRY AGAIN\n";
        all_input_part();
    }

    /*

    //cout
    cout << des;

    robot_part addHead(name,num,"Head",price,weight,des);
    //robot_part::robot_part(name,number,"Head",price,weight,des);
    new_head.push_back(addHead);
    */
    int ans;
    cout << "\t1.Add New Part\t\t2.Save & Exit";
    cin >> ans;

    if (ans == 1){
        all_input_part();
    } else if (ans == 2){
        print_arm(new_arm);
        print_head(new_head);
        print_torso(new_torso);
        print_battery(new_battery);
        print_locomotor(new_locomotor);

        screen_pm();
        

    }
    
    return 0;
}



// add to file
void print_arm(const vector<arm>& pr){
    read_arm(1);
    unsigned long int size_vec = pr.size();
    int i;
    
    
    
    
    if (size_vec != 0){
        
        
        fstream put_in;

        put_in.open("store_arm.txt");
        
        
        for(i = 0; i < size_vec; i++){
            put_in << pr[i].get_name() << " * "<< pr[i].get_number() << " * "<<pr[i].get_type() << /*" "<< pr[i].get_price() <<*/" * "<< pr[i].get_weight() << " * " << " * " << pr[i].get_power()<< "1 * "<< pr[i].get_description() << "\n";

        }

       put_in.close();
    }



}


// IN CONSTRUCTION
void read_arm(int com){
    unsigned long int size = new_arm.size();
    
    if (com == 1 ||(com == 0 && size ==0)){
        char N[10000];
        char word[10000];
        char * breaking;
        
        
        
        fstream read_file;
        read_file.open("store_arm.txt");
        
        read_file >> N;
        while (read_file.good()){
            strcat(word, N);
            strcat(word, " ");
            read_file >> N;
            
        }
        read_file.close();
        
        
        
        int x = 1;
        
        string name;
        int num;
        string type;
        double price;
        double weight;
        string des;
        //int type_ans;
        double power;
        
        breaking = strtok(word, "*");
        while (breaking != NULL) {
            switch (x) {
                case 1:
                    name = breaking;
                    break;
                case 2:
                    istringstream (breaking) >> num;
                    break;
                case 3:
                    type = breaking;
                    break;
                case 4:
                    istringstream (breaking) >> price;
                    break;
                case 5:
                    istringstream (breaking) >> weight;
                    break;
                    
                case 6:
                    des = breaking;
                    break;
                case 7:
                    istringstream (breaking) >> power;
                    
                    arm object(name, num, type, price, weight, des,power);
                    new_arm.push_back(object);
                    
                   
                    
                    
                    x =0;
                    break;
                    
                    
            }
            
            x++;
            breaking = strtok(NULL, "*");
        }
        

    }
    if (com == 0){
        cout << "\n\n\t========== ARM ========== " << endl;
        
        //unsigned long int size = new_arm.size();
        
        int i;
        
        for (i = 0 ; i < size ; i++){
            
            cout << "\t******** " << new_arm[i].get_name() <<" ********"<< endl;
            cout << "\tNUMBER: ";
            cout << new_arm[i].get_number() << endl;
            
            cout << "\tTYPE: ";
            cout << new_arm[i].get_type() << endl;
            
            cout << "\tPRICE: ";
           // cout << new_arm[i].get_price() << endl;
            
            cout << "\tWEIGHT: ";
            cout << new_arm[i].get_weight() << endl;
            
            cout << "\tDESCRIPTION: ";
            cout << new_arm[i].get_description() << endl;
            
            
        }
    }


    
}









void print_head(const vector<robot_part>& pr){
    read_head(1);
    unsigned long int size_vec = pr.size();
    int i;
    
    if ( size_vec !=0){
        
        
        
        fstream add_file;
        
        add_file.open("store_head.txt");
        for(i = 0; i < size_vec; i++){
            add_file << pr[i].get_name() << " * " << pr[i].get_number() << " * " << pr[i].get_type() << " * " << pr[i].get_price() << " * " << pr[i].get_weight() << " * " << pr[i].get_description() << " * ";
            
        }
        
        add_file.close();
        
    }
    
}




void read_head(int com){
    unsigned long int size = new_head.size();
    cout << size << endl;
    
    if(com == 1 || (com == 0 && size == 0)){
        char N[10000];
        char word[10000];
        char * breaking;
        
        
        
        fstream read_file;
        read_file.open("store_head.txt");
        
        read_file >> N;
        while (read_file.good()){
            strcat(word, N);
            strcat(word, " ");
            read_file >> N;
            
        }
        read_file.close();
        
        
        
        int x = 1;
        
        string name;
        int num;
        string type;
        double price;
        double weight;
        string des;
        //int type_ans;
        // double power;
        
        breaking = strtok(word, "*");
        while (breaking != NULL) {
            switch (x) {
                case 1:
                    name = breaking;
                    break;
                case 2:
                    istringstream (breaking) >> num;
                    break;
                case 3:
                    type = breaking;
                    break;
                case 4:
                    istringstream (breaking) >> price;
                    break;
                case 5:
                    istringstream (breaking) >> weight;
                    break;
                    
                case 6:
                    des = breaking;
                    
                    robot_part object(name, num, type, price, weight, des);
                    new_head.push_back(object);
                    
                    /*
                    string name = " ";
                    int num = 0;
                    string type = " ";
                    double price = 0.0;
                    double weight = 0.0;
                    string des = " ";
                    */
                    
                    x =0;
                    break;
                    
                    
            }
            
            x++;
            breaking = strtok(NULL, "*");
        }
        

    }
    
    if (com == 0){
        cout << "\n\n\t========== HEAD ========== " << endl;
        
        unsigned long int Nsize = new_head.size();
        
        int i;
        
        for (i = 0 ; i < Nsize ; i++){
            
            cout << "\n\t******** " << new_head[i].get_name() <<" ********"<< endl;
            cout << "\tNUMBER:       ";
            cout << new_head[i].get_number() << endl;
            
            cout << "\tTYPE:        ";
            cout << new_head[i].get_type() << endl;
            
            cout << "\tPRICE:        ";
            cout << new_head[i].get_price() << endl;
            
            cout << "\tWEIGHT:       ";
            cout << new_head[i].get_weight() << endl;
            
            cout << "\tDESCRIPTION: ";
            cout << new_head[i].get_description() << endl;
            
            
        }
        if (i == 0){
            cout << "\t\t----   EMPTY ----" << endl;
        }
    }
    
    

}




void print_locomotor (const vector<locomotor>& pr ){
    read_locomotor(1);
    
    unsigned long int size_vec = pr.size();
    int i;
    
    if ( size_vec !=0){
        fstream add_file;
        add_file.open("store_locomotor.txt");
        for(i = 0; i < size_vec; i++){
            add_file << pr[i].get_name() << " * " << pr[i].get_number() << " * " << pr[i].get_type() << " * " << pr[i].get_price() << " * " << pr[i].get_weight() << " * "<< pr[i].get_max_speed() << " * "<<pr[i].get_power()<< " * " << pr[i].get_description() << " * ";
            
        }
        
        add_file.close();
        
    }

}


void read_locomotor(int com){
    unsigned long int size = new_locomotor.size();
    
    if (com == 1 || (com==0 && size ==0)){
        char N[10000];
        char word[10000];
        char * breaking;
        
        
        
        fstream read_file;
        read_file.open("store_locomotor.txt");
        
        read_file >> N;
        while (read_file.good()){
            strcat(word, N);
            strcat(word, " ");
            read_file >> N;
            
        }
        read_file.close();
        
        
        
        int x = 1;
        
        string name;
        int num;
        string type;
        double price;
        double weight;
        string des;
        //int type_ans;
        double power;
        double speed;
        
        breaking = strtok(word, "*");
        while (breaking != NULL) {
            switch (x) {
                case 1:
                    name = breaking;
                    break;
                case 2:
                    istringstream (breaking) >> num;
                    break;
                case 3:
                    type = breaking;
                    break;
                case 4:
                    istringstream (breaking) >> price;
                    break;
                case 5:
                    istringstream (breaking) >> weight;
                    break;
                    
                case 6:
                    des = breaking;
                    break;
                case 7:
                    istringstream (breaking) >> speed;
                    break;
                case 8:
                    istringstream(breaking) >> power;
                    
                    locomotor object(name, num, type, price, weight, des, speed, power);
                    new_locomotor.push_back(object);
                    
                    /*name = " ";
                     num = 0;
                     type = " ";
                     price = 0.0;
                     weight = 0.0;
                     des = " ";
                     */
                    
                    x =0;
                    break;
                    
                    
            }
            
            x++;
            breaking = strtok(NULL, "*");
        }
        
        
        
        

    }
    
    if (com == 0){
        cout << "\n\n\t========== Locomotor ========== " << endl;
        
        unsigned long int Nsize = new_locomotor.size();
        
        int i;
        
        for (i = 0 ; i < Nsize ; i++){
            
            cout << "\t******** " << new_locomotor[i].get_name() <<" ********"<< endl;
            cout << "\tNUMBER:       ";
            cout << new_locomotor[i].get_number() << endl;
            
            cout << "\tTYPE:        ";
            cout << new_locomotor[i].get_type() << endl;
            
            cout << "\tPRICE:        ";
            cout << new_locomotor[i].get_price() << endl;
            
            cout << "\tWEIGHT:       ";
            cout << new_locomotor[i].get_weight() << endl;
            
            cout << "\tDESCRIPTION: ";
            cout << new_locomotor[i].get_description() << endl;
            
            cout << "\tMAX SPEED:    ";
            cout << new_locomotor[i].get_max_speed() << endl;
            
            cout << "\tPOWER:        ";
            cout << new_locomotor[i].get_power();
            
        }
        if (i == 0){
            cout << "\t\t ----   EMPTY ----" << endl;
        }
    }

    
    
}




void print_torso (const vector<torso>& pr){
    read_torso(1);
    
    unsigned long int size_vec = pr.size();
    int i;
    
    if ( size_vec !=0){
        fstream add_file;
        add_file.open("store_torso.txt");
        for(i = 0; i < size_vec; i++){
            add_file << pr[i].get_name() << " * " << pr[i].get_number() << " * " << pr[i].get_type() << " * " << pr[i].get_price() << " * " << pr[i].get_weight() << " * "<< pr[i].get_comp()<< " * " << pr[i].get_description() << " * ";
            
        }
        
        add_file.close();
        
    }

}


void read_torso(int com){
    unsigned long int size = new_torso.size();
    
    if (com == 1 ||(com == 0 && size == 0)){
        char N[10000];
        char word[10000];
        char * breaking;
        
        
        
        fstream read_file;
        read_file.open("store_torso.txt");
        
        read_file >> N;
        while (read_file.good()){
            strcat(word, N);
            strcat(word, " ");
            read_file >> N;
            
        }
        read_file.close();
        
        
        
        int x = 1;
        
        string name;
        int num;
        string type;
        double price;
        double weight;
        string des;
        //int type_ans;
        int comp;
        
        breaking = strtok(word, "*");
        while (breaking != NULL) {
            switch (x) {
                case 1:
                    name = breaking;
                    break;
                case 2:
                    istringstream (breaking) >> num;
                    break;
                case 3:
                    type = breaking;
                    break;
                case 4:
                    istringstream (breaking) >> price;
                    break;
                case 5:
                    istringstream (breaking) >> weight;
                    break;
                    
                case 6:
                    des = breaking;
                    break;
                case 7:
                    istringstream (breaking) >> comp;
                    
                    
                    torso oject(name, num, type, price, weight, des, comp);
                    new_torso.push_back(oject);
                    
                    /*name = " ";
                     num = 0;
                     type = " ";
                     price = 0.0;
                     weight = 0.0;
                     des = " ";
                     */
                    
                    x =0;
                    break;
                    
                    
            }
            
            x++;
            breaking = strtok(NULL, " * ");
        }

    }
    
    
    
    if (com == 0){
        cout << "\n\n\t========== Torso ========== " << endl;
        
        //unsigned long int size = new_battery.size();
        
        int i;
        
        for (i = 0 ; i < size ; i++){
            
            cout << "\t******** " << new_torso[i].get_name() <<" ********"<< endl;
            cout << "\tNUMBER: ";
            cout << new_torso[i].get_number() << endl;
            
            cout << "\tTYPE: ";
            cout << new_torso[i].get_type() << endl;
            
            cout << "\tPRICE: ";
            cout << new_torso[i].get_price() << endl;
            
            cout << "\tWEIGHT: ";
            cout << new_torso[i].get_weight() << endl;
            
            cout << "\tDESCRIPTION: ";
            cout << new_torso[i].get_description() << endl;
            
            cout << "\tTORSO COMP: ";
            cout << new_torso[i].get_comp() << endl;
            
        }
        if (i == 0){
            cout << "\t\t ----   EMPTY ----" << endl;
        }
    }
    
    
}


void print_battery (const vector<battery>& pr){
    read_battery(1);
    
    unsigned long int size_vec = pr.size();
    int i;
    
    if ( size_vec !=0){
        fstream add_file;
        add_file.open("store_battery.txt");
        for(i = 0; i < size_vec; i++){
            add_file << pr[i].get_name() << " * " << pr[i].get_number() << " * " << pr[i].get_type() << " * " << pr[i].get_price() << " * " << pr[i].get_weight() << " * " << " * "<< pr[i].get_energy() <<" * "<< pr[i].get_description() << " * ";
            
        }
        
        add_file.close();
        
    }

}


void read_battery(int com){
    unsigned long int size = new_battery.size();
    
    if (com == 1 || ( com == 0 && size==0)){
        char N[10000];
        char word[10000];
        char * breaking;
    
    
    
        fstream read_file;
        read_file.open("store_battery.txt");
    
        read_file >> N;
        while (read_file.good()){
            strcat(word, N);
            strcat(word, " ");
            read_file >> N;
        
        }
        read_file.close();
    
    
    
        int x = 1;
    
        string name;
        int num;
        string type;
        double price;
        double weight;
        string des;
        //int type_ans;
        double energy;
    
        breaking = strtok(word, "*");
        while (breaking != NULL) {
            switch (x) {
                case 1:
                    name = breaking;
                    break;
                case 2:
                    istringstream (breaking) >> num;
                    break;
                case 3:
                    type = breaking;
                    break;
                case 4:
                    istringstream (breaking) >> price;
                    break;
                case 5:
                    istringstream (breaking) >> weight;
                    break;
                
                case 6:
                    des = breaking;
                    break;
                case 7:
                    istringstream (breaking) >> energy;
                
                    battery object(name, num, type, price, weight, des, energy);
                    new_battery.push_back(object);
                
                    name = " ";
                    num = 0;
                    type = " ";
                    price = 0.0;
                    weight = 0.0;
                    des = " ";
                
                
                    x =0;
                    break;
                
                
            }
        
            x++;
            breaking = strtok(NULL, "*");
        }
    }
    
    if (com == 0){
        cout << "\n\n\t========== Batteries ========== " << endl;
        
        //unsigned long int size = new_battery.size();
        char sender[10000];
        
        int i;
        
        for (i = 0 ; i < size ; i++){
            
            cout << "\t******** " << new_battery[i].get_name() <<" ********"<< endl;
            cout << "\tNUMBER: ";
            cout << new_battery[i].get_number() << endl;
            
            cout << "\tTYPE: ";
            cout << new_battery[i].get_type() << endl;
            
            cout << "\tPRICE: ";
            cout << new_battery[i].get_price() << endl;
            
            cout << "\tWEIGHT: ";
            cout << new_battery[i].get_weight() << endl;
            
            cout << "\tDESCRIPTION: ";
            cout << new_battery[i].get_description() << endl;
            
            cout << "\tENERGY: ";
            cout << new_battery[i].get_energy() << endl;
            
            string lol = new_battery[i].get_name() + " ";
            
            
            
        }
        if (i == 0){
            cout << "\t\t ----   EMPTY ----" << endl;
        }
    }
    
    
    
    
}

/*
string * sender(){
    
    string send[500][8];
    
    int i;
    
    for (i = 0; i < new_head.size(); i++){
        send[i][0] = new_head[i].get_name();
        send[i][1] = new_head[i].get_number();
        send[i][2] = new_head[i].get_price();
        send[i][3] = new_head[i].get_weight();
        send[i][4] = new_head[i].get_type();
    }
    
    for (i = i+1; i < new_torso.size(); i++) {
        send[i][0] = new_torso[i].get_name();
        send[i][1] = new_torso[i].get_number();
        send[i][2] = new_torso[i].get_price();
        send[i][3] = new_torso[i].get_weight();
        send[i][4] = new_torso[i].get_type();
        send[i][5] =new_torso[i].get_comp();
    }
    
    for (i = 0; i < new_arm.size(); i++){
        send[i][0] = new_arm[i].get_name();
        send[i][1] = new_arm[i].get_number();
        send[i][2] = new_arm[i].get_price();
        send[i][3] = new_arm[i].get_weight();
        send[i][4] = new_arm[i].get_type();
        send[i][5] = new_arm[i].get_power();
    }
    
    for (i = 0; i < new_locomotor.size(); i++){
        send[i][0] = new_locomotor[i].get_name();
        send[i][1] = new_locomotor[i].get_number();
        send[i][2] = new_locomotor[i].get_price();
        send[i][3] = new_locomotor[i].get_weight();
        send[i][4] = new_locomotor[i].get_type();
        send[i][5] = new_locomotor[i].get_power();
        send[i][5] = new_locomotor[i].get_max_speed();
    }
    
    for (i = 0; i < new_battery.size(); i++){
        send[i][0] = new_battery[i].get_name();
        send[i][1] = new_battery[i].get_number();
        send[i][2] = new_battery[i].get_price();
        send[i][3] = new_battery[i].get_weight();
        send[i][4] = new_battery[i].get_type();
        send[i][5] = new_battery[i].get_energy();
        
        
    }
    
    cout << send[2][2] << endl;
    return *send;
}*/




void display_elements() {
    cout << "\t========== CREATE MODEL ========== " << endl;
    cout << "\t----currently on stock----" << endl;
    
   
    which();
    
    
}

void which(){
    string temp_name;
    cout << "\tEnter Model Name: ";
    cin.ignore();
    getline(cin, temp_name);
    
    int temp_num;
    string temp_made;
    double temp_price = 0.0;
    double temp_weight;
    string temp_des;
    
    cout <<"\tEnter Model Number: ";
    cin >> temp_num;
    
    
    
    cout << "\tSelect One Head " << endl;
    
    unsigned long int size = new_head.size();
    int i;
    int answer;
    
    for (i = 0; i < size ; i++){
        cout << "\t #" << i+1 <<new_head[i].get_name() << new_head[i].get_number() << endl;
    }
    
    
    
    
    cout << "Enter HERE: ";
    cin >> answer;
    answer--;
    
    
    temp_made = temp_made + " " + "Head: " + new_head[answer].get_name();
    //temp_price = temp_price + new_head[answer].get_price();
    temp_weight = temp_weight + new_head[answer].get_weight();
    
    
    new_head.push_back(new_head[answer]);
    
    // ***TORSO***
    
    
    cout << "\tSelect One Torso: " << endl;
    
    size = new_torso.size();
    
    
    
    for (i = 0; i < size ; i++){
        cout << "\t # :" << i+1 <<new_torso[i].get_name() << new_torso[i].get_number() << endl;
    }
    
    
    
    
    cout << "Enter HERE: ";
    cin >> answer;
    answer--;
    
    
    temp_made = temp_made + " " + "Head: " + new_torso[answer].get_name();
    temp_price = temp_price + new_torso[answer].get_price();
    temp_weight = temp_weight + new_torso[answer].get_weight();
    
    new_torso.push_back(new_torso[answer]);
    // *** ARM ***
    
    cout << "\tSelect Arm(s) " << endl;
    
    size = new_arm.size();
    
    
    
    for (i = 0; i < size ; i++){
        cout << "\t # :" << i+1 <<new_arm[i].get_name() << "Number: " <<new_arm[i].get_number() << endl;
        
    }
    
    
    cout << "Enter HERE: ";
    cin >> answer;
    answer--;
    
    
    temp_made = temp_made + " " + "ARM: " + new_arm[answer].get_name();
    //temp_price = temp_price + new_arm[answer].get_price();
    temp_weight = temp_weight + new_arm[answer].get_weight();
    
    new_arm.push_back(new_arm[answer]);
    // *** LOCOMOTION ***
    cout << "\tSelect A Locomotion " << endl;
    
    size = new_locomotor.size();
    
    
    
    for (i = 0; i < size ; i++){
        cout << "\t # :" << i+1 <<new_locomotor[i].get_name()<< " " << new_locomotor[i].get_number() << endl;
    }
    
    
    
    
    cout << "Enter HERE: ";
    cin >> answer;
    answer--;
    
    
    temp_made = temp_made + " " + "Locomotor: " + new_locomotor[answer].get_name();
    temp_price = temp_price + new_locomotor[answer].get_price();
    temp_weight = temp_weight + new_locomotor[answer].get_weight();
    
    new_locomotor.push_back(new_locomotor[answer]);
    // BATTERY
    
    cout << "\tSelect BATTERY(IES) " << endl;
    
    size = new_battery.size();
    
    
    
    for (i = 0; i < size ; i++){
        cout << "\t # :" << i+1 <<new_battery[i].get_name() << " "<<new_battery[i].get_energy() << endl;
    }
    
    
    
    
    cout << "Enter HERE: ";
    cin >> answer;
    answer--;
    
    
    temp_made = temp_made + " " + "BATTERY: " + new_battery[answer].get_name();
    temp_price = temp_price + new_battery[answer].get_price();
    temp_weight = temp_weight + new_battery[answer].get_weight();
    
    
    model object(temp_name, temp_num, temp_price, temp_made, temp_weight, temp_des);
    new_model.push_back(object);
    
    new_battery.push_back(new_battery[answer]);
    
    save_model();
    
}


void save_model(){
    save_it(1);
    fstream add_in;
    add_in.open("store_model.txt");
    
    add_in << new_model[0].get_name() <<" * "<< new_model[0].get_number() <<" * "<< new_model[0].get_price() <<" * "<< new_model[0].get_made() << " * "<< new_model[0].get_weight()<< " * "<< new_model[0].get_des() <<" * ";
    
    add_in.close();
    
    screen_pm();
    
}

void save_it(int com){
    unsigned long int size = new_model.size();
    
    if (com == 1 || ( com == 0 && size==0)){
        char N[10000];
        char word[10000];
        char * breaking;
        
        
        
        fstream read_file;
        read_file.open("store_model.txt");
        
        read_file >> N;
        while (read_file.good()){
            strcat(word, N);
            strcat(word, " ");
            read_file >> N;
            
        }
        read_file.close();
        
        
        //model (string name_it, int number_it, double price_it , string made_it, double weight_it, string des_it)
        int x = 1;
        
        string name ;
        double price;
        double num ;
        string made_of;
        double weight ;
        string des;
        
        breaking = strtok(word, "*");
        while (breaking != NULL) {
            switch (x) {
                case 1:
                    name = breaking;
                    break;
                case 2:
                    istringstream (breaking) >> num;
                    break;
                case 3:
                    istringstream (breaking) >> price;
                    break;
                case 4:
                    made_of = breaking;
                    break;
                case 5:
                    istringstream (breaking) >> weight;
                    break;
                    
                case 6:
                    des = breaking;
                    
                    
                    model object(name, num, price, made_of, weight, des);
                    new_model.push_back(object);
                    
                    
                    
                    x =0;
                    break;
                    
                    
            }
            
            x++;
            breaking = strtok(NULL, "*");
        }
    }
    
    if (com == 0){
        cout << "\n\n\t========== MODEL ========== " << endl;
        
        //unsigned long int size = new_battery.size();
        //char sender[10000];
        
        int i;
        
        for (i = 0 ; i < size ; i++){
            
            cout << "\t******** " << new_model[i].get_name() <<" ********"<< endl;
            cout << "\tNUMBER: ";
            cout << new_model[i].get_number() << endl;
            
            cout << "\tMADE OF: ";
            cout << new_model[i].get_made() << endl;
            
            cout << "\tPRICE: ";
            cout << new_model[i].get_price() << endl;
            
            cout << "\tWEIGHT: ";
            cout << new_model[i].get_weight() << endl;
            
            cout << "\tDESCRIPTION: ";
            cout << new_model[i].get_des() << endl;
            
            
            
            
        }
        if (i == 0){
            cout << "\t\t ----   EMPTY ----" << endl;
        }
    }
    
    
    
    
}
