#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    stack<int> s;
    for(int i = 0; i< n; i++){
        if(arr[i] % 2 == 0)
            s.push(arr[i]);
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

return 0; 
}