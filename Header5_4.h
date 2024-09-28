#ifndef HEADER_H
#define HEADER_H

#include <iostream>

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

void shop_day();
void print_day(Day day, std::ostream& os);
void closing_time(Day day_of_the_week, std::ostream& os);

#endif