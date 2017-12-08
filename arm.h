#ifndef ARM_H_INCLUDED
#define ARM_H_INCLUDED
//#include "product_ma.h";
#include "std_lib_facilities.h"

class arm {
    private:
        double part_power; // in watts
        int part_battery_comp;
        string part_name;
        int part_number;
        string part_type; //can be Torso, head, Locomotor or battery
        double part_price;
        double part_weight;
        string part_description;

    public:
        arm();


        arm(string , int , string , double , double , string , double);



        //void set_name();
        string get_name() const ;

        //void set_number(int);
        int get_number() const;

       // void set_type(string type);
        string get_type() const;

       // void set_price(double);
        double get_price();
       // void set_weight(double);
        double get_weight() const ;

       // void set_description(string);
        string get_description() const;

        double get_power() const;
};


#endif // ARM_H_INCLUDED
