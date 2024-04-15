#pragma once
#include "IntegerArray.cpp"


const int MAXLENGTH_ARRAY = 5;
int arr_number[MAXLENGTH_ARRAY] = { 0 };
int second_array[MAXLENGTH_ARRAY] = { 5, 5, 5, 5, 5 };


void input_array(int a[], int n);

void display_array(int a[], int);

void copy_array(int a1[], int a2[], int n);

double  standard_deviation(int a[], int n);