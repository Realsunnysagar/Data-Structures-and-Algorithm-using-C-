/*
Bit Manipulation
1.Bitwise Operator
    I. Bitwise AND ( & ) -> 0&1 gives 0, 0&0 gives 0, 1&0 gives 0, 1&1 gives 1
    II.Bitwise OR ( | ) -> 0|0 -> 0, 0|1 -> 1, 1|0->1, 1|1->1
    III. Bitwise XOR or exclusive OR ( ^ ) -> 0^0 = 0, 1^1=0, 0^1=1, 1^0=1 {same ->0, different = 1}
2.One's Complement
    -Binary NOT Operator -> ~(tilde)
    -~0 ->1 , ~1->0 (here 0 and 1 is one Bit)
    -~6 -> 0 0 0 0 0 1 1 0 -> -7
    - 1 1 1 1 1 0 0 1 -> MSB is 1 therefore -ve no.
    - if MSB = 0(+ve) , MSB = 1(-ve)
    - 1. one's compliment -> 0 0 0 0 1 1 0
    - 2. add 1 -> 0 0 0 0 1 1 1  = (7) base 10 this is magnitude and sign is -VE seen above 
    - therefore ~6 = - 7 , this 2 steps including known as 2's compliment and its only for mathematical understanding value of the no. 11111001 
    - in program -ve n0. are stored in the form 2's compliment
    - ~0(8 bits) = -1
3.Binary Shift Operators
    1.Left Shift (<<)
        - num << i position like 7<<2
        - 00000111 we have to do 2 times lefft shift
        - 1st - 00001110 , 2nd- 00011100 = (28) b10
        - shortcut if leftshift by 2 then cut 2 0's from left and write at right
        - or a << b => a * 2 pow b like 7 * 2 pow2
    2.Right Shift (>>)
        - 7 >> 2
        - 00000111 -> 1st 00000011 -> 2nd 00000001 i.e 1
        - removing element form the right and adding the zero's in left
        - a >> b -> a / 2 pow b -> 7/4pow1 => 1
4.Check if Odd or Even using bitMan
    - what we observe that : ODD - right most bit is 1, EVEN - right most bit is 0 {last bit 2 pow 0 is 1 which contribute to odd}
    - 15(00001111) just check last bit and for that we will use Bit mask
    - We are going to make all the rest bit 0 except the last bit, and if it is 1 then odd and 0 then even
    - For that we will use 'AND' operator between the num and 1 (00000001) and if final o/p is 0 then even and if 1 then odd
    - Bit masks are used to access specific bits in a byte of data. like we figureout 00000001
    - In ques of Bitmasking we need to figure out smth like this  
5.Get ith Bit
    - num = 6, i = 2,  00000 1 10 -> here we need to find that ith bit which is 1 in this case 
    - so we need to think that what bitmasking we should apply
    - bitmask = 00000100 therefore we will have 1 at ith position and will use 'AND' operator
    - but i can be anything, therefore we will use mask = 1 << i
    - if nums is 0 then ith having 0 bit and if mask > 0 then ith position having bit 1
6.Set ith Bit
    - converting to 1 like if 0->1 and if 1->1
    - num = 6, i = 3;  0 0 110 therefore to make that 0 to 1 we will take 'OR' operation with 01000
    - If we will take OR then there will be no change on other position 
    - that will become 01110 = 14
    - num | 1 << i
7.Clear ith Bit
    - that means 0 -> 0 and if 1 -> then 0 
    - clearing 1 to 0
    - num = 6, i = 1; 0110 -> 0100 (4) we have cleared the ith bit to 0
    - for clearing to the ith term we need to take 'AND' operator for that position
    - Bitmask - 111011 0 at ith then taking not = 000100 => 1<<i
    - mask = ~(1 << i)
8.Check for Power of 2
    - check if a no. is in power of 2 like 2(10),4(100),8(1000),16(10000),32(100000) ...etc 
    - there is common in it that position of 2 power is having 1 and rest is 0 like in 8 2pow3 is 1 rest 000
    - there is another thing that if those (num - 1) are 1(1) ,3(11) ,7(111) ,15(1111) ,31(11111) ...etc
    - 3rd observation is taking 'AND' of num 'AND' (num-1) is 0
    - like 16(10000) & 15(01111) = 00000
    - therefore if it comes 0 then it is a power of 2 and if not equal to 0 then its not power of 2
9.Count Set Bits
    - num = 10
    - to count the sum of all the binary 1 that will be the count
    - 1.last digit of binary form (odd/even already did)
    - 2.num >> 1; 
    - repeat all this two steps till num becomes 0
10. Fast Exxponential   {google, amazon}
    - X pow n => x*x*x* ...n here TC: O(n)
    - using bit manipulation we can solve it O(log n)
    - X pow n -> we will take n's binary form and for each bit we will multiply with X pow1 , X pow 2, X pow 4 , X pow 8 . . .{power will be 2times}
    - like 3 pow 5 -> binary of 5 - 1 0 1 and for each bit starting from right mult. with 3pow1, 3pow2, 3pow4
    - int ans = 1; therefore ans = 1*3pow1*3pow4 = 3pow5 {we will skip 3 pow 2 because at 2nd pos bit is 0 so 0*3pow2 = 0}
    - loop will work for binary form of pow(n) times : n -> log n
    - 1. ans = 1, (n) 5 -> 101 ; x = 3
        if last bit is 1 then ans = ans * x = 3, x = x*x = 3pow2 = 9
    -2. x = x*x = 3pow2 * 3pow2 = 3 pow4 = 81
    -3. ans = ans*x : 3*81 = 243
    - we had these 3 iteration rather than 5 iteration in this case
    */
#include <bits/stdc++.h>
using namespace std;

//Odd or Even using bit masking
void oddOrEven(int num){
    if(!(num & 1)){
        cout<<"Even\n";
    }else{
        cout<<"Odd\n";
    }
}

//Get ith Bit of a no.
int getIthBit(int num, int i){
    int bitMask = 1 << i;

    if(!(num & bitMask)){
        return 0;
    }else{
        return 1;
    }
}

// Set ith Bit in a no.
int setIthBit(int num , int i){
    int bitMask = 1 << i;
    return (num | bitMask);
}

// Clear ith Bit
int clearIthBit(int num, int i){
    int bitMask = ~(1 << i);
    return num & bitMask;
}

//Check if no. is power of 2
bool isPowerOf2(int num){
    if(!(num & (num-1))){
        return true;
    }
    else{
        return false;
    }
}

//Ques: WAF to update the ith bit in a number according to given value (0 or 1)
// num = 7, i = 2 , val = 0;
// num = 7, i = 3 , val = 1;
// 1. clear the ith bit 2. num | (val << i)
void updateIthBit(int num, int i, int val){
    num = num & ~(1 << i);

    num = num | (val << i);

    cout<< num << endl;
}
/* Ques: WAF to clear last i bits of a number (means clearing  bits to zero from right of i size)
num = 15, i = 2;
1.will use and operation 
2. mask : ~0<<i because ~0 = -1 = 11111111 left shifting it will put required zero in right
3. num = num & (~0 << i)
*/
void clearIBits(int num, int i){
    int bitMask = (~0) << i;
    num = num & bitMask;

    cout << num <<endl;
}

// Count Set Bit
int countSetBits(int num){
    int count = 0;

    while (num>0){
        int lastDigit = num & 1;
        count += lastDigit;

        num = num >> 1;
    }
    cout<<count<<endl;
    return count;
}

// Fast Exponential (google and amazon)
void fastExpo(int x, int n){
    int ans = 1;
    while(n>0){
        int lastBit = n & 1;
        if(lastBit){
            ans = ans * x;
        }
        x = x * x;
        n = n >> 1;
    }
    cout<<ans<<endl;
}

int main() {
    // Bitwise Operator
    cout<<(3 & 5)<<endl;
    cout<<(~6)<<endl;

    oddOrEven(5);
    oddOrEven(6);

    cout<<getIthBit(7,1)<<endl;
    cout<<setIthBit(6,3)<<endl;
    cout<<clearIthBit(6,1)<<endl;
     
    cout<<isPowerOf2(4)<<endl;
    cout<<isPowerOf2(16)<<endl;
    cout<<isPowerOf2(13)<<endl;

    updateIthBit(7,2,0);
    updateIthBit(7,3,1);

    clearIBits(15,2);

    countSetBits(10);

    fastExpo(3,5);

 
return 0; 
}