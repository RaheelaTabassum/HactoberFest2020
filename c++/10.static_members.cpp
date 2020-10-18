#include<iostream>
using namespace std;
class Account
{
private:
    int balance; //instance member variable
    static float roi; //static member variable, class variable
public:
    void SetBalance(int x)
    {
        balance=x;
    }
    static void SetROI(float x)
    {
        Account::roi = x;
    }
    static void ShowRoi()
    {
        std::cout << "The value of roi is "<<Account::roi << '\n';
    }
};
float Account::roi = 3.5f; //defining the roi outside
int main()
{
    Account a1; // if no oject is made, then also the static variable exists
    // Account::roi = 4.5f; we can do this if the roi is not private
    // we can define a function for this
    Account::ShowRoi();
    Account::SetROI(4.5);
    Account::ShowRoi();
}
