/*
1. Print Subarrays
    -Subarray is continous part of an array
    -ex:[1,2,3,4,5] , subarray->{1,12,123,1234,12345,2,23,234,2345,3,34,345,4,45,5 are the subarrays}
    -Subsequence(non-continuous) like 1,3,5
    -for subarrays n=5 15subarr, n=4 10subarr, therefore for n element n(n+1)/2;
    -Printing all subarr -> O(n^3) {using string can be O(n^2)}
2.Max Subarray Sum 
    -Can be tricky with negative elment in array so this
    -Brute Force Approach or optimize it
    -kadane's approach (DP)
    -calculate the sum of all subarrays
    -INT_MIN {initialise int max variable from it because it is smallest possible value in 4B value (-infinity) predefined macros}
    -INT_MAX {lly initialise min var with this because it is the max value possible in cpp(+infinity)}
*3.Kadane's Algorithm (DP) -> O(n)
    -two no.s 3 condition
        1. +ve + +ve -> +ve(currSum)
        2. -ve + +ve -> +ve(currSum)
        3. -ve + +ve -> -ve(currSum)
    -1 loop, 2 var currSum and maxSum, 
4.Buy & Sell Stocks
    -prices = [7,1,5,3,6,4] and indices 012345 are days
    -buy some stock on any day and sell it in next or another day, calc profit or loss
    -return maximum profit
    -eachday = sell day -> best buy -->min(i=0 to sellday-1)
5.Trapping Rainwater
    -height = [4,2,0,6,3,2,5], every bar >= zero ,, ans->11
    -Find amount of water trapped.
    -bar needs a valley to trap water i.e. larger bars on both sides 
    -min of (left largest & right largest) bars gives trapped water
    -water will be trapped only when n>3 i.e atleast 3 bar required
    -decending, ascending order doesn't store water there must be a pocket
    -traped area height*width
    -Auxiliary Arrays
    -for each bar we need to check maximum bar in left and maximum bar in right among those 2 bar the one which is smallest will decide the height 
    -left_max = [-inf,4,4,6,6,6] -> for ith, left_max[i] = max(leftMax[i-1], height[i-1])
    -right_max = [6,6,6,5,5,5,-inf] ->for this we will start form the right side of the array
    -therfore min = [-inf,4,4,4,5,5,-inf] 
    -(min - height[i]) -> water trapped
    -[-inf,2,4,-2,2,3,-inf ] ignore -ve and replace it by zero
    -[o,2,4,0,2,3.0] amount of water traped btw bar so calc the sum for totalwater traped
    -* In maths -inf-4 -> -ve value but in cpp INT_MIN - 4 -> +ve value(dur to bit manipulation)
    - we can solve it and buy thorugh stacks 
*/
/*
class
1.Sliding Window
    1.Fixed size Window
        -{1,2,3,4,5} -> Maximum sum of subarr with window size 3
        -it will take arrays like 1,2,3 ; 2,3,4; 3,4,5
    2.Variable size window
        -

*/
#include <bits/stdc++.h>
using namespace std;


void printSubarrays(int *arr, int n){
    for(int start=0; start < n; start++){
        for(int end = start; end<n; end++){
        // cout<<"{"<<start<<","<<end<<"} "; //  print the pair of starting and ending indexes of Subarrays
        for(int i=start; i<=end;i++){
            cout<<arr[i];
        }
        cout<<", ";
        }
        cout<<endl;
    }
}

void maxSubarraySum1(int *arr, int n){//O(n^3)
    int maxSum= INT_MIN;
    for(int start=0; start<n; start++){
        for(int end=start; end<n; end++){
            int currSum = 0;
            for(int i=start; i<=end; i++){
                currSum += arr[i];
            }
            cout<<currSum<<",";
            maxSum = max(maxSum, currSum);
        }
        cout<<endl; 
    }
    cout<<"Maximum Subarray Sum: "<<maxSum<<endl;
}

void maxSubarraySum2(int *arr, int n){      //O(n^2)
    int maxSum= INT_MIN;
    for(int start=0; start<n; start++){     //start = 2
        int currSum = 0;
        for(int end=start; end<n; end++){   //end = 2,3,4,5
            currSum += arr[end];
            // cout<<currSum<<",";
            maxSum = max(maxSum, currSum);
        }
    }
    cout<<"Maximum Subarray Sum: "<<maxSum<<endl;
}

//Kadane's Algorithm
void maxSubarraySum3(int *arr, int n){
    int maxSum= INT_MIN;
    int currSum=0;
    for(int i=0; i<n; i++){
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if(currSum < 0){
            currSum = 0;
        }
    }
    cout << "maximum subarray sum using Kadane's Algo ="<<maxSum<<endl;
}    


// Buy and Sell stocks 
void maxProfit(int *prices, int n){
    int bestBuy[100000];
    bestBuy[0] = INT_MAX;
    // cout<<bestBuy[0]<<","; //o/p +infinity
    for(int i=1;i<n;i++){
        bestBuy [i]= min(bestBuy[i-1],prices[i-1]);
        // cout<<bestBuy[i]<<",";
    }
    int maxProfit = 0; //O(n+n) = O(2n) = O(n)
    for(int i=0; i<n; i++){
        int currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currProfit);
    }
    cout<<"max Profit = "<<maxProfit<<endl;
}

// water trapped 
void trap(int *heights, int n){
    int leftMax[2000] , rightMax[2000];
    leftMax[0] = 0;
    rightMax[n-1] = 0;
    cout<<leftMax[0]<<",";
    for(int i=1; i<n; i++){
        leftMax[i] = max(leftMax[i-1], heights[i-1]);
        cout<<leftMax[i]<<",";
    }
    cout<<endl;
    for(int i=n-2; i>=0; i--){
        rightMax[i] = max(rightMax[i+1], heights[i+1]);
        cout<<rightMax[i]<<",";
    }
    cout<<rightMax[n-1]<<","<<endl;
    cout<<endl;
    //final step
    int waterTrapped = 0;
    for(int i=0; i<n; i++){
        int currWater = min(leftMax[i], rightMax[i]) - heights[i];
        if (currWater > 0){
            waterTrapped += currWater;
        }
    }
    cout<<"Water Trapped = "<<waterTrapped<<endl;
}

int main() {

    int arr[5] = {1,2,3,4,5};
    int n = 5;
    printSubarrays(arr, n);

    int arr1[6] = {2, -3, 6, -5, 4,2};
    int n1 = sizeof(arr1)/sizeof(int);
    maxSubarraySum1(arr1,n1);
    maxSubarraySum2(arr1,n1);
    maxSubarraySum3(arr1,n1);

    int prices[6] = {7, 1, 5, 3, 6, 4};
    int n2 = sizeof(prices)/sizeof(int);
    maxProfit(prices,n2); 

    int heights[7] = {4,2,0,6,3,2,5};
    int n3 = sizeof(heights) / sizeof(int);
    trap(heights,n3);


    return 0;
return 0; 
}