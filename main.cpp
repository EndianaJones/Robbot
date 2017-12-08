#include <iostream>
#include <fstream>
#include <conio.h>
#include<windows.h>
#include "user_input.h"
#include "main.h"

using namespace std;



int main(){

    int ans;
    cout << "\t========== HOME ========== "<< endl;
    cout << "\t1. Customer"<< endl;
    cout << "\t2. Employee" << endl;
    cout << "\tENTER 1 OR 2:  ";
    cin >> ans;

    if(ans == 1){

    } else if (ans == 2){
        screen_empl();
    } else {
        system("cls");
        cout << "WRONG INPUT, TRY AGAIN\n";
        main();
    }

}


void screen_empl(){

    system("cls");

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
    system("cls");

    cout << "\t========== PRODUCT MANAGEMENT ========== "<< endl;
    int ans;
    int type_ans;

    cout <<"\t1.Add Part\t\t\t2.Create New Model\n\t3.Display Part(s)\t\t4.Display Model(s)"<<endl;
    cout <<"Enter 1,2,3,OR4: ";
    cin >> ans;
    system("cls");
   switch(ans){
    case 1:
        all_input_part();
        break;
    case 2:


        break;
    case 3:

        break;
    case 4:

        break;
    default:
        cout << "WRONG INPUT, TRY AGAIN"<<endl;


    }


}

