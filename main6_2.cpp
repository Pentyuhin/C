#include <iostream>
#include <cstring>

#include <windows.h> 
using namespace std;

char minimum_from(char b[], int position, int length)
{
    int min_index = position;
    for (int count = position + 1; count < length; count++)
        if (b[count] < b[min_index])
            min_index = count;
    return min_index;
}

void selection_sort(char b[], int length)
{
    for (int count = 0; count < length - 1; count++)
        swap(b[count], b[minimum_from(b, count, length)]);
}

void swap(char& first, char& second)
{
    char temp = first;
    first = second;
    second = temp;
}

void string_sort(char b[])
{
    int length = strlen(b);
    selection_sort(b, length);
}

int main()
{

     SetConsoleCP(1251);
     SetConsoleOutputCP(1251);

    const int MAX_LENGTH = 80;
    char b[MAX_LENGTH] = {};

    cout << "Введите тестовую строку для сортировки: ";
    cin.getline(b, MAX_LENGTH);

    string_sort(b);

    cout << "Отсортированная строка равна: " << b;

    return 0;
}