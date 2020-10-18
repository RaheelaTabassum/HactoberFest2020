#include<iostream>
using namespace std;
inline void fun();
inline int sum(int );
int main()
{
    fun();
    std::cout << "You are in main" << '\n';
    std::cout << "Enter a number: ";
    int n;
    std::cin >> n;
    std::cout << "The sum of first " << n << " natural numbers is "<< sum(n) <<'\n';
}

void fun()
{
    std::cout << "You are in fun" << '\n';
}

int sum(int n)
{
    int s=0;
    for(int i=0;i<n;i++)
    {
        s+=i;
    }
    return s;
}
