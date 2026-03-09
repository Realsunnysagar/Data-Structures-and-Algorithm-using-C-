/*
1.Heaps / Priority Queue
2.PQ in STL
    - #include<queue>
    priority_queue<int> pq;
    - push()    //O(log n)
    - pop()     //O(log n)
    - top()     //O(1)
            PQ
           /  \
 (%)max heap   min heap (rank(lesser the rank higher the priority))
    - We can make this two types of PQ depending on the condition
3.Heaps
    -What is the Heap Data Structure?
    -We visualize heap as a CBT(complete binary tree)
     and in code it is written as an vector/array
    - The implimentation of the Heap under cpp STL is Priority Queue
    -         9                 1
             / \               / \
            4   5             2   4
           / \               / \ 
          1   2             5   9
        max Heap           min Heap
        (by default)
        PQ
    Heap is a Complete BT(CBT)
    -CBT is a BT where all levels are filled except maybe the last one, which is filled left to right
    -Parent >= Children //Max Heap (root(top) = maximum)
    -Parent <= children //Min Heap (root(top) = minimum)
4.Building Heaps
    -push()     //insert    O(log n)
    -pop()      //pop max or min O(log n)
    -top()      //get max or min    O(1)
    - Heap is not implemented as a class
    REASON : 1.insert TC:O(n) and then 2.fix Heap TC which is far more than log n
    Sol:-
    - Heap as an array/vector
    Heap : parent-child Relation
            8(0)    arr = [8,4,5,1,2, ] -->0-based indexing, we will convert CBT into array
           / \      index i(parent)
       (1)4   5(2)      leftChild = 2*i+1
         / \            rightChild = 2*i+1  in array    like for 8 LC = 1, RC = 2
     (3)1   2(4)    and
                    child idx = x
                    par idx = (x-1)/2
    vec.push_back(val) -->this will push the value 9 last of the array which is O(1) time and then we will fix it in log n time.
5.Push in Heap
    Insert val = 9
    1.heap --> insert(val)
        vec.pb(val)     //O(1)
        [8, 4, 5, 1, 2, 9, ]
    2.fix heap
        P-C relation
        childI = 5 (x)      //9 is at idx 5
        ParI = 2 ((x-1)/2)
        while(childI > parI){      //O(logn)in worst case //value at that idx 
            swap(x, parI)
            x = parI
            parI = (x-1)/2
        }
    [9,4,8,1,2,5, ]
6.Pop in Heap
    -        9          -To pop the top element in heap is a 3 step process 
           /   \        1. swap (root , last) -O(1)
          4     8       2. delete this lastIdx--> vec.pop_back() - O(1)
         / \   /        3. Fix the Heap --> heapify - O(log n)
        1  2  5
    [9, 4, 8, 1, 2, 5, ]
    1.[5, 4, 8, 1, 2, 9, ]  //swap
    2.[5, 4, 8, 1, 2,  ]    //delete
    3.
    Heapify 
        3       heapify(idx = 0){
       / \          val 1 --> i(par)
      8   6         val 2 --> l = 2*i + 1
     /              val 3 --> r = 2*i + 1
    4               i <-- max(val1, val2, val3)
                        swap(maxI, i)
                        heapify(maxI)
                    }     
7.PQ for Pair/Object
    -How we will create Priority Queue for objects
    class Student{
        string name;
        int marks;
    }
*/
#include <bits/stdc++.h>
using namespace std;

class Heap{
    vector<int> vec; //CBT -->max Heap
public:
    void push(int val){
        // step 1
        vec.push_back(val);
        // fix
        int x = vec.size() - 1; //childI
        int parI = (x-1)/2;
        while(parI >= 0 && vec[x] > vec[parI]){        //just chage > to < to make it min heap
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x-1)/2;
        }
    }
    void heapify(int i){ //i = parI
        if(i >= vec.size()){
            return;
        }
        int l = 2*i +1;
        int r = 2*i + 2;

        int maxI = i;
        if(l < vec.size() && vec[l] > vec[maxI]){
            maxI = l;
        }

        if(r < vec.size() && vec[r] > vec[maxI]){
            maxI = r;
        }
        
        swap(vec[i], vec[maxI]);
        if(maxI != i){  //swapping with child node
            heapify(maxI);
        }
    }
    void pop(){
        // step 1 : swap 
        swap(vec[0], vec[vec.size()-1]);
        // step2
        vec.pop_back();
        // step 3
        heapify(0); //O(log n)
    }
    int top(){  //O(1)
        return vec[0]; //highest priority element
    }
    bool empty(){
        return vec.size() == 0;
    }
};

// PQ for Objects
class Student { //"<" overload
public:
    string name;
    int marks;

    Student(string name, int marks){
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const Student &obj) const {
        return this->marks< obj.marks;
    }

};
int main() {

    // priority_queue<int> pq; //this is for max heap
    priority_queue<int, vector<int>, greater<int>> pq;  //here min Heap is used internally
    // We can do these with string also just replace int with string and change data
    pq.push(5);
    pq.push(10);
    pq.push(9);
    pq.push(7);
    pq.push(3);

    while(!pq.empty()){
        cout<<"top : "<< pq.top() <<endl;
        pq.pop();
    }

    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);
    cout<<"Top =  "<<heap.top()<<endl;
    heap.pop();
    cout<<"Top =  "<<heap.top()<<endl;

    priority_queue<Student> pq1;

    pq1.push(Student("Sunny", 85));
    pq1.push(Student("Ankit", 95));
    pq1.push(Student("Suraj", 65));

      
    while(!pq1.empty()){
        cout<<"top : "<< pq1.top().name << ", "<<pq1.top().marks<<endl;
        pq1.pop();
    }

return 0; 
}