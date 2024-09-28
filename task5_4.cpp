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
	// Печать заголовка таблицы
	cout.width(17);
	cout << "ДЕНЬ ";
	cout.width(19);
	cout << "ВРЕМЯ ЗАКРЫВАЕТСЯ \n\n";


	// Печать таблицы от понедельника (Day::Monday) до
	// воскресенья (Day::Sunday)
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
		case 0: cout << "Понедельник"; break;
		case 1: cout << "Вторник"; break;
		case 2: cout << "Среда"; break;
		case 3: cout << "Четверг"; break;
		case 4:	cout << "Пятница"; break;
		case 5: cout << "Суббота"; break;
		case 6: cout << "Воскресенье"; break;
		default: cout << "ОШИБКА!"; break;
	}
}