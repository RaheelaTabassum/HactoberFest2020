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
    void ShowData();
};
void Complex::ShowData()
{
    std::cout << a<<"  "<<b << '\n';
}

int main()
{
    Complex c1;
    c1.SetData(3,5);
    c1.ShowData();
}
