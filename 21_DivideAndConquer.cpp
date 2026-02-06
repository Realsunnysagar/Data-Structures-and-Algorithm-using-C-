/*
Divide and Conquer
    -A recursive algorithm
    -just dividing the big problem into small and solution of small will be collected together to find ans 
1.Merge Sort
    -TC: O(n log n)
    -arr[] - {6,3,7,5,2,4}
    -1.Divide from the mid - left part and right part
    -left(6,3,7) and right(5,2,4)
    -2.mergeSort(left)
       mergeSort(right) ->just call recursively on both the half
    -further left -{6,3}{7} and right-{5,2}{4} here 7,4 hit the base case and cant be divided further
    -{6}{3}  {5}{2} base cases
    -3.merge(  )
    -Merge/Combine Step 
        -we will assume that mergeSort will give me sorted {3,6,7} and {2,4,5}
        -temp of size 6, i.e left(si,mid) i + right(mid+1, ei) j
        - temp{2,3,4,5,6}   compare i and j in both half and fill this temp
        - finally it will be copied to original array
        - Space Complexity : O(n) because we required another n spaces to sort
    - ms(arr, si, ei){
        if(si>=ei)
            return
        mid = (si+ei)/2;
        ms(arr,si,mid) //left
        ms(arr, mid+1, ei) //right
        merge(arr,si,ei,mid)
     }
     merge(arr,si,ei,mid){
        vector<int> 
        i = si  //left
        j = mid + 1  //right
        while(i<=mid && j<= ei){
            arr[i], arr[j] ->vector
        }
     copy vector to original array
       }
2.Quick Sort
    - arr[] = {6,3,7,5,2,4}
    - 
*/
#include <bits/stdc++.h>
using namespace std;

// Merge Sort Algorithm
void merge(int arr[], int si, int mid, int ei){ //O(n)
    vector<int> temp;
    int i = si;
    int j = mid + 1;

    while (i<= mid && j<=ei){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        } else{
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= ei){
        temp.push_back(arr[j++]);
    }
    // vector -> orginal arr
    for(int idx = si, x=0; idx<=ei; idx++){ //org arr
        arr[idx] = temp[x++];
    }
}

void mergeSort(int arr[], int si, int ei){
    if(si >= ei) return;

    int mid = si + (ei-si)/2;

    mergeSort(arr,si,mid);  //left half
    mergeSort(arr,mid+1, ei);//right half

    merge(arr, si, mid, ei); // conquer
}

//Quick Sort 


void printArr(int arr[], int n){
    for(int i = 0; i< n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main() {

    int arr[6] = {6,3,7,5,2,4};
    int n = 6;

    mergeSort(arr, 0, n-1);
    printArr(arr,n);
    
return 0; 
}