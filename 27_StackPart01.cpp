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

int main() {
    Stack<string> s; //therefore we need to specify type also as we have use class templet

    s.push("learn");
    s.push("coding");
    s.push("here");

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
return 0; 
}