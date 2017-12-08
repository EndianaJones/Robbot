#ifndef BATTERY_H_INCLUDED
#define BATTERY_H_INCLUDED
//#include "product_ma.h"

class battery {
    private:
        double part_energy;
        string part_name;
        int part_number;
        string part_type; //can be Torso, head, Locomotor or battery
        double part_price;
        double part_weight;
        string part_description;

    public:
        battery();

        battery(string, int, string, double, double, string, double);

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

        double get_energy() const;
};


#endif // BATTERY_H_INCLUDED
