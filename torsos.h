#ifndef TORSOS_H_INCLUDED
#define TORSOS_H_INCLUDED
#include "std_lib_facilitie.h"
//#include "product_ma.h"

class torso{
    private:
        int part_battery_comp;
        string part_name;
        int part_number;
        string part_type; //can be Torso, head, Locomotor or battery
        double part_price;
        double part_weight;
        string part_description;

    public:
        torso();


        torso(string , int , string , double , double , string , int);



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
    
    int get_comp() const;


       //torso();


        /*torso(string name, int number, string type, double price, double weight, string des, int comp){
            part_name = name;
            part_number = number;
            part_type = type; //can be Torso, head, Locomotor or battery
            part_price = price;
            part_weight = weight;
            part_description = des;
            part_battery_comp = comp;


        }

*/






};


#endif // TORSO_H_INCLUDED
