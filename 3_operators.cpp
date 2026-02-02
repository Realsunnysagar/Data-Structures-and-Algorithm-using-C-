/*
1.Constant
    *variables that cannot be changed.
    *must be initialized.
    eg--> const int n = 25;
    *macro and constant is diff, macro doesnot occupy memory space
      whereas const occupy memory.
    *macros is also used to create a symbolic shortcut like 
        #define ll long long

2.Typecasting 
    Conversion of data from one type to another.
    *Types---->Implicit Conversion(automatic / type promotion)
                    *Done by compiler to avoid data loss. 
                    bool -> char -> int -> float -> double 

        ------>explicit conversion (forced by programmer)
3. Operators
    I. Arithmetic Operator
        a. Binary(needs two operands)
            +,-,*,/ (divide), %(modulo)
        b. Unary 
            increment(++), decrement(--)
            *it can be post (a++) or pre (++a)
    II. Assignment Operator
        = , +=, -=, *=, /=
    III. Relational Operator
        ==,<=,>=,<,>,!=
    IV. Logical Operator
        and(&&), or(||), Not(!)
            
*/
#include <iostream>
using namespace std;
int main(){

const float PI = 3.14;

// Implicit 
cout<<(10/3)<<endl; //3
cout<<(10/3.0)<<endl; //3.3333 double
cout<<(23.5+2+'A')<<endl; //return double value bcoz it has high priority

// Explicit
cout<<(int)('A')<<endl;
cout<<(int)(PI)<<endl;
cout<<(char)('A'+1)<<endl;
cout<<((bool)3+2)<<endl; //-->(bool)[any no.] always gives 1 and (bool)0 gives 0

//Arithmetic operator
// Binary
int a =5;
int b= 3;
cout<<"+ "<<(a+b)<<endl;
cout<<"- "<<(a-b)<<endl;
cout<<"* "<<(a*b)<<endl;
cout<<"/ "<<(a/b)<<endl;
cout<<"% "<<(a%b)<<endl;
// unary AO
a++; //a = a+1
b--; // b = b - 1
cout<<a<<endl;
cout<<b<<endl;

// Assignment Operator
a *= 5;
cout<<a<<endl;
 
}  
