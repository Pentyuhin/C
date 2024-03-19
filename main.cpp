#include "conversions.h"
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double minTemp, maxTemp, step;

	print_preliminary_message();

	input_table_specifications(minTemp, maxTemp, step);

	print_message_echoing_input(minTemp, maxTemp, step);

	print_table();

	fahrenheit_of(minTemp);

	absolute_value_of(minTemp);

	getTemp(minTemp, maxTemp, step);


	return 0;
}
