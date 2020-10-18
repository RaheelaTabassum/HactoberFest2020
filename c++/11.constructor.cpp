#include<iostream>
using namespace std;
class Complex
{
private:
    int a,b;
public:
    Complex(void) //constructor overloading //default constructor
    {
        a = 0;
        b = 0;
        return;
    }
    Complex(int x) //constructor overloading //parameterized constructor
    {
        a = x;
        b = 0;
    }
    Complex(Complex &c)
    {
        a = c.a;
        b = c.b;
    }
    Complex(int x, int y) // a constructor; parameterized constructor
    {
        a = x;
        b = y;
        cout << "Hello constructor" << '\n';
    }
    void ShowData()
    {
        std::cout << a << " " << b << '\n';
    }
    // Complex(Complex c) // error
    // {
    //     a=c.a;
    //     b=c.b;
    // }
    
};
int main()
{
    Complex c1(3,4),c2(5),c3; // results in an issue as there is no constructor which thakes no argument
    // Complex c4 = Complex(7,8); // another way of defining c4. Older way not supported
    // Complex c5 = 10; // for passing one argument only. Older way not supported
    Complex c6 = c1;
    c6.ShowData();
    // c5.ShowData();
    // c4.ShowData();
    c3.ShowData();
    c2.ShowData();
    c1.ShowData();
}
