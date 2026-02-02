/*
1.Bubble Sort
    -Idea: large elements come to end by swapping with adjacents
    -[5,4,1,3,2] 54321 
    -we will just swap the largest element to the last
    -every element will be checked in turns(iteration)
    -[4,1,3,2,5] runs ntimes -> [1,3,2,4,5] runs n-1 times -> [1,2,3,4,5]  -> [1,2,3,4,5] 4th turn compares 1 and 2
    -it takes n-1 turns to sort 
    -Time complexity: O(n^2)
2.Selection Sort 
    -Idea : pick the smallest (from unsorted ) & put it in the beginning
    -[5,4,1,3,2]
    -TC : O(n^2)
3.Insertion Sort 
    Idea : pick an element form unsorted part & place it correctly in sorted part
    -TC: O(n^2)
4.Counting Sort
    Idea : use a frequency count of elements from min to max.
    -used when min<-->max range is low; and for +ve numbers
    -TC : O(n+range)
5.Inbuilt Sort
    -TC : O(nlogn)
    -Ascending Order
        -sort(start,end) ->start and end are iterators
    -Descending Order
        -sort(start, end, greater<int>()) -> 3 parameters 
*/

#include <bits/stdc++.h>
using namespace std;

void print(int *arr, int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// Bubble Sort
void bubbleSort(int arr[], int n){
    for (int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){      //if you want array in reverse order then just change > to <
                swap(arr[j],arr[j+1]);
            }
        }
    }
    print(arr,n);
}

// Selection Sort
void selectionSort(int arr[], int n){

    for (int i=0; i<n-1; i++){
        int minIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIdx]){ //if you want it descending order then change < to >
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    print(arr,n);
}

// Insertion Sort
void insertionSort(int arr[], int n){
    
    for(int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] > curr){ // for getting array in descending order just change > to <
            swap(arr[prev], arr[prev+1]);
            prev--;
        } 
        arr[prev+1] = curr;
    }
    print(arr, n);
}

// Counting Sort 
void countSort(int arr[], int n){
    int freq[100000]; //range 
    int minVal = INT_MAX, maxVal = INT_MIN;
    for(int i=0; i<n; i++){
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }
    // 1st Step - O(n)
    for (int i = 0; i<n; i++){
        freq[arr[i]]++;
    }
    // 2nd step -O(range) = max-min
    for(int i=minVal, j=0; i<=maxVal; i++){
        while(freq[i]>0){
            arr[j++] = i;
            freq[i]--;
        }
    }
    print(arr, n);
}

int main() {
 
    int arr[5] = {5,4,1,3,2};
    bubbleSort(arr,5);
    selectionSort(arr,5);
    insertionSort(arr, 5);

    int arr1[8] = {1,4,1,3,2,4,3,7};
    countSort(arr1,8);

return 0; 
}