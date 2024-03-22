#include <iostream>
using namespace std;

// Функция отображает на экране "пирамиду" заданной высоты из символов.
void print_pyramid(int height)
{

	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= height - i; j++) {
			cout << " ";
		}
		for (int k = 1; k <= 2 * i - 1; k++) {
			cout << "*";
		}
		cout << endl;
	}
}

// Функция выводит информацию и проверяет диапазон значений высоты  
void test_print_pyramid()
{
	int height = 0;

	cout << "Эта программа печатает на экране \"пирамиду\" заданной высоты." << endl;

	do
	{
		cout << "Введите высоту пирамиды: ";
		cin >> height;

		if (height < 1 || height > 30) {
			cout << "Введите другое значение (из диапазона от 1 до 30): ";
			cin >> height;
		}
	} while (height < 1 || height > 30);

	print_pyramid(height);

}