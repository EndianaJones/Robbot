#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include "torso.h"
#include "product_ma.h"
#include "arm.h"
#include "battery.h"
#include "locomotor.h"
#include "std_lib_facilities.h"
#include "user_input.h"
#include "main.h"
//#include "std_lib_facilities.h"
/*

void save_head (vector<robot_part> );
void save_arm (vector<arm>& );
void save_torso (vector<torso>& );
void save_battery (vector<battery>& );
void save_locomotor (vector<locomotor>& );
*/
//int all_input_part();
void print_arm(const vector<arm>&);
void print_head(const vector<robot_part>&);
void print_locomotor (const vector<locomotor>& );
void print_torso (const vector<torso>&);
void print_battery (const vector<battery>&);
    vector<robot_part> new_head;
    vector<torso> new_torso;
    vector<locomotor> new_locomotor;
    vector<battery> new_battery;
    vector<arm> new_arm;
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


        //screen_pm();


    }

    return 0;
}




void print_arm(const vector<arm>& pr){
    /*unsigned long int size_vec = pr.size();
    int i;
    cout << "hi";
    if (size_vec != 0){
        fstream put_in;

        put_in.open("store_arm.txt");

        for(i = 0; i < size_vec; i++){
            cout << pr[i].get_name() << " "<< pr[i].get_number() << " "<<pr[i].get_type();// << " "<< pr[i].get_price() <<" "<< pr[i].get_weight() << " " << pr[i].get_description()<< " " << pr[i].get_power() << "\n";

        }

       put_in.close();
    }

*/

}

void print_head(const vector<robot_part>& pr){
    /*unsigned long int size_vec = pr.size();
    int i;
    for(i = 0; i < size_vec; i++){
        cout << pr[i].get_name() << endl;

    }*/
}


void print_locomotor (const vector<locomotor>& pr ){

}


void print_torso (const vector<torso>& pr){

}


void print_battery (const vector<battery>& pr){

}


