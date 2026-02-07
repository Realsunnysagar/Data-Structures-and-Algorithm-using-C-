/*
1.Stack-Data Structure
    -We always imagine it as a bucket
    -push(), pop(), top()  -->O(1)
    -In stack top element is important because it is only element which we can access
    -It is also called a LIFO dataStructure (Last In First Out)
2.Stack Using Vector
    - push, pop , top func in O(1) time
    - {1,2,3,_,_,_ } -> stack {then 3 = topIdx}{if we push(4) there then topIdx++}
    - we can impelement it using array but the issue is we required size of array 
    - therefore we can implement it using vector
    - using vector {1,2.3 . . } 
    - class stack{
        push(val)
            vector.push_back(val);
        pop()
            vector.pop_back();
     }
3.Stack Implementation
    -using Vector with class template
    - we need to create a stack for different datatype let say float, int , char, string, bool
    - To resolve this we have special feature that is class template
    - template<class T> =>write this above the class and variable is like vecotor<T> vec;
4.Stack Implementation using Linked List 
    - In LinkedList most important node is head therefore we will use it as top in stack
    - push(val) => ll.push_front(val)       //O(1)
    - pop() => ll.pop_front()       //O(1)
    - top() => ll head->data        //O(1)
    - class Stack{
        List<int> ll;
     }
5.Stack in STL
    - #include<stack>
    - stack<int> s;  //stack created
    - s.empty() //empty function
    - rest is same as we declared
6.Push at Bottom of Stack
    - pushAtBottom(&stack, value)
    - to create a function in which we need to push a elment to the bottom of the stack rather than top
    -* All the containers of STL like vector, listl, stack always (pass by value) in functions and if we want to change under that and want to reflect onto that then we need to pass by reference (&)
    - We will use recursive approach for it
    - PAB(stack, val){      //O(n) - linear time complexity
        if(stack.empty())
            push(val)
            return;
        temp = stack.top()
         stack.pop()
        PAB(stack, val)
        stack.push(temp)
     }
7.Reverse a string using a stack
    - "abcd" - "dcba"
    - if we want to reverse a string then simply put it an stack and remove to from the top one by one the output will be reversed
8.Reverse a stack
    -(use Recursion only)
    -{3,2,1} -> {2,1} -> {1} -> { } (to reverse empty stack is easy because we just need to return )
    - rev(stack){
        if(s.empty)
            return;
        temp = s.top(); 
        s.pop();
        rev(s)
        pushAtBottom(s,temp);
     }
9.Stock Span Problem
    - span = max no. of consecutive days (including current) for which price <= today's price
    - stocks = [100, 80, 60, 70, 60, 85, 100]   => each position is a day like day 1,2,3, ..resp
    - span   = [ 1,  1,  1,  2,  1,  5,   7 ]   => price <= today's price
    - This is what span we need to return, 
    - asked in multiple companie's drive
    - Aproach
        span = i(curr) - prevHigh(i);  //at day 1st span is always 1 
        prevHigh = 1st greater value previous to curr
        ans/span = { 1, 1, 1, 2, 1, 5, 7}
        span = i + 1 // for 1st element and for largest element at any index whose previous is always small
        In stack we will be storing prevHigh values only as the prevHigh changes for an element we will pop the useless element from the stack
        - stack<int> s
          vector<int> span
          span[0] = 1
          s.push(0)
          for(int i = 1; i<arr.size(), i++)     //cal prev high
            while(!s.empty() && arr[i] => s.top())
                s.pop() 
            if(s.empty())
                span[i] = i + 1
            prevHigh = s.top()
            span[i] = i - prevHigh
    */
#include <bits/stdc++.h>
using namespace std;

// Create Stack using vector
template<class T>
class Stack{
    vector<T> vec;
public:
    void push(T val){  //O(1)
        vec.push_back(val);
    }

    void pop(){     //O(1)
        if(isEmpty()){
            cout<<"Stack is empty.\n";
            return;
        }
        vec.pop_back();
    }

    T top(){      //O(1)
        //  if(isEmpty()){
        //     cout<<"Stack is empty.\n";
        //     return -1;
        // }
        int lastIdx = vec.size() - 1;
        return vec[lastIdx];
    }

    bool isEmpty(){ //O(1)
       return vec.size() == 0;
    }
};


// create Stack using Linked List
template<class T1>
class Node{
public:
    T1 data;
    Node* next;
    Node(T1 val){
        data = val;
        next = NULL;
    }
};
template<class T1>
class Stack1{
    // list<T1> ll;
    Node<T1>* head;
public: 
    Stack1(){
        head = NULL;
    }
    void push1(T1 val){
        // ll.push_front(val);
        Node<T1>* newNode = new Node<T1>(val);
        if(head == NULL){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void pop1(){
        // ll.pop_front();
        Node<T1>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    T1 top1(){
        // return ll.front();
        return head->data;
    }

    bool isEmpty(){
        // return ll.size() == 0;
        return head == NULL;  
    }
};

// Push at the Bottom
// -->Not found in video check on YT
void pushATBottom(stack<int> &s, int val){  //O(n)
    if(s.empty()){
        s.push(val);    //push at top = push at bottom
        return;
    }

    int temp = s.top();
    s.pop();
    pushATBottom(s, val);
    s.push(temp);
}

//Reverse a String using Stack
string reverseString(string str){  //TC: O(n) : O(n) SC
    string ans;
    stack<char> s;

    for(int i=0; i<str.size(); i++){
        s.push(str[i]);
    }

    while(!s.empty()){
        char top = s.top();
        ans += top;
        s.pop();
    }
    return ans;
}

// Reverse a stack
void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    reverse(s);
    pushATBottom(s, temp);
}

// to print
void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top() << " ";
        s.pop();
    }
    cout<<endl;
}
// Stock span Problem
void stockSpanProblem(vector<int> stock, vector<int> span){
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for(int i =1 ; i<stock.size(); i++){
        int currPrice = stock[i];
        while(!s.empty() && currPrice >= stock[s.top()]){
            s.pop();
        }
        if(s.empty()){
            span[i] = i + 1;
        }else{
            int prevHigh = s.top();
            span[i] = i-prevHigh;
        }
    }

    for(int i= 0; i<span.size(); i++){
        cout<<span[i]<<" ";
    }
    cout<<endl;
}

int main() {
    Stack<string> s; //therefore we need to specify type also as we have use class templet

    s.push("learn");
    s.push("coding");
    s.push("here");

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    // using LL
    Stack1<int> s1;
    s1.push1(3);
    s1.push1(2);
    s1.push1(1);

    while(!s1.isEmpty()){
        cout<<s1.top1()<<" "; //1, 2, 3
        s1.pop1();
    }
    cout<<endl;

    string str="abcd";
    cout<<reverseString(str)<<endl;

    stack<int> s2;
    s2.push(9);
    s2.push(8);
    s2.push(6);
    s2.push(7);
    printStack(s2);
    reverse(s2);
    printStack(s2);
    
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span = {0, 0, 0, 0, 0, 0, 0};
    stockSpanProblem(stock,span);

return 0; 
}