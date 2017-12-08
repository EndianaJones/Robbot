#ifndef USER_INPUTS_H_INCLUDED
#define USER_INPUTS_H_INCLUDED

#include <vector>
#include "torsos.h"
#include "product_mas.h"
#include "arm.h"
#include "battery.h"
#include "locomoto.h"
#include "std_lib_facilitie.h"
//#include "user_inputs.h"

int all_input_part();


void read_arm(int );


void read_head(int );


void read_locomotor (int);


void read_torso (int);


void read_battery (int);



void print_arm(const vector<arm>&);


void print_head(const vector<robot_part>&);


void print_locomotor (const vector<locomotor>& );


void print_torso (const vector<torso>&);


void print_battery (const vector<battery>&);


void display_elements();

string * sender();


void save_it(int);

#endif // USER_INPUT_H_INCLUDED
