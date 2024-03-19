#include <iostream>
#include <windows.h>

using namespace std;

// Функция печатает сообщения, поясняющего назначение программы.
void print_preliminary_message()
{
	cout << "Эта программа печатает значения температур в разных шкалах.\n\n";
}

// Функция запрашивает у пользователя параметры для таблицы с клавиатуры.
double input_table_specifications(double& minTemp, double& maxTemp, double& step)
{
	cout << "Введите минимальную температуру в градусах Цельсия: ";
	cin >> minTemp;

	cout << "Введите максимальную температуру в градусах Цельсия: ";
	cin >> maxTemp;

	cout << "Введите шаг изменения температуры: ";
	cin >> step;

	return minTemp, maxTemp, step;
}

// Функция отображение параметров, введенных пользователем.
void print_message_echoing_input(double minTemp, double maxTemp, double step)
{
	cout << "Температуры в градусах Цельсия: от " << minTemp << " до " << maxTemp << " с шагом " << step << "\n\n";
}

// Функция печатает заголовок таблицы температы.
void print_table()
{
	cout << "\n Таблица преобразования температур: \n";
	cout << "  Цельсий" << "  " << "  Фаренгейт" << "  " << "  Кельвин\n";
}

// Функция возвращает значение температуры по шкале Фаренгейта для переданного значения по шкале Цельсия.
double fahrenheit_of(double& minTemp)
{
	double fahrenheitTemp = 1.8 * minTemp + 32;

	return fahrenheitTemp;
}
// Функция возвращает значение температуры в абсолютной шкале для переданного значения по шкале Цельсия.
double absolute_value_of(double& minTemp)
{
	double kelvinTemp = minTemp + 273.15;

	return kelvinTemp;

}

// Функция выводит значение температуры, температуры в Фаренгейтах и абсолютного значения температуры
void getTemp(double& minTemp, double& maxTemp, double& step)
{

	for (double temp = minTemp; temp <= maxTemp; temp += step)
	{
		// Вывод значений температуры, температуры в Фаренгейтах и абсолютного значения температуры
		cout << "\t" << temp << "\t" << fahrenheit_of(temp) << "\t" << absolute_value_of(temp) << endl;
	}
}