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

// ������� ���������� �� ������ ���������� ������������ ��������� �����.
void task_1() 
{

	fstream file;
	char ch = 0;

	file.open("Lecture_4.txt"); // ��������� ���� � ������ �������� ��������� �����

	if (file.fail())
	{
		cout << "��������, ������� ���� �� �������!\n";
	}

	while (file.get(ch))
	{
		cout << ch; // ������� ���������� ����� �� �����
	}

	file.close();
}

// ������� �������� ��� �� �������� ����� � ���� � ������ WithoutComments.cpp � �� �����, ��� ���� ��������� ��� ����������� ����� ��������� /* ... */.
void task_2() 
{
    cout << "��������: " << 16 / 2 << " = " << 4 * 2 << ".\n\n";

    ifstream inputFile(__FILE__); // ��������� ����������� �������� ����
    ofstream outputFile("WithoutComments.cpp"); // ������� ����� ���� ��� ������

    /*
        test
    */

    if (inputFile.is_open() && outputFile.is_open()) {
        char ch = 0;
        bool inComment = false;

        while (inputFile.get(ch)) {
            if (ch == '/' && inputFile.peek() == '*') {
                inComment = true;
                inputFile.get(); // ���������� ������ "*"
            }
            else if (inComment && ch == '*' && inputFile.peek() == '/') {
                inComment = false;
                inputFile.get(); // ���������� ������ "/"
            }
            else if (!inComment) {
                outputFile << ch; // ���������� ������ � ����� ����
                cout << ch; // ������� ������ �� �����
            }
        }

        inputFile.close();
        outputFile.close();
    }
    else {
        cerr << "������ �������� ������" << endl;
    }
}

/*
    ������� ��������� ����������� �������� ����, ����� ��������� ������
    �� �������� � ����������� ������� ��������. 
    ����� ���������� ������ ����� ��������� ������� ����� ���������� �������� �� �����.
*/
void task_3() 
{
    ifstream inputFile(__FILE__); // ��������� ����������� �������� ����

    if (inputFile.is_open()) {
        int count = 0;
        char ch;

        while (inputFile.get(ch)) {
            count++;
        }

        cout << "���������� �������� � �����: " << count << endl;

        inputFile.close(); // ��������� ����
    }
    else {
        cerr << "������ �������� �����" << endl;
    }
}


void task_4()
{
    ifstream inputFile(__FILE__); // ��������� ����������� �������� ����
    
    if (inputFile.is_open())
    {
        stack<char> charStack;  // ������� ���� ��� �������� ��������
        char ch;

        // ������ ������� �� ����� � �������� �� � ����
        while(inputFile.get(ch))
        {
            charStack.push(ch);
        }

        // ������� ������� �� ����� (� �������� �������)
        while (!charStack.empty())
        {
            cout << charStack.top();
            charStack.pop();
        }

        inputFile.close(); // ��������� ����

    }
    else
    {
        cerr << "������ �������� �����" << endl;
    }


}