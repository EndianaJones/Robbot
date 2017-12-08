#ifndef LOCOMOTOR_H_INCLUDED
#define LOCOMOTOR_H_INCLUDED
#include "std_lib_facilitie.h"

using namespace std;

class locomotor {
    private:
        double part_max_speed; // in MPH
        double part_power; //in watts
        int part_battery_comp;
        string part_name;
        int part_number;
        string part_type; //can be Torso, head, Locomotor or battery
        double part_price;
        double part_weight;
        string part_description;

    public:
        locomotor();


        locomotor(string , int , string , double , double , string , double, double );



        //void set_name();
        string get_name() const ;

        //void set_number(int);
        int get_number() const;

       // void set_type(string type);
        string get_type() const;

       // void set_price(double);
        double get_price() const;
       // void set_weight(double);
        double get_weight() const ;

       // void set_description(string);
        string get_description() const;

        double get_max_speed() const ;

        double get_power() const;

};

#endif // LOCOMOTOR_H_INCLUDED
