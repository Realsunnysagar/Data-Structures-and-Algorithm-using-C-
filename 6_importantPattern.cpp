// check notes for clarity
/*
Continue - will skip the below part 
Break- will terminate upto that
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    for(int i=1; i<=6;i++){
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
        
    for(int i=1; i<=6; i++){
        for(int j=1; j<=i; j++){
            cout<<i;
        }
        cout<<endl;
    }

    for(int i=1; i<=5; i++){
        char ch = 'A';
        for(int j=1; j<=i; j++){
            cout<<ch; 
            ch++;
            // cout<<(char)('A' + j); using type conversion here initislize i and j from 0
        }
        cout<<endl;
    }

    for(int i=1; i<=4;i++){
        for(int j=1; j<=4 ; j++){
            cout<<'*'<<" ";
        }
        cout<<endl;
    }
//Floyd's Triangle
    int num=1;
    for(int i=1; i<=4; i++){
        for(int j=1; j<=i; j++){
            cout<<num++<<" ";
        }
        cout<<endl;
    }


return 0; 
}