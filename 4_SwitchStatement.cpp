/*
#include<iostream>
using namespace std;
int main(){
    int day=3;
    
    switch(day){
        case 1 : cout<<"Monday"<<endl;
            break;
        case 2 : cout<<"Tuesday"<<endl;
            break;
        case 3 : cout<<"Wednesday"<<endl;
            break;
        case 4 : cout<<"Thursday"<<endl;
            break;
        case 5 : cout<<"Friday"<<endl;
            break;
        case 6 : cout<<"Saturday"<<endl;
            break;
        case 7 : cout<<"Sunday"<<endl;
            break;
        default : cout<<"Invalid Day";
    }
}
    */
/*
--Build a calcultor using Switch for the 4 basic arithmetic operator (+,-, *, /)
*/
#include<iostream>
using namespace std;
int main(){
    char op;
    cout<<"Enter operator +,-,*,/"<<endl;
    cin>>op;
    int a, b;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;
    switch(op){
        case '+' : cout<<"a + b = "<<(a+b)<<endl;
            break;
        case '*' : cout<<"a * b = "<<(a*b)<<endl;
            break;
        case '-' : cout<<"a - b = "<<(a-b)<<endl;
            break;
        case '/' : cout<<"a / b = "<<(a/b)<<endl;
            break;
        default : cout << "Invalid Operator";
    }
    return 0;
}