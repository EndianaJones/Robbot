//
//  model_creator.hpp
//  project_rob
//
//  Created by Gerve-Endy Pluviose on 10/19/16.
//  Copyright © 2016 Gerve-Endy Pluviose. All rights reserved.
//

#ifndef model_creator_hpp
#define model_creator_hpp

#include <stdio.h>
#include "user_inputs.h"

class model {
private:
    string name;
    int number;
    double price;
    string made_of;
    double weight;
    string des;
public:
    model (string, int, double, string, double, string);
    
    string get_name() const;
    int get_number() const;
    double get_price() const;
    string get_made() const;
    double get_weight() const;
    string get_des() const;
};

//void display_elements();
#endif /* model_creator_hpp */
