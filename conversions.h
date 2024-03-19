#ifndef CONVERSIONS_H
#define  CONVERSIONS_H

#include <iostream>
#include <windows.h>
#include <iomanip>

void print_preliminary_message();

double input_table_specifications(double& minTemp, double& maxTemp, double& step);

void print_message_echoing_input(double minTemp, double maxTemp, double step);

void print_table();

double fahrenheit_of(double& minTemp);

double absolute_value_of(double& minTemp);

void getTemp(double& minTemp, double& maxTemp, double& step);

#endif // CONVERSIONS_H

