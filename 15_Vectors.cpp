/*
1.Dynamic Memory Allocation
    - we take input of the size at run time 
    - using new keyword operator from which we can allocate new memory to data in data structure
    -In 1D array
        - int size;
        - cin>> size;
        - int *arr = new int[size];    will work like -->arr[1] => *(arr+1)
    -Two types of memory allocation
        1. Static (at compile time memory will be allocated)  -> int arr[100] ={1,2,3,4,5} 
            -this is fixed
            -allocation are done in stack memory and if stack frame is removed then the variable will be removed
            -memory gets freed automatically
        2. Dynamic (at run time)
            - this is dynamic
            - allocation are done in heap memory
            - int *ptr =new int[size=10]
            - here the array of size 10 will be created in the heap
            - but the ptr varible is created in main func and will be pointing the the first element of the array
            - if the ptr will be there in any stack function and we will delete that function the pointer will be deleted but the array will be there in the heap until unless we delete that{called Memory Leak}
            - delete[] ptr; -> to free space from the heap which ptr holds
            - Its very important to use delete if you use the new dma
            - memory needs to be freed explicitly (delete operator)
2.Memory Leak
    -A memory leak occurs when programmers create a memory in a heap and forget to delete it.
    -Leads to reduced performance due to depletion of available memory.
    -during server setup we assure memory deallocation very precisly to overcome issues
3.2D Dynamic Arrays
    - to make directly 2d dynamic array is not possible
    - therefore we will make different 1D arrays (rows) and converge that to make a 2d arr
    - ptr of i = new int[cols]; like ptr1, ptr2,. . .
    - so we will create a array of pointers
    - int **arr = new int*[size]; --> this is a pointer to the pointer of the arrays1d
    - In heap memory it will create a array which is get pinted my matrix (int*), and every elment is a ptr
    - Each ptr element is pointing to a array 1D
    - This is a internal working of it
    - matrix[i][j] =>will work as *(*(matrix + i)+j)
4.STL
    Standard Template Library of C++
    - It is a library (collection) of container classes(like vectors ..etc), algorithms(like sort , etc..) & iterators.
    - It contains the implementation of common daa structures like vectors, stacks, maos etc.
5.Vectors
    - Like Dynamic arrays that can resize dynamically at runtime.
    - They are stored contiguously in memory.
    - also called sequence container.
    - #include <vector>
    - no need to deallocate it because everything is there in STL
    - vector<int> vec1;
    - vector<int> vec2 = {1, 2, 3, 4};
    - vector<int> vec3(5, -1); => size=5, initialise from -1
    - vec[i] => *(vec + i)
6.Vector Implemention in Memory*
    - size -> no. of element present, capacity -> max. no. of element that vec can hold
    - vector<int> vec = {1,2,3,4} => In memory it will create a array of size 4 and capacity 4
    - If we want to store a elm 5 in upper array then it will create another space double then previous capacity(4) and becomes 2*4 capacity(8)
    - Now each element will be copied to new space of capacity 8 like {1, 2, 3, 4, 5, _ _ _}
    - then prevously occupied array of cap 4 will be deleted automatically
    - again if it cross 8 then will create another of capacity 16
    - It takes  O(n) linear times to copy each element to new created place
    - but if space is there and we just need to add element the for new element will take -> O(1) constant times
    - average - ammortized time is O(1)
    - vec.push_back(5); -> add 5 to end of vec
    - vec.size() and vec.capacity()
    - vec.pop_back(5); -> to delete the element
7.Pair Sum
    - Find if any pair in sorted vector has target sum.
    - i/p : arr = [2,7,11,15], taret = 9
    - o/p : [0,1] //vector of indices
    - 2 pointer approach - start and end
    - currSum = st + end
    - while(start < end) ->O(n)
    - 1. currSum = target -> ans
    - 2. currSum > target -> end--
    - 3. currSum < target -> st++
8.2D Vectors
    - vector<vector int> matrix;
    - individual row will be a individual vector therfore its a vector of vectors
    -*unlike 2D array, in 2D vectors we can keep mutiple no. of columns i.e. no. of element in row can vary
    -
    - 
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> pairSum(vector<int> arr, int target){
    int st=0 , end = arr.size()-1;
    int currSum = 0;
    vector<int> ans;

    while (st < end){
        currSum = arr[st] + arr[end];
        if(currSum == target){
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }else if(currSum > target){
            end--;
        }else{
            st++;
        }
    }
    return ans;
}

int main() {
    /*later decomment it
    int rows, cols;
    cout<<"enter rows: ";
    cin>>rows;
    cout<<"enter cols:";
    cin>>cols;

    int* *matrix = new int*[rows];

    for(int i=0; i<rows; i++){
        matrix[i] = new int[cols];
    }

    // data store
    int x =1; 
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            matrix[i][j] = x++;
            cout<< matrix[i][j] <<" ";
        }
        cout<<endl;
    }
    // both is same
    cout<<matrix[2][2] <<endl;
    cout << *(*(matrix + 2) + 2) <<endl;
*/
    vector<int> vec1 = {1, 2, 3, 4};
    vector<int> vec2(10,-1);
    cout<<vec1.size() <<"\n";

    for(int i=0; i<vec2.size(); i++){
        cout<<vec2[i]<<" ";
    }
    cout<<endl;
    // pair sum
    vector<int> vec3 = {2, 7, 11, 15};
    int target = 9;
     vector<int> ans = pairSum(vec3, target);
     cout<<ans[0] <<", "<< ans[1] << endl;

    //  2D vectors
    cout<<endl<<"2D vectors:\n";
    vector <vector<int>> matrix = {{1,2,3}, {4,5}, {6}};

    for(int i = 0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
return 0; 
}