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
		cout << "������� ���������� ���������, � �������: ";
		cin >> size;


		// �������� ��� ��������� � ������� ������ 0 � �� char
		if (size <= 0 || typeid(size) == typeid(char))
		{
			cout << "������������ ����. ����������, ������� ������������� ����� �����.\n";

			return 1;
		}


		int* arr = generatorArr(size); // ������� ���������� �������

		if (arr != nullptr)
		{
			double mean = average(arr, size); // ��������� ������� ��������
			double stdDev = standard_deviation(arr, size); // ��������� �������������������� ����������


			cout << "������� ��������\t" << mean << endl;
			cout << "�������������������� ����������\t" << stdDev << endl;

			delete[] arr; // �������� �������	

		}
		
		cout << "������ ���������� ����������? (1 - ��, 0 - ���): ";
		cin >> flag; // �������� ����� �� ������������
	}

	return 0;
}


