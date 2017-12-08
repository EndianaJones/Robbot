#include <iostream>
#include "locomoto.h"
//#include "std_lib_facilities.h"

locomotor::locomotor(string name , int number, string type, double price, double weight, string des , double power, double speed){
            part_name = name ;
            part_number = number;
            part_type = type; //can be Torso, head, Locomotor or battery
            part_price = price;
            part_weight = weight;
            part_power = power;
            part_max_speed = speed;
            part_description = des;
}



        //void set_name();
        string locomotor::get_name() const {
            return part_name;
        }

        //void set_number(int);
        int locomotor::get_number() const{
            return part_number;
        }

       // void set_type(string type);
        string locomotor::get_type() const{
            return part_description;
        }

       // void set_price(double);
        double locomotor::get_price() const{
            return part_price;
        }

       // void set_weight(double);
        double locomotor::get_weight() const {
            return part_weight;
        }

       // void set_description(string);
        string locomotor::get_description() const {
            return part_description;
        }



        double locomotor::get_max_speed() const{
            return part_max_speed;
        }

        double locomotor::get_power()const{
            return part_power;
        }
