#include <iostream>
#include <windows.h>
#include "statistics.h"

using namespace std;


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size = 0;
	
	int flag = 1;

	while (flag != 0)
	{
		cout << "Введите количество элементов, в массиве: ";
		cin >> size;


		// Проверка что элементов в массиве больше 0 и не char
		if (size <= 0 || typeid(size) == typeid(char))
		{
			cout << "Некорректный ввод. Пожалуйста, введите положительное целое число.\n";

			return 1;
		}


		int* arr = generatorArr(size); // Функция заполнения массива

		if (arr != nullptr)
		{
			double mean = average(arr, size); // Вычисляем среднее значение
			double stdDev = standard_deviation(arr, size); // Вычисляем среднеквадратическое отклонение


			cout << "Среднее значение\t" << mean << endl;
			cout << "Среднеквадратическое отклонение\t" << stdDev << endl;

			delete[] arr; // Удаление массива	

		}
		
		cout << "Хотите продолжить выполнение? (1 - да, 0 - нет): ";
		cin >> flag; // Получаем ответ от пользователя
	}

	return 0;
}


