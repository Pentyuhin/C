#include <fstream>
#include <iostream>
#include <string>
#include <stack>


using namespace std;

void task_1();
void task_2();
void task_3();
void task_4();

int main() 
{
    setlocale(LC_ALL, "ru");

	task_1();
	cout << endl;
	task_2();
    cout << endl;
    task_3();
    cout << endl;
    task_4();
	return 0;
}

// Функция печатающую на экране содержимое собственного исходного файла.
void task_1() 
{

	fstream file;
	char ch = 0;

	file.open("Lecture_4.txt"); // Открываем файл с именем текущего исходного файла

	if (file.fail())
	{
		cout << "Извените, открыть файл не удалось!\n";
	}

	while (file.get(ch))
	{
		cout << ch; // Выводим содержимое файла на экран
	}

	file.close();
}

// Функция копирует все из текущего файла в файл с именем WithoutComments.cpp и на экран, при этом пропуская все комментарии между маркерами /* ... */.
void task_2() 
{
    cout << "Проверка: " << 16 / 2 << " = " << 4 * 2 << ".\n\n";

    ifstream inputFile(__FILE__); // Открываем собственный исходный файл
    ofstream outputFile("WithoutComments.cpp"); // Создаем новый файл для записи

    /*
        test
    */

    if (inputFile.is_open() && outputFile.is_open()) {
        char ch = 0;
        bool inComment = false;

        while (inputFile.get(ch)) {
            if (ch == '/' && inputFile.peek() == '*') {
                inComment = true;
                inputFile.get(); // Пропускаем символ "*"
            }
            else if (inComment && ch == '*' && inputFile.peek() == '/') {
                inComment = false;
                inputFile.get(); // Пропускаем символ "/"
            }
            else if (!inComment) {
                outputFile << ch; // Записываем символ в новый файл
                cout << ch; // Выводим символ на экран
            }
        }

        inputFile.close();
        outputFile.close();
    }
    else {
        cerr << "Ошибка открытия файлов" << endl;
    }
}

/*
    Функция открывает собственный исходный файл, затем считывает символ
    за символом и увеличивает счетчик символов. 
    После завершения чтения файла программа выводит общее количество символов на экран.
*/
void task_3() 
{
    ifstream inputFile(__FILE__); // Открываем собственный исходный файл

    if (inputFile.is_open()) {
        int count = 0;
        char ch;

        while (inputFile.get(ch)) {
            count++;
        }

        cout << "Количество символов в файле: " << count << endl;

        inputFile.close(); // Закрываем файл
    }
    else {
        cerr << "Ошибка открытия файла" << endl;
    }
}


void task_4()
{
    ifstream inputFile(__FILE__); // Открываем собственный исходный файл
    
    if (inputFile.is_open())
    {
        stack<char> charStack;  // Создаем стек для хранения символов
        char ch;

        // Читаем символы из файла и помещаем их в стек
        while(inputFile.get(ch))
        {
            charStack.push(ch);
        }

        // Выводим символы из стека (в обратном порядке)
        while (!charStack.empty())
        {
            cout << charStack.top();
            charStack.pop();
        }

        inputFile.close(); // Закрываем файл

    }
    else
    {
        cerr << "Ошибка открытия файла" << endl;
    }


}