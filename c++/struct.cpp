#include<iostream>
using namespace std;
struct book
{
private:
    char title[20];
    int bookid;
    float salary;
public:
    void input()
    {
        std::cout << "Enter the title, bookid and price of the book respectively:" << '\n';
        std::cin >> title >> bookid >> salary;
        if (bookid<0)
        {
            bookid = -bookid;
        }
    }
    void display()
    {
        std::cout << "Title is " << title << ", bookid is " << bookid << " and salary is " << salary << '\n';
    }
};

int main()
{
    book b1;
    b1.input();
    // if we donot want our data to get corrupted, we can use private, public and protected inside the structure.
    // b1.bookid=-100; should result in an error as the only way to check the input is defined in the input function
    //std::cout << "From main: title is "<<b1.title<<", bookid is "<<b1.bookid<<" and salary is "<<b1.salary<< '\n';
    // after making the attributes private, we are unable to use them outside the structure
    b1.display();
}
