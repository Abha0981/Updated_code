#include <iostream>
using namespace std;

void func1(int a, int b)
{
    swap(a, b);
    cout << a << " " << b << endl;
}

void func2(int &a, int &b)
{
    a = a + b;
    b = b - a;
    cout << a << " " << b << endl;
}

int main()
{
    int a = 34;
    int b = 456;

    cout << a << " ";
    cout << b << endl;
    func1(a, b);
    func2(a, b);
    cout << a << " ";
    cout << b << endl;
    return 0;
}