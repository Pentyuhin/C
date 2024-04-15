#include <iostream>
#include <cmath>

#include "IntegerArray.h"

using namespace std;

void input_array(int a[], int n)
{
	cout << "Enter " << n << " values for the array" << endl;

	for (int i = 0; i < n; i++)
	{	
		cout << "Enter " << i + 1 << " number: ";
		cin >> a[i];
	}
	
}

void display_array(int a[], int)
{
	for (int i = 0; i < MAXLENGTH_ARRAY; i++)
	{
		cout << arr_number[i] << "\t";

	}
}

void copy_array(int a1[], int a2[], int n) 
{
	for (int i = 0; i < n; i++)
	{
		a1[i] = a2[i];
	}

	for (int i = 0; i < MAXLENGTH_ARRAY; i++)
	{
		cout << a2[i] << "\t";
	}
}


double  average(int a[], int n)
{
	double  total = 0.0f;

	for (int i = 0; i < n; i++)
	{
		total += double(a[i]);
	}

	return total / n;
	
}

double  standard_deviation(int a[], int n)
{
	double  mean = average(arr_number, MAXLENGTH_ARRAY);
	double  sum_sq_diff = 0;

	for (int i = 0; i < n; i++)
	{
		sum_sq_diff += pow(a[i] - mean, 2);
	}

	return sqrt(sum_sq_diff / n);
}



