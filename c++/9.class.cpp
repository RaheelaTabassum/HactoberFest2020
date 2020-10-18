#include<iostream>
using namespace std;
class Complex
{
private:
    int a,b;
public:
    void SetData(int x,int y)
    {
        a = x;
        b = y;
    }
    void ShowData()
    {
        std::cout << a<<"  "<<b << '\n';
    }
    void Add(Complex c1, Complex c2)
    {
        a = c1.a+c2.a;
        b = c1.b+c2.b;
    }
};

int main()
{
    Complex c1,c2,c3;
    c1.SetData(3,10);
    c2.SetData(4,9);
    c3.Add(c1,c2);
    c3.ShowData();
}
