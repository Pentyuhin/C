#include <iostream>
#include "Header.h"

using namespace std;

enum class Day
{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

int closing_time(Day day_of_the_week);
void print_day(Day day, ostream& os);

void shop_day()
{
	// ������ ��������� �������
	cout.width(17);
	cout << "���� ";
	cout.width(19);
	cout << "����� ����������� \n\n";


	// ������ ������� �� ������������ (Day::Monday) ��
	// ����������� (Day::Sunday)
	for (int count = static_cast<int>(Day::Monday); count <= static_cast<int>(Day::Sunday); count++)
	{
		cout.width(19);

		print_day(static_cast<Day>(count), cout);

		cout.width(9);
		cout << closing_time(static_cast<Day>(count)) << ": 00\n";
	}
}



int closing_time(Day day_of_the_week)
{
	return 17;
}


void print_day(Day day, ostream& os)
{
	switch (static_cast<int>(day))
	{
		case 0: cout << "�����������"; break;
		case 1: cout << "�������"; break;
		case 2: cout << "�����"; break;
		case 3: cout << "�������"; break;
		case 4:	cout << "�������"; break;
		case 5: cout << "�������"; break;
		case 6: cout << "�����������"; break;
		default: cout << "������!"; break;
	}
}