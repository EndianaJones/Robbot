//
//  model_creator.cpp
//  project_rob
//
//  Created by Gerve-Endy Pluviose on 10/19/16.
//  Copyright © 2016 Gerve-Endy Pluviose. All rights reserved.
//


 


#include <iostream>
#include <fstream>
#include <string>
#include "model_creator.hpp"
//#include "user_inputs.cpp"


void save_it(int com);
model::model (string name_it, int number_it, double price_it , string made_it, double weight_it, string des_it){
    name = name_it;
    price = price_it;
    number = number_it;
    made_of = made_it;
    weight = weight_it;
    des = des_it;
    
}


string model::get_name() const{
    return name;
}

int model::get_number() const{
    return number;
}

double model::get_price() const{
    return price;
}

string model::get_made() const{
    return made_of;
}
double model::get_weight() const{
    return weight;
}
string model::get_des() const{
    return des;
}










