#include <iostream>
#include <string>
#include <cctype> 
#include <windows.h>


using namespace std;

int find_first_vowel(const string& word);
void print_text(int index1, int index2);

void string_comparison(string& first_word, string& second_word);

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    string first_word, second_word;

    cout << "Введите первое слово: ";
    getline(cin, first_word);

    cout << "Введите второе слово: ";
    getline(cin, second_word);

    int index1 = find_first_vowel(first_word);
    int index2 = find_first_vowel(second_word);

    print_text(index1, index2);

    string_comparison (first_word, second_word);

    return 0;
}

int find_first_vowel(const string& word)
{
    for (size_t i = 0; i < word.length(); i++)
    {
        char letter = tolower(word[i]);
        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
        {
            return i;
        }
        if (letter == 'а' || letter == 'и' || letter == 'е' || letter == 'ё' || letter == 'о' || letter == 'у' || letter == 'ы' || letter == 'э' || letter == 'ю' || letter == 'я')
        {
            return i;
        }
    }
    return -1; // Если гласные буквы не найдены
}


void print_text(int index1, int index2)
{


    if (index1 == -1 && index2 == -1)
    {
        cout << "Гласные буквы не найдены в обоих словах." << endl;
    }
    else if (index1 < index2)
    {
        cout << "Первая гласная буква расположена раньше в первом слове, чем во втором." << endl;
    }
    else if (index1 > index2)
    {
        cout << "Первая гласная буква расположена раньше во втором слове, чем в первом." << endl;
    }
    else
    {
        cout << "Первые гласные буквы в обоих словах расположены на одной и той же позиции." << endl;
    }

}

void string_comparison(string& first_word, string& second_word)
{
    int i = 0;
    int j = 0;

    for (; i < first_word.length(); i++);

    for (; j < second_word.length(); j++);


    if (i > j)
    {
        cout << first_word << " больше чем " << second_word;
    }
    else if (i < j)
    {
        cout << first_word << " меньше чем " << second_word;
    }
    else
    {
        cout << second_word << " равны " << first_word;
    }

}