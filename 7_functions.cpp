/*Reuseable block of code 
1.  argument = is used when func is called 
    parameters = when it is defined
2.pass by value and pass by reference
assignment is to build a calculator..


*/
#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    int fact = 1;
    for(int i=1; i<=n;i++){
        fact = fact * i;
    }
    cout<<"factorial(" <<n<<" )"<< fact << endl;
    return fact;
}

bool isPrime(int n){
    if(n==1){
        return false;
    }
    for (int i=2;i<=n-1;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

bool isPrime2(int n){
     if(n==1){
        return false;
    }
    for (int i=2;i*i<=n-1;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int binCoeff(int n, int r){
    int val1 = factorial(n);
    int val2 = factorial(r);
    int val3 = factorial(n-r);

    int result = val1/(val2*val3);
    return result;
}

int main() {
    // factorial(6);
    cout<<isPrime(22)<<endl;
    cout<<isPrime2(2)<<endl;
    cout<<binCoeff(3,2);
return 0; 
}