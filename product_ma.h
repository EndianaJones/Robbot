#ifndef PRODUCT_MA_H_INCLUDED
#define PRODUCT_MA_H_INCLUDED
#include "std_lib_facilities.h"

class robot_part {
    private:
        string part_name;
        int part_number;
        string part_type; //can be Torso, head, Locomotor or battery
        double part_price;
        double part_weight;
        string part_description;

    public:
        robot_part();


        robot_part(string, int, string, double, double, string);



        //void set_name();
        string get_name() const;

        //void set_number(int);
        int get_number() const;

       // void set_type(string type);
        string get_type() const;

       // void set_price(double);
        double get_price() const;

       // void set_weight(double);
        double get_weight() const ;

       // void set_description(string);
        string get_description() const ;


};





#endif // PRODUCT_MA_H_INCLUDED
