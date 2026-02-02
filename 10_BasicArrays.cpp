/*
1.Arrays 
    -Linear collection of same type of elements that are stored together in contiguous memory spaces.
    -it is a Data structure.
    -index -> position (starts from 0)
2.Creating an array
    -int marks[50]; ->created a memory spaces with 50 int size now having garbage value (index 0 to 49)
    -int marks[50] = {1,2,3}; ->value at rest indices 3 to 49 will be intialized with 0 value.
    -int marks[] = {1,2,3}; ->it will take the size of right side element in this case 3
    -Memory is statically allocated (at compile time not at runime)
    -sizeof(marks) -> will give sum of Bytes of all
    -lenOfArray = sizeof(marks)/sizeof(Int) -> will give length of array
3.Output & Input Array
    -We will use loops for output of an array {loop will run from index 0 to lenOfArray-1}
    -for taking terminal input we will again use loop only in same way using cin
    -for taking lenOfArr as input;
        int n;
        cout<<"Enter the lenOfarr";
        cin>>n;
        int arr[n];
        //Now loop
4.Arrays are passed by reference
    -In Cpp array name -> pointer
    -array_name refer to the address 0th index
    -when we pass arr_name as a argument then it doesnt create copy in func rather pass the address of the variable which is reflected in main func.
    -passing array_name is equal to passing a pointer
    -void printArr(int arr[]){..} or void printArr(int *ptr){..} both is same
    - int nums[] -> this is a pointer as a parameter in func
                ->if we calc size of num then it will give size of pointer which is 8.
                -> therefore we need to give size n as one more parameter in funcn.
                -> void printArr(int nums[], int n) lly in leetcode
5.Linear Search
    -search for key = 10 (say)
    -it will check each index one by one and return the index value for which it has 1st key value
    -Time complexity : relation btw input size(array size) & no. of operations
    -Time complexity -> O(n) {Linear TC}
6.Binary Search
    -Prerequisite : sorted array {like in dictionary ABC..}
    -find mid position mid=(st+end)/2 -> then compare key with mid {==(return), mid<key(2nd half); arr[mid]>key (1st half)}
    -choose one half then calc new mid and compare again
    -if Searching in 2nd half then st=mid+1 or if searching in 1st half then end = mid-1;
    -1st iteration -> n/2^0 . . . .xth iter -> n/2^(x-1) == 1 therefore taking log both side log n = x-1 log2base2=1 ->x=logn
    -gives better time complexity : O(log n)
7.Array Pointer 
    -Array pointer acts like a constant pointer.
    -unlike in normal pointer of variable which may change address.
8.Pointer Arithmetic
    1.Increment & Decrement Operator
        -ptr++ or ++ptr ->it will not just inc 1 but will inc the size of dtype which ptr stores, from original ptr to next
        -ptr-- or --ptr 
    2.Addition & Substraction of Constants
        - ptr+3 -> ptr+[3*int{4B}]=12 spaces skiped
        - ptr-3 -> ptr
    3.Addition & Substraction of Pointers
        - ptr1 + ptr2 //Invalid operator
        - ptr1 - ptr2 //both should be of same type , o/p gives how many integer can be stored in btw these two ptr
    4.Comparison (==,<,<=,>,>=) of ptr
        -if true then o/p = 1

*/

#include <bits/stdc++.h>
using namespace std;
// linear search
int linearSearch(int *arr, int n, int key){     //int *arr == int arr[];
    for(int i=0; i<n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

// Binary Search
int binSearch(int *arr, int n, int key){
    int st = 0; int end = n-1;
    while(st<=end){
        int mid = (st+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){ //2nd half
            st = mid + 1;
        }
        else{
            // 1st half
            end = mid - 1;
        }
    }
    return -1;
}

void printArr(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {

    
    int arr[] = {5,4,3,9,12};
    int n = sizeof(arr)/sizeof(int);
// Reverse an array
// 1.with extra space(just copy paste reversly on another array then overwrite on original arr)
// Can affect space complexity with larger value : space comp -> O(n) and TC : O(n)
    int copyArr[n];
    for(int i=0; i<n; i++){
        int j = n-i-1;
        copyArr[i] = arr[j];
    }
    for(int i=0; i<n; i++){
        arr[i] = copyArr[i];
    }
    printArr(arr,n);

// 2.Without extra space (2 Pointer Approach)
// SC: O(1) and TC : O(n) n/2
    int arr1[] = {5,4,3,9,12};
    int n1 = sizeof(arr1)/sizeof(int);

    int start = 0; int end = n-1;
    while (start<end){
        swap(arr1[start],arr1[end]);
        // int temp = arr1[start];
        // arr1[start] = arr1[end];
        // arr1[end] = temp;
        start++;
        end--;
    }
    printArr(arr1,n1);

//Print largest among the array
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    cout<<"Largest = "<<max<<endl;

    // for minimum
    int min = arr[0];
    for(int i=0; i<n;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    cout<<"Smallest = "<<min<<endl;
    // for sum
    int sum = 0;
    for(int i=0; i<n;i++){
        sum+=arr[i];
    }
    cout<<"Sum = "<<sum<<endl;

    cout<<*arr<<" "<<*(arr+1)<<endl;

    cout<<linearSearch(arr, n, 9)<<endl;
    cout<<binSearch(arr1, n, 5)<<endl;

    
return 0; 
}