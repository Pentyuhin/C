#include <iostream>
using namespace std;

// ������� ���������� �� ������ "��������" �������� ������ �� ��������.
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

// ������� ������� ���������� � ��������� �������� �������� ������  
void test_print_pyramid()
{
	int height = 0;

	cout << "��� ��������� �������� �� ������ \"��������\" �������� ������." << endl;

	do
	{
		cout << "������� ������ ��������: ";
		cin >> height;

		if (height < 1 || height > 30) {
			cout << "������� ������ �������� (�� ��������� �� 1 �� 30): ";
			cin >> height;
		}
	} while (height < 1 || height > 30);

	print_pyramid(height);

}