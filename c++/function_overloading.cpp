#include<iostream>
float area(int r);
int area(int a,int b);
int main()
{
    int r;
    std::cout << "Enter the radius of the circle" << '\n';
    std::cin >> r;
    std::cout << "Area of the circle is " << area(r) << '\n';
    int l,b;
    std::cout << "Enter length breadth of rectangle" << '\n';
    std::cin >> l>>b;
    std::cout << "Area of the rectangle is " << area(l,b) << '\n';
}

float area(int r)
{
    return 3.14*r*r;
}

int area(int a,int b)
{
    return a*b;
}
