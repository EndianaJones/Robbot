
#include <iostream>
#include "std_lib_facilities.h"
#include "product_ma.h"


/*robot_part::robot_part(){
    int part_number = 0;
    double part_price = 0.0;
    double part_weight = 0.0;

}*/
robot_part::robot_part( string name, int number, string type, double price, double weight, string des){
        part_name = name;
        part_number = number;
        part_type = type; //can be Torso, head, Locomotor or battery
        part_price = price;
        part_weight = weight;
        part_description = des;


}

string robot_part::get_name()const {
    return part_name;
}


int robot_part::get_number()const{
    return part_number;
}



string robot_part::get_type() const {
    return part_type;
}



double robot_part::get_price() const {
    return part_price;
}


string robot_part::get_description()const {
    return part_description;
}

double robot_part::get_weight() const {
    return part_weight;
}

