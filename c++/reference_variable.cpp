#include<iostream>
using namespace std;
int main()
{
    int a;
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "The value of a is " << a << '\n';
    int &y=a;
    y++;
    std::cout << "The value of a after using reference variable is " << a << '\n';
    std::cout << "Post-increment " << y++ << '\n';
    std::cout << "Pre-increment " << ++y << '\n';

}
