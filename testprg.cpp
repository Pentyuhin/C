#include <iostream>
#include "queen.h"

int main() {

    setlocale(LC_ALL, "ru");
    Queen q;
    q.solve();
    q.printSolutions();
    q.saveSolutionsToFile("solutions.txt");
    return 0;
}