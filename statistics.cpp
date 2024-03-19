#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

// Функция заполнения массива
int* generatorArr(int sizeArr) {


	int* arr = new int[sizeArr]; // Динамический массив 

	for (int i = 0; i < sizeArr; i++)
	{
		cout << "Введите\t" << i + 1 << " число:\t";
		cin >> arr[i];  // записываем числа в ячейки массива
	}

	return arr;
}

// Функция для вычисления среднего значения.
double average(int* arr, int size)
{
	double sum = 0;

	for (int i = 0; i < size; i++) 
	{
		sum += arr[i];
	}

	return sum / size;
}

// Функция для вычисления среднеквадратического отклонения
double standard_deviation(int* arr, int size)
{
	double mean = average(arr, size); // Вычисляем среднее значение

	double sumSquaredDifference = 0;

	for (int i = 0; i < size; i++) {

		sumSquaredDifference += pow(arr[i] - mean, 2); // Суммируем квадраты разностей 
	}

	return sqrt(sumSquaredDifference / size);
}
