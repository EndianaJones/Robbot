#include <iostream>
#include <fstream>
//#include <conio.h>
//#include<windows.h>
#include "user_inputs.h"
#include "main.h"
#include "model_creator.hpp"
#include "customer.hpp"

using namespace std;



int main(){

    int ans;
    cout << "\t========== HOME ========== "<< endl;
    cout << "\t1. Customer"<< endl;
    cout << "\t2. Employee" << endl;
    cout << "\tENTER 1 OR 2:  ";
    cin >> ans;

    if(ans == 1){
        customer();

    } else if (ans == 2){
        screen_empl();
    } else {
        
        cout << "WRONG INPUT, TRY AGAIN\n";
        main();
    }

}


void screen_empl(){

   

    cout << "\t========== EMPLOYEE ========== "<< endl;

    int ans;
    cout << "\t1. Product Management"<< endl;
    cout << "\t2. Sales Associate" << endl;
    cout << "\t3. Corporate"<< endl;
    cout << "\tENTER 1, 2 OR 3:  ";
    cin >> ans;

    if (ans == 1){
        screen_pm();
    } else if (ans == 2){
        cout << "2"<< endl;
    } else if (ans == 3){
        cout << "3" << endl;

    } else {
        system("cls");
        cout << "WRONG INPUT, TRY AGAIN\n";
        screen_empl();
    }

}


void screen_pm(){
    //system("cls");
    

    cout << "\n\n\t========== PRODUCT MANAGEMENT ========== "<< endl;
    int ans;
    //int type_ans;

    cout <<"\t1.Add Part\t\t\t2.Create New Model\n\t3.Display Part(s)\t\t4.Display Model(s)\n\t5.GO HOME"<<endl;
    cout <<"Enter 1,2,3,OR4: ";
    cin >> ans;
   
   switch(ans){
    case 1:
        all_input_part();
        break;
    case 2:
           display_elements();
           
        break;
    case 3:
           read_head(0);
           read_torso(0);
           read_arm(0);
           read_locomotor(0);
           read_battery(0);
           
        break;
    case 4:
           save_it(0);
        break;
    case 5:
           main();
        break;
           
           
    default:
        cout << "WRONG INPUT, TRY AGAIN"<<endl;


    }


}

