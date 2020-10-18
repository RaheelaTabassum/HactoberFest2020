#include<iostream>
float sum(float a)
{
    return a;
}
float sum(float a,float b=0)
{
    return a+5+7; //results in errors
}
// float sum(float a)
// {
//     return a;
// }
int main()
{
    char a,b;
    std::cout << "Enter value of a: ";
    std::cin >> a;
    std::cout << sum(a) << '\n';
}
