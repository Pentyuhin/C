#include <iostream>

using namespace std;



/*
		Определите класс для дробей – рациональных чисел, являющихся отношением двух
	целых чисел. Напишите функции-члены для сложения, вычитания, умножения и де-
	ления дробей. Определите вариант класса, в котором эти действия оформлены в
	виде перегруженных операторов.

*/



class Fractions
{
	private:
		int a = 0;
		int c = 0;
		int b = 0;
		int d = 0;
		char value = 0;
	

	public:
		Fractions() 
		{
			setNumber();
			fd();
		}

		void setNumber()
		{
			cout << "Функция Калькулятор дробей\n";

			cout << "Введите целое число для числителя первый дроби: ";
			cin >> a;
			cout << "Введите целое число для знаменателя первый дроби: ";
			cin >> c;

			cout << "Введите оператор действия: ";
			cin >> value;

			cout << "Введите целое число для числителя первый дроби: ";
			cin >> b;
			cout << "Введите целое число для знаменателя первый дроби: ";
			cin >> d;
			
		}
		void fd()
		{
			
			switch (value)
			{
			case '+':
			{

				if (c == d)
				{
					int numerator = a + b;
					int denominator = c;
					cout << "\t" << numerator << endl;
					cout << "равно: ----" << endl;
					cout << "\t" << denominator << endl;
				}
				else
				{
					int numerator = a * b + b * c;
					int denominator = c * d;

					cout << "\t" << numerator << endl;
					cout << "равно: ----" << endl;
					cout << "\t" << denominator << endl;

				}
				break;
			}
			case '-':
			{

				if (c == d)
				{
					int numerator = a - b;
					int denominator = c;
					cout << "\t" << numerator << endl;
					cout << "равно: ----" << endl;
					cout << "\t" << denominator << endl;
				}
				else
				{
					int numerator = a * b - b * c;
					int denominator = c * d;

					cout << "\t" << numerator << endl;
					cout << "равно: ----" << endl;
					cout << "\t" << denominator << endl;

				}
				break;
			}
			case '*':
			{

				if (c == d)
				{
					int numerator = a * b;
					int denominator = c * d;
					cout << "\t" << numerator << endl;
					cout << "равно: ----" << endl;
					cout << "\t" << denominator << endl;
				}
				else
				{
					int numerator = a * b / 2;
					int denominator = c * d / 2;

					cout << "\t" << numerator << endl;
					cout << "равно: ----" << endl;
					cout << "\t" << denominator << endl;

				}
				break;
			}
			case '/':
			{

				if (c == d)
				{
					int numerator = a * d;
					int denominator = c * b;
					if (numerator / denominator % 2 == 0)
					{
						int result = numerator / denominator;
						cout << "равно: " << result << endl;
					}
					else
					{
						cout << "\t" << numerator << endl;
						cout << "равно: ----" << endl;
						cout << "\t" << denominator << endl;
					}

				}
				else
				{
					int numerator = a * d;
					int denominator = c * b;

					cout << "\t" << numerator << endl;
					cout << "равно: ----" << endl;
					cout << "\t" << denominator << endl;

				}
				break;
			}

			default:
				cout << "Введен не правильный оператор действия!";
				break;
			}
		}

};

int main()
{
	setlocale(LC_ALL, "ru");
	
	Fractions fb;

	return 0;
}

