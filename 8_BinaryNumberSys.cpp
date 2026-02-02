/*
1.Binary Number system
    Decimal no. - 0 to 9
    Binary no. - 0 and 1 -> bits also helps in bits manupulation chapter.
    532= 5*100 + 3*10 + 2*1
2.binary to decimal
    just do it with 2^smth (101 = 1*2^2 + 0*2^1 + 1*2^0) = 5
    can be written as (5)base10 = (101)base2

3.Decimal to binary
    -we need to divide the no. by 2 and need to note the rem
    -like for 18 rems will be 01001 therefore writting it in bottom to top
     we will get 10010 is ans
    -backward arrangement of remainder is the decimal of that binary

4.Data Type Modifiers
    -After the meaning of existing data types.
    -int(4bytes = 32bits) -> -2^31 to 2^31-1 {half -ve and half+ve 2^32/2 = 2^31}
    -long >= int
     short 2bytes
     signed -> same int is same as int
                MSB(most significant bit)_ _ _ _LSB
     unsigned -> can only store non-negative numbers like age etc
                -> unsigned short int age;
5. 

*/

#include <bits/stdc++.h>
using namespace std;

// binary to decimal
void binToDec(int binNum){
    int n = binNum;
    int decNum = 0;
    int pow = 1; //2^0 2^1 2^2 ...

    while(n > 0){
        int lastDig = n % 10;
        decNum += lastDig*pow;
        pow = pow*2;
        n = n/10;
    }

    cout << decNum << endl;
}

//decimal to binary
void dectoBin(int decNum){
    int n = decNum;
    int pow = 1;
    int binNum = 0;

    while(n > 0){
        int rem = n % 2;
        binNum += rem*pow;
        n = n/2;
        pow = pow*10;
    }   
    cout<< binNum <<endl;
}

int main() {
 cout<<sizeof(int)<<endl;
 cout<<sizeof(long)<<endl;
//convert binary to decimal
binToDec(1010);
dectoBin(5);
return 0; 
}