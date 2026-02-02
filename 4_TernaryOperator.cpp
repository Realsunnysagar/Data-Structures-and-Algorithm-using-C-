/*
1.Ternary Operator
    variable = conition? statement1 : statement2;
    -All the work can be done using if-else but to make it short we use this one.
    -
*/
#include<iostream>
using namespace std;

int main(){
    bool isAdult;
    int age;
    cout <<"Enter age: ";
    cin>>age;
    isAdult = age >= 18 ? true : false;
    return 0;
}
