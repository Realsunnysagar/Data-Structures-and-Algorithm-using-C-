/*
1.Linked List
    -Is also a linear Data Structure like arrays, vector 
    - 1->2->3->4
    - Each element is a Node
    - Each Node is having two parts one is storing the element and other storing address of next node
    - Here memory is not allocated in continous form unlike in array where memory allocation is continous like 100,104,108. . .
    - 100{1,500}, 500{2,200}, 200{3,50}, 50{4,NULL}
    - LL Node having two component : 1. data(int) 2.Node* (ptr)
    - Head* = special pointer pointing to the 1st Node
    - Tail = points to the last node
    - We can't access any elment in LL in O(1) time, we need to go to that element sequentially unlike in array we directly fetch arr[3], arr[0] .. etc
2.LL Implementation
    - We can make it through STL also but will study afterwards
    - Now we will implement using class 
    - Here type of an Node is Node itself and we make it using class
    - Class Node{       //Node
        int data;
        Node* next;
      };
     Class List{            //collection of nodes
        Node* head;
        Node* tail;
     };
3.Push Front
    - LL.push_front(val)
    - .push_front, .Push_back, .pop_front, .pop_back this four function are there in STL
    - just adding a node in the front
    - 1.Node* newNode = new Node(val); //creating the new node
    - 2.newNode->next = head; //if previously empty then h = t = newNode
    - 3.head = newNode //now head will point to new 1st node
4.Push Back
    -Pushing value at the last
    -1.Node* newNode = new Node(val);
    -2.tail->next = newNode
    -3.tail = newNode
5.Print LL
    -LL.printList()
    -Node* temp = head;
    while(temp != NULL){
     cout<<temp->data
     temp = temp->nextj
    }
6.Insert in LL Middle
    -Insert node at a given position in the LL
    -LL.insert(val, pos)
    -1.Create a new node
        Node* newNode = new Node(val);
    -2.find node at pos-1(loop)
        a.newNode->next = temp->next    //storing the address of right element before breaking 
        b.temp->next = newNode
7.Deleting the LL
    -write a code to delete entire LL
    -we made all dynamically therefore we need to delete that explicitly
    -we will create destructor of ~List and ~Node
8.Pop Front
    - LL.pop_front()
    - 1.Node* temp = head
    - 2.head = head->next
    - 3.temp->next = NULL
        delete temp;
9.Pop Back 
    -LL.pop_back()
    -1.tail's prev(loop)
        temp = head
        while(temp->next != tail){  //or we can write updated also (temp->next->next != NULL)
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail
        tail = temp;
    -finally last element will be removed
10.Iterative Search
    -searchItr(key)
    -we need to find a key=2 and return the position
11.Recursive Search
    - searchRec(key)
    - helper(temp, key){
        if(temp == NULL)
            return -1;
        if(temp->data=key)
            return 0;
      idx = helper(temp->next, key)
      if(idx == -1)
        return -1;
      return idx+1; 
     }
12.Reverse a Linked List
    -    
13.Find & Remove Nth Node from End
    - we cant traverse backward
    - to identify the prev node of deleting element
    - {1,2,3,4,5}  n=2 i.e 4
    - 1.last nth node
        front = 5   n=1
        front = 4   n=2
        front = 3   n=3
       therefore (size-n+1)
    - prev = (size-n)th
    - prev->next = prev->next->next;
    - 
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
    ~Node(){
        if(next != NULL){
            // cout<<"~Node"<< data<<endl;
            delete next;
            next = NULL;
        }
    }
};
class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = NULL;
        tail = NULL;
    }
    ~List(){
        // cout<<"~List\n";
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }
    void push_front(int val){
        Node* newNode = new Node(val); //dynamic 
        // Node* newNode(val); //static way of creating if we will go out of this function then it will be deleted
        
        if(head == NULL){
            
            head = tail = newNode;
        }else{
            newNode->next = head; 
            head = newNode;
        }
    }
    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList(){
        Node* temp = head;

        while(temp != NULL){
            cout<< temp->data <<" -> ";
            temp = temp -> next;
        }
        cout<<"NULL\n";
    }

    void insert(int val, int pos){
        Node* newNode = new Node(val);
        
        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            if(temp == NULL){
                cout<<"position is INVALID\n";
                return;
            }
            temp = temp->next;
        }
        // temp is now at pos-1 i.e. prev/left
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front(){
        if(head == NULL){
            cout << "LL is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp = head;

        while (temp->next->next != NULL){
            temp = temp->next;
        }

        temp->next = NULL; //temp = temp's prev
        delete tail;
        tail = temp;
    }
    // 
    int searchItr(int key){ //O(n)
        Node* temp = head;
        int idx = 0;

        while(temp!=NULL){
            if(temp->data == key){
                return idx;
            }

            temp = temp->next;
            idx++;
        }
        return -1;
    }

    // 
    int helper(Node* h, int key){
        if(h == NULL){
            return -1;
        }
        if(h->data == key){
            return 0;
        }

        int idx = helper(h->next, key);
        if(idx == -1){
            return -1;
        }
        return idx + 1;  
    }
    int searchRec(int key){
        return helper(head, key);
    }

    // Reverse a LL
    void reverse(){
        Node* curr = head;
        Node* prev = NULL;
        tail = head;
        while (curr != NULL){
            Node* next = curr->next;
            curr->next = prev;

            // updation for next itr
            prev = curr;
            curr = next;
        }
        head = prev;
    }
//Removing Nth element from the last
    int getSize(){
        int sz = 0;
        Node* temp = head;
        
        while(temp != NULL){
            temp = temp->next;
            sz++;
        }
        return sz;
    }
    void removeNth(int n){
        int size = getSize();
        Node* prev = head;

        for(int i=1; i<(size-n); i++){ //i=(size-n) => prev => deletion node prev
            prev = prev->next;
        }

        Node* toDel = prev->next;
        cout<<"going to delete: "<<toDel->data<<endl;

        prev->next = prev->next->next;
    }
};
int main() {
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);
    //1->2->3->NULL
    ll.printList();

    ll.insert(100,2);
    ll.printList();

    // ll.pop_back(); //2->3-> . . .
    ll.printList();
    cout<<ll.searchItr(2) <<endl;
    ll.searchRec(3);

    ll.reverse();
    ll.printList();

    ll.removeNth(2);
    ll.printList();
return 0; 
}