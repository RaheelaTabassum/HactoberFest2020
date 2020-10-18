#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number:" << ' ';
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cout << a[i] << ' ';
        sum+=a[i];
    }
    cout << endl;
    cout << "The sum of all the elements of the loop is " << sum <<endl;
}
