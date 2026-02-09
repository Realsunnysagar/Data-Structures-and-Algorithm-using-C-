/*
1.Next Greater Element
    -next greater = first greater element that is to the right
    -arr=[6,8,0,1,3]    ans=[8,-1,1,3,-1]
    -for each element if there is next greater element then write element or return -1
    -this time we will travelling from back to front
    -for 3 -> -1 , 1->3, 0->1, 8->-1(poped all beacause these cant be next greater as all is smaller then 8 and only 8 left), 6->8  =>{8,-1,1,3,-1}
    -
*/
#include <bits/stdc++.h>
using namespace std;

// Next Greater Element
void nextGreater(vector<int> arr, vector<int> ans){
    stack<int> s;
    int  idx = arr.size();
    ans[idx] = -1;
    s.push(arr[idx]);

    for(idx = idx-1; idx>= 0; idx --){
        int curr = arr[idx];
        while(!s.empty() && curr >= s.top()){
            s.pop();
        }

        if(s.empty()){
            ans[idx] = -1;
        }else{
            ans[idx] = s.top();
        }
        s.push(curr);
    }
    for(int i=0; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans = {0, 0, 0, 0, 0};

    nextGreater(arr, ans);
return 0; 
}