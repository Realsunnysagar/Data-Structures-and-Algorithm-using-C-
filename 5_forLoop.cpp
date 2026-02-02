/*
For loop
    -> Just to repeat some task we use it
    -> It is of 3 type for, do and while we can use any of these in any question. 
    -> for (initialisation; condition; updation){
     //do some work
     }
    -> infinite loop make sure this condition should not occur. 
    -> iterate(run) , iteration(single run), iterator(loop's variable/counter varialbe like i, j , num ...)


*/
// #include<iostream>
// using namespace std;

// int main(){
//     int num;
//     for (num =1; num<=5;num++ ){
//         cout<<num<<endl;
//     }
//     cout<<"The last no. is "<<num<<endl; //6
// }

/* Print sum of 1st n natural number*/
#include<iostream>
using namespace std;
int main(){
    int n; 
    cout<<"Enter a number"<<endl;
    cin>>n;
    int sum=0;
    for(int i=1; i<=n; i++){
        sum += i;
    }
    cout<<"Sum is: "<<sum<<endl;
    return 0;
}