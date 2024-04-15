#include <iostream>
#include <windows.h>
#include "IntegerArray.h"

using namespace std;



int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	input_array(arr_number, MAXLENGTH_ARRAY);

	display_array(arr_number, MAXLENGTH_ARRAY);

	copy_array(arr_number, second_array, MAXLENGTH_ARRAY);

	cout << endl;

	cout << "Стандартное отклонение: " << standard_deviation(arr_number, MAXLENGTH_ARRAY) << endl;

	return 0;
}