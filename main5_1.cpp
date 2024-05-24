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

    b.MyName(); // ������� "Base"
    f.MyName(); // ������� "FirstChild"
    s.MyName(); // ������� "SecondChild"

    cout << "-----------------" << endl;

    Base* ptr = &b;
    Base* ptr1 = &f;
    Base* ptr2 = &s;

    ptr->MyName();  // ������� "Base", ���� ���� ��� ��������� Base*
    ptr1->MyName(); // ������� "FirstChild", ���� ���� ��� ��������� Base*
    ptr2->MyName(); // ������� "SecondChild", ���� ���� ��� ��������� Base*

    return 0;
}