#include<iostream>
int sum(int a,int=0,int=0);
int main()
{
    int a,b;
    std::cout << "Enter two numbers" << '\n';
    std::cin >> a>>b;
    std::cout << sum(a,b) << '\n';
    int c;
    std::cout << "Enter three numbers" << '\n';
    std::cin >> a >> b >> c;
    std::cout << sum(a,b,c) << '\n';
}

int sum(int a,int b,int z)
{
    return (a+b+z);
}
