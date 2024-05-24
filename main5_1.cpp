#include <iostream>
using namespace std;

class Base {
public:
    virtual void MyName() { cout << "Base\n"; }
};

class FirstChild : public Base {
public:
    void MyName() override { cout << "FirstChild\n"; }
};

class SecondChild : public Base {
public:
    void MyName() override { cout << "SecondChild\n"; }
};

int main() {
    Base b;
    FirstChild f;
    SecondChild s;

    b.MyName(); // Выводит "Base"
    f.MyName(); // Выводит "FirstChild"
    s.MyName(); // Выводит "SecondChild"

    cout << "-----------------" << endl;

    Base* ptr = &b;
    Base* ptr1 = &f;
    Base* ptr2 = &s;

    ptr->MyName();  // Выводит "Base", даже если тип указателя Base*
    ptr1->MyName(); // Выводит "FirstChild", даже если тип указателя Base*
    ptr2->MyName(); // Выводит "SecondChild", даже если тип указателя Base*

    return 0;
}