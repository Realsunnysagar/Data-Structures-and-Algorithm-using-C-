/*
1.Detect a Cycle/Loop in a LL
    -Floyd's Cycle finding Algorithm
    - ()->()->()-> ()-> ()
               ^()-()-()^
    -Two ptrs -> 1.slow = head +1  (slow = slow->next)
                 2.fast = head +2  (fast = fast->next->next)
    -Floyd's algorithm says that if there is any loop then it is sure that this two pointer will meet anywhere
    -fast = slow = head
     while(fast != NULL && fast->next != NULL){     //even times f !=NULL, and odd times f->next != NULL
        slow = slow->next;
        fast = fast->next;
        if(slow == fast)
            cycle => break;
     }
2.Removing Cycle in a LL
    -1.cycle detection
        slow; fast
    -2.after meeting slow = head
    -3.now loop slow = +1, fast = +1 now if they will meet again at the connection/junction point again
            prevNode->next = NULL;
    -we need to handle one special case where head and juction is same like a rectangle say
        if(slow = fast){ at 2nd step
            while(fast->next != slow)
                fast ->+1
            fast->next = NULL
        }
3.List in STL
    - #include<list>
    - list<int> ll; //similar to : vector<int> arr;
    - ll.push_front(val);
    - ll.push_back(val);
    Iterator
    - #include<iterator>
    - Iterators in C++ are objects that allow you to traverse through the elements of a container(like arrays, vectors, lists, etc.) in a sequential manner.
    - list<int>::iterator itr;
    - ll.begin()    ->itr of head
    - ll.end()  ->itr of tail->next
    - for(itr = ll.begin ; itr != ll.end(); itr++)
    cout<<(*itr)    1 2 3 4
    - 
    - ll.size();        //total no. of nodes/element
    - ll.front() & ll.back()    //gives head and tail element
    - ll.pop_front() & ll.pop_back()    //adding at front and adding at back
4. Merge Sort on LL
    1. ms LL
    - ms(head){
        rightHead = splitAtMid(head)
        ms(head) <-sorted
        ms(rightHead) <-sorted
        merge(head,rightHead)
    }
    2. half/mid find and split Linked list into two parts
    - spliting at mid (using slow and fast technique)
        slow = fast = head
        while(fasst != NULL && fast->next != NULL)
            slow -> +1
            fast -> +2
        }
        prev->next = NULL       //split
        return rightHead = slow
    3. two sorted LL : merge both
    - Merging 2 sorted Lists
    - check codes below
5.Zig-Zag Linked List
    -For a linked list of the form : L(1)->L(2)->L(3)->...L(n-1)->L(n)
    -convert it into a zig-zag form i.e. : L(1)->L(n)->L(2)->L(n-1)->L(3)->L(n-2)...
    -solve this ques without any extra space
    1.split at Mid
    2.Reverse 2nd part(rightHead)
    3.Alternate Merging
        left = head
        right = rightHeadRev

        while(left != NULL && right != NULL)
        nextLeft = left->next
        nextRight = right->next

        left->next = right
        right->next = nextLeft
        tail = right        //we will track tail for odd no. of element and last element left
        left = nextLeft
        right = nextRight
        }

        tail -> next = right;

6.Doubly Linked List
    - {1} <-> {2} <-> {3} <-> {4} <-> {5}
    - pop front and push front
    - Node => {data, next, prev}
    - class Node{
        data 
        next, prev
    }
    - class DoublyList{
        head
        tail
    }
    - push front is done check below
    - pop_front 
        Node* temp = head   //we need to delete this dynamic allocated one so stored in temp
        head = head->next;
        if(head != NULL)        //for 1node ll say this
            head->prev = NULL
        temp->next = NULL
        delete temp;

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
public:
    Node* head;
    Node* tail;
    List(){
        head = NULL;
        tail = NULL;
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
    void printList(){
        Node* temp = head;

        while(temp != NULL){
            cout<< temp->data <<" -> ";
            temp = temp -> next;
        }
        cout<<"NULL\n";
    }

};
bool isCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;  //+1
        fast = fast->next->next;    //+2

        if(slow == fast){
            cout<<"Cycle Exists\n";
            return true;
        }
    }
    cout<<"Cycle doesn't exists\n";
    return false;
}

// Remove cycle
void removeCycle(Node* head){
    // detect cycle
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout<<"Cycle exists\n";
            isCycle = true;
            break;
        }
    }
    if(!isCycle){
        cout << "Cycle doesn't exist\n";
        return;
    }

    //step 2
    slow = head;
    if(slow == head){   //special case : tail->head
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL;  // remove cycle
    }else{
        Node* prev = fast;
        while(slow != fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL; // remove cycle
    }
}

// Using Iterator
void printList(list<int> ll){
    list<int>::iterator itr;
    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout <<(*itr)<<" -> ";
    }
    cout<<"NULL"<<endl;
}

// Merge Sort in LL
Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while( fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev != NULL){
        prev ->next = NULL; //split at Node
    }

    return slow; //slow = rightHead
}

Node* merge(Node* left, Node* right){
    List ans;
    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL){
        if(i->data <= j->data){
            ans.push_back(i->data);
            i = i->next;
        }else{
            ans.push_back(j->data);
            j = j->next;
        }
    }
    while(i != NULL){
        ans.push_back(i->data);
        i = i->next;
    }
    while(j != NULL){
        ans.push_back(j->data);
        j = j->next;
    }
    return ans.head;
}
Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* rightHead = splitAtMid(head);

    Node* left = mergeSort(head);    //left Head
    Node* right = mergeSort(rightHead);   //right Head

    return merge(left, right); //head of sorted LL
}


// Zig-Zag Linked List
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;    //prev is head of reversed LL
}

Node* zigZagLL(Node* head){
    Node* rightHead = splitAtMid(head);
    rightHead = reverse(rightHead);

    // alternate merging : 1st head = head; 2nd 
    Node* left = head;
    Node* right = rightHead;
    Node* tail = right;

    while(left != NULL && right != NULL){
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        right->next = nextLeft;

        tail = right;

        left = nextLeft;
        right = nextRight;
    }

    if(right != NULL){
        tail->next = right;
    }
    return head;
}

// Doubly Linked List
class Node1{
public:
    int data1;
    Node1* next1;
    Node1* prev1;

    Node1(int val){
        data1 = val;
        prev1 = next1 = NULL;
    }
};

class DoublyList{
public:
    Node1* head;
    Node1* tail;

    DoublyList(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node1* newNode = new Node1(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next1 = head;
            head->prev1 = newNode;
            head = newNode;
        }
    }
    void printList1(){
        Node1* temp = head;
        while(temp != NULL){
            cout<< temp->data1 <<"<=>";
            temp = temp->next1;
        }
        cout<<"NULL\n";
    }

    void pop_front(){
        Node1* temp = head;
        head = head->next1;
        if(head != NULL){
            head->prev1 = NULL;
        }

        temp->next1 = NULL;
        delete temp;
    }
};

int main() {
 
    List ll;
    ll.push_front(4);
    ll.push_front(5);
    ll.push_front(8);
    ll.push_front(3);
    ll.push_front(6);
    ll.push_front(1); 
    //1->2->3->1
    ll.tail->next = ll.head;
    removeCycle(ll.head);
    ll.printList();

    ll.head = mergeSort(ll.head);
    // printList(ll.head);
    ll.printList();

    ll.head = zigZagLL(ll.head);
    ll.printList();

    // DLL
    DoublyList dbll;
    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);

    dbll.printList1();

    dbll.pop_front();
    dbll.printList1();
    
return 0; 
}