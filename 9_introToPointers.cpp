/*
1.Decimal(10),Binary(2), Hexadecimal(16)-{a,b,c,d,e,f=10,11,12,13,14,15 resp.}
2.Adress of Operator (&) {also & is used for Bitwise And}
    -"&" gives the address of a variable like &a is 79971 
3.Pointers
    -A special variable that stores address of another variable.
    -int *ptr = &a; here *ptr is storing the address of int type variable a.
    -float *ptr2 = &b; stores address of float no.
    -int **pptr = &ptr; stores address of pointers
4.Deference Operatore 
    -Gets the value of the variable pointed by any pointer.
    - * (used to 1.Multiply 2.declare a pointer 3.derefrence{*(address) gives value store at this})
    -int a =10; declared variable
     int *ptr = &a; declared a pointer
     print *ptr will be equal to 10.
5.Null pointer
    -we assign Null value to a pointer to show that it doesn't point to any location.
    -int *ptr = NULL; stores 0  {segmental fault->Dereferencing null ptr is not possible as it'll result in error}
6.Passing Arguments
    ->Pass by value
        -When parameter is a copy of actual argument variable in memory.
    ->Pass by reference
        -Two ways -- using pointers, using reference variables
        -When we pass the reference of argument to the function.
        -we can make changes in var in main func in func usig ptr
7.Reference Variable
    -Reference variable is an alternate name (alias) of already existing variable.
    -int a=5;
     int &b=a; now a and b refer to the same variable in memory
     if b make changes in itself then it will be reflected on a.
     we need to initialze reference variable without that it is not possible to create it.
     int &b; will give error.

8. Dynamic memory allocator 
    -int *ptr = new int(10); ->it is created through heap
    - delete ptr; -> we need to manually delete it because it can create
9.Dangling Pointer 
    -when we deleted the variable but pointer still refering to that address called dangling pointer
10.Wild Pointer 
    -pointer which is declared but not initialize
*/

#include <bits/stdc++.h>
using namespace std;
void swapNumbers(int x, int y){
    cout<<"Initial Value of A is "<<x<<endl;
    cout<<"Initial Value of B is "<<y<<endl;
    int *ptr1=&y;
    int *ptr2=&x;
    cout<<"Value of A is "<<*ptr1<<endl;
    cout<<"Value of B is "<<*ptr2<<endl;
}
int main() {
 int a = 10;
 int b= 12;
 int *ptr1 = &a;
 int *ptr2 = &b;
 cout<<ptr1<<endl;
 cout<<*ptr1<<endl;
 cout<<sizeof(*ptr1)<<endl;
 swapNumbers(a,b);
int **pptr = &ptr1;
cout<<pptr<<" "<<&ptr1<<endl;
cout<<**pptr<<" "<<*ptr1<<" "<<a<<endl;
return 0; 
}