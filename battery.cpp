#include <iostream>
#include "std_lib_facilities.h"
#include "battery.h"


//battery();

battery::battery(string name, int num, string type, double  price, double weight, string des, double energy){
        part_energy = energy;
        part_name = name;
        part_number = num;
        part_type = type; //can be Torso, head, Locomotor or battery
        part_price = price;
        part_weight = weight;
        part_description = des;

}

        //void set_name();
string battery::get_name() const{
    return part_name;
}

        //void set_number(int);
int battery::get_number() const{
    return part_number;
}

       // void set_type(string type);
string battery::get_type() const{
    return part_type;
}

       // void set_price(double);
double battery::get_price() const{
    return part_price;
}

       // void set_weight(double);
double battery::get_weight() const {
    return part_weight;
}

       // void set_description(string);
string battery::get_description() const {
    return part_description;
}


double battery::get_energy() const{
    return part_energy;
}
