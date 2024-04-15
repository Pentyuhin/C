#include <iostream>
#include <iomanip>
#include "Header.h"

using namespace std;

void shop_day()
{
    cout << setw(17) << "ДЕНЬ " << setw(19) << "ВРЕМЯ ЗАКРЫВАЕТСЯ \n\n";

    for (int count = static_cast<int>(Day::Monday); count <= static_cast<int>(Day::Sunday); count++)
    {
        cout << setw(19);
        print_day(static_cast<Day>(count), cout);
        cout << setw(9);
        closing_time(static_cast<Day>(count), cout);
    }
}

void print_day(Day day, ostream& os)
{
    switch (day)
    {
    case Day::Monday: os << "Понедельник"; break;
    case Day::Tuesday: os << "Вторник"; break;
    case Day::Wednesday: os << "Среда"; break;
    case Day::Thursday: os << "Четверг"; break;
    case Day::Friday: os << "Пятница"; break;
    case Day::Saturday: os << "Суббота"; break;
    case Day::Sunday: os << "Воскресенье"; break;
    default: os << "ОШИБКА!"; break;
    }
}

void closing_time(Day day_of_the_week, ostream& os)
{
    switch (day_of_the_week)
    {
    case Day::Sunday: os << "13:00"; break;
    case Day::Saturday: os << "17:00"; break;
    case Day::Wednesday: os << "20:00"; break;
    default: os << "18:00"; break;
    }
}