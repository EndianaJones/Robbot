#include <iostream>
#include "arm.h"
#include "std_lib_facilities.h"

arm::arm(string name , int number, string type, double price, double weight, string des , double power){
            part_name = name ;
            part_number = number;
            part_type = type; //can be Torso, head, Locomotor or battery
            part_price = price;
            part_weight = weight;
            part_power = power;
}



        //void set_name();
        string arm::get_name() const {
            return part_name;
        }

        //void set_number(int);
        int arm::get_number() const{
            return part_number;
        }

       // void set_type(string type);
        string arm::get_type() const{
            return part_description;
        }

       // void set_price(double); double get_price const();
        double arm::get_price(){
            return part_price;
        }

       // void set_weight(double);
        double arm::get_weight() const {
            return part_weight;
        }

       // void set_description(string);
        string arm::get_description() const {
            return part_description;
        }

        double arm::get_power() const {
            return part_power;
        }
