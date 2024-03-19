#include <iostream>
#include <windows.h>

using namespace std;

// ������� �������� ���������, ����������� ���������� ���������.
void print_preliminary_message()
{
	cout << "��� ��������� �������� �������� ���������� � ������ ������.\n\n";
}

// ������� ����������� � ������������ ��������� ��� ������� � ����������.
double input_table_specifications(double& minTemp, double& maxTemp, double& step)
{
	cout << "������� ����������� ����������� � �������� �������: ";
	cin >> minTemp;

	cout << "������� ������������ ����������� � �������� �������: ";
	cin >> maxTemp;

	cout << "������� ��� ��������� �����������: ";
	cin >> step;

	return minTemp, maxTemp, step;
}

// ������� ����������� ����������, ��������� �������������.
void print_message_echoing_input(double minTemp, double maxTemp, double step)
{
	cout << "����������� � �������� �������: �� " << minTemp << " �� " << maxTemp << " � ����� " << step << "\n\n";
}

// ������� �������� ��������� ������� ���������.
void print_table()
{
	cout << "\n ������� �������������� ����������: \n";
	cout << "  �������" << "  " << "  ���������" << "  " << "  �������\n";
}

// ������� ���������� �������� ����������� �� ����� ���������� ��� ����������� �������� �� ����� �������.
double fahrenheit_of(double& minTemp)
{
	double fahrenheitTemp = 1.8 * minTemp + 32;

	return fahrenheitTemp;
}
// ������� ���������� �������� ����������� � ���������� ����� ��� ����������� �������� �� ����� �������.
double absolute_value_of(double& minTemp)
{
	double kelvinTemp = minTemp + 273.15;

	return kelvinTemp;

}

// ������� ������� �������� �����������, ����������� � ����������� � ����������� �������� �����������
void getTemp(double& minTemp, double& maxTemp, double& step)
{

	for (double temp = minTemp; temp <= maxTemp; temp += step)
	{
		// ����� �������� �����������, ����������� � ����������� � ����������� �������� �����������
		cout << "\t" << temp << "\t" << fahrenheit_of(temp) << "\t" << absolute_value_of(temp) << endl;
	}
}