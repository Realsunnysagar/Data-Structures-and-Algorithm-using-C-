/*Literal --> const like 2
variables --> a,b,c(identifier) 

*Naming convention
    1.start with "_" or letter
    2. only contains UC, LC, 0-9 and _
    3. must not be a keyword (reserved words) e.g --> int, float,  return etc

*Data types
    1. primitive 
        simple
        int -- 4 bytes [1byte = 8bits ] ... 4*8=32bits
        char -- 1 byte [kjdsk@#$%]
        bool -- 1byte [true -- 1, false -- 0]
        float -- 4bytes
        double -- 8bytes

    2. Non-primitive
        complex like user defined data types
        eg-String, Array
*Comments
    single line //
    multiline comments

*Inputs in cpp
*avg
    if we divide sum by integer then output will be integer
    

*/ 

#include<iostream>
#define PI 3.14 //Macros --> symbolic constants
#include<iomanip> //--->for setprecision
using namespace std;


int main(){
    cout<<"Let's do it!!\n ";

    // cout<<PI<<endl;
    // int a = 10;
    // int b ; //---->provide a garbage value as no value is assigned
    // cout<<a<<endl<<b<<endl;

    // float pi = 3.14152075648;
    // double pi2 = 3.14152075648;
    // cout<<setprecision(12)<<pi<<endl;
    // cout<<setprecision(12)<<pi2<<endl;

    // int age;
    // cout<<"enter your age";
    // cin>>age;
    // cout<<age;

    // average of marks
    int eng, math, sci;
    cout<<"enter eng marks:";
    cin>>eng;
    cout<<"enter eng marks:";
    cin>>sci;
    cout<<"enter eng marks:";
    cin>>math;
    int avg = (eng + sci + math) / 3;
    cout<<"avg marks ="<<avg<<endl;
    return 0;
} 