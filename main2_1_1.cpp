#include <iostream>

/*
		Цифровой счетчик – это целочисленная переменная с ограниченным диапазоном
	значений, которая сбрасывается при достижении максимального значения. При-
	меры использования: цифровые часы, счетчик метров в индикаторе пробега. Опи-
	шите класс для такого счетчика. Предусмотрите возможность установления мини-
	мальных и максимальных значений, увеличения значения счетчика на единицу, воз-
	вращения текущего значения. Напишите программу для проверки работоспособно-
	сти счетчика.
*/



class DigitalCounter {
private:
    int minValue;
    int maxValue;
    int value;

public:
    DigitalCounter(int minVal, int maxVal) : minValue(minVal), maxValue(maxVal), value(minVal) {}

    void increase() {
        if (value == maxValue) {
            value = minValue;
        }
        else {
            value++;
        }
    }

    int getValue() {
        return value;
    }
};

int main() {


    setlocale(LC_ALL, "ru");
    DigitalCounter counter(0, 59); // Создание счетчика с диапазоном от 0 до 59

    std::cout << "Текущее значение счетчика: " << counter.getValue() << std::endl;

    counter.increase();
    std::cout << "Увеличиваем значение счетчика" << std::endl;

    std::cout << "Новое значение счетчика: " << counter.getValue() << std::endl;

    return 0;
}