/*
Calculating tax according to given income

*/

// #include <iostream>
// using namespace std;
// int main()
// {
//     int income;
//     float tax;
//     cout<<"Enter income (in lakhs) :";
//     cin>>income;
//     if(income<5){
//         //0%
//         tax = 0;
//     }
//     else if(income <= 10) {
//         //20%
//         tax = 0.2*income;
//     }
//     // else if(income>=12 && income<=15){
//         //20%
//     else{
//         //30%
//         tax = 0.3*income;
//     }
//     cout<<"Tax = "<<(tax * 100000)<<endl;
//     return 0;
// }

/*
Print the largest of 3 numbers
*/
#include <iostream>
using namespace std;
int main()
{
    int a, b ,c;
    cout<< "Enter a: "<<endl;
    cin>>a;
    cout<< "Enter b: "<<endl;
    cin>>b;
    cout<< "Enter c: "<<endl;
    cin>>c;
    if (a>=b && a>=c){
        cout<<"a is largest";
    }
    else if (b>=c){
        cout<<"b is largest";
    }
    else{
        cout<<"c is largest";
    }
    return 0;
}