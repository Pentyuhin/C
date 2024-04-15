#include <iostream>
#include <algorithm>
#include <windows.h>

using namespace std;

void no_repetitions(char* arr, int size, int& newSize);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 80;
    char charArray[size] = {0};

    int newSize = 0;

    cout << "Введите строку: ";
    cin.getline(charArray, size);

    no_repetitions(charArray, size, newSize);

    // Выводим результат
    cout << "Строка без повторяющихся символов равна: ";
    for (int i = 0; i < newSize; ++i) {
        cout << charArray[i];
    }

    cout << "Эта строка содержит повторяющиеся символы: ";

    for (int i = 0; i < size; ++i) {
        cout << charArray[i];
    }

    return 0;
}


void no_repetitions(char* arr, int size, int& newSize) {
    // Сортируем массив, чтобы соседние повторяющиеся элементы сгруппировались
    sort(arr, arr + size);

    // Удаляем повторяющиеся элементы
    char* newEnd = unique(arr, arr + size);

    // Определяем новый размер массива после удаления повторяющихся элементов
    newSize = newEnd - arr;

}