/*
1. If else

*/
#include <iostream>
using namespace std;
int main()
{
    int age;
    cout << "Enter your age";
    cin >> age;
    if (age >= 18)
    {
        cout << "can vote";
    }
    else
    {
        cout << "CANNOT   vote";
    }
    return 0;
}