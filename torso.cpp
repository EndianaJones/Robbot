#include <iostream>
#include "torso.h"
#include "std_lib_facilities.h"

//torso();


        torso::torso(string name, int number, string type, double price, double weight, string des, int comp){

            part_name = name ;
            part_number = number;
            part_type = type; //can be Torso, head, Locomotor or battery
            part_price = price;
            part_weight = weight;
            part_description = des;
            part_battery_comp = comp;

        };



        //void set_name();
        string torso::get_name() const {
            return part_name;
        }

        //void set_number(int);
        int torso::get_number() const{
            return part_number;
        }

       // void set_type(string type);
        string torso::get_type() const{
            return part_description;
        }

       // void set_price(double);
        double torso::get_price() {
            return part_price;
        }

       // void set_weight(double);
        double torso::get_weight() const {
            return part_weight;
        }

       // void set_description(string);
        string torso::get_description() const {
            return part_description;
        }
