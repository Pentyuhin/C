#include <iostream>
#include <string>
#include <cctype> 


using namespace std;

int find_first_vowel(const string& word);

int main()
{

    setlocale(LC_ALL, "rus");

    string first_word, second_word;

    cout << "Введите первое слово: ";
    getline(cin, first_word);

    cout << "Введите второе слово: ";
    getline(cin, second_word);

    int index1 = find_first_vowel(first_word);
    int index2 = find_first_vowel(second_word);

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
    }
    return -1; // Если гласные буквы не найдены
}