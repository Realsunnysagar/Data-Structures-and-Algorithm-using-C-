/*
1.Sorted Array to Balanced BST
    - arr = [3,4,5,6,7, 8,9]
             6
           /   \
          4     8     ->Balanced BST -> Min possible height
         / \   / \    ->BST inorder(left-curr-right) --> sorted
        3   5 7   9
    - left subtree -- curr(middle node) -- right subtree

      [ 3 ,  4,   5,             6,         7,   8,   9]
        L    C    R                         L     C   R
            L                     C               R
    - (arr[], st, end){
        arr[mid] --> curr Node
        curr--> left(arr, st, mid-1)
        curr--> right(arr, mid+1, end)
        return curr
        }
2.Converted BST to Balanced BST
    -        6                      
            / \                  6
           5   7               /   \    
          /     \     -->     4     8  
         4       5           / \   / \
        /         \         3   5 7   9
       3           9        Balanced BST(minimum possible height)
    
    - Original BST ---> sorted sequence(Inorder) ---> Balanced BST
    Approach
        1. Get it's inorder seq (sorted)
        2. Seq --> Balanced BST
            and store Balanced BST in original root
3.Size of Largest BST in BT
    Ques covered : Root Node/ height of Largest BST in BT
    -           50
               /  \         - Here the largest valid BST if of root node 6 of size 5
             30    60
            / \    / \
           5  20  45  70
                      / \ 
                     65  80
    Approach
    1.isBST(boot) --> left
    2.isBST(bool) --> right
    3.maxOf left
    4.min of right
    5.size of left & right + 1 will be final height
    we need these 5 important feature to solve it 
    - Info{
        isBST(bool)
        min(int)
        max(int)
        size(int)
     }
        Dry run this for 30
    - Valid BST
        1. leftInfo : isBST --> T
        2. rightIfo : isBST --> T
        3. leftInfo --> max < root->data
        4. rightInfo --> min > root->data
    - Info* largestBST(root){           //Time C : O(n)
        leftInfo(root->left)
        rightInfo(root->right)
        IsBST{
         --> 4 conditon
         min, max, sz
        }
         IsBST --> true ==> sz
        return info;
     }
4.Merge 2 BST
    -       2           9                   3
           / \         / \      ==        /   \
          1   4       3   12             1     9
                                          \   / \
                                           2 4   12
    Approach
        1.Sorted array --> balanced BST
        a) Inorder seq BST1
        b) Inorder seq BST2
        c) sorted merge -> sorted
        Now from final sorted we will create balanced BST


*/
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }

};

// Sorted Array to Balanced BST
Node* buildBSTfromSorted(int arr[], int st, int end){
    if(st > end){
        return NULL;
    }
    int mid = st + (end - st)/2;
    Node* curr = new Node(arr[mid]);

    curr->left = buildBSTfromSorted(arr, st, mid-1);
    curr->right = buildBSTfromSorted(arr, mid+1, end);

    return curr;
}

// Preorder printing values
void preorder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// 
Node* BSTfromSortedVec(vector<int> arr, int st, int end){
    if(st > end){
        return NULL;
    }
    int mid = st + (end - st)/2;
    Node* curr = new Node(arr[mid]);

    curr->left = BSTfromSortedVec(arr, st, mid-1);
    curr->right = BSTfromSortedVec(arr, mid+1, end);

    return curr;
}
void getInorder(Node* root, vector<int> &nodes){
    if(root == NULL) return;

    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}
Node* balancedBST(Node* root){
    // get inorder seq
    vector<int> nodes;
    getInorder(root, nodes);

    return BSTfromSortedVec(nodes, 0, nodes.size()-1);
}

// Largest BST in BT
class Info{
public:
    bool isBST;
    int min;
    int max;
    int sz;

    Info(bool isBST, int min, int max, int sz){
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->sz = sz;
    }

};

static int maxSize;

Info* largestBST(Node* root){
    if(root == NULL){
        return new Info(true, INT_MAX, INT_MIN, 0);
    }

    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
    int currMax = max(root->data, max(leftInfo->max, rightInfo->max));
    int currSz = leftInfo->sz + rightInfo->sz + 1;

    if(leftInfo->isBST && rightInfo->isBST 
        && root->data > leftInfo->max
        && root->data < rightInfo->min){
             maxSize = max(maxSize, currSz);
           return new Info(true, currMin, currMax, currSz);
        }

    return new Info(false, currMin, currMax, currSz);
}

// Merge 2 BST
Node* mergeBSTs(Node* root1, Node* root2){
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;

    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    int i =0, j = 0;
    while(i<nodes1.size() && j<nodes2.size()){
        if(nodes1[i] < nodes2[j]){
            merged.push_back(nodes1[i++]);
        }else{
            merged.push_back(nodes2[j++]);
        }
    }

    while(i<nodes1.size()){
        merged.push_back(nodes1[i++]);
    }

    while(j<nodes2.size()){
        merged.push_back(nodes2[j++]);
    }

    return BSTfromSortedVec(merged, 0, merged.size()-1);    //already written above
}

int main() {
    int arr[7] = {3, 4, 5, 6, 7, 8, 9};

    Node* root = buildBSTfromSorted(arr, 0, 6);

    preorder(root);
    cout<<endl;

    Node* root2 = new Node(6);
    root2->left = new Node(5);
    root2->left->left = new Node(4);
    root2->left->left->left = new Node(3);

    root2->right = new Node(7);
    root2->right->right = new Node(8);
    root2->right->right->right = new Node(9);

    root2 = balancedBST(root2);
    preorder(root2);
    cout<<endl;

    Node* root3 = new Node(50);
    root3->left = new Node(30);
    root3->left->left = new Node(5);
    root3->left->right = new Node(20);

    root3->right = new Node(60);
    root3->right->left = new Node(45);
    root3->right->right = new Node(70);
    root3->right->right->left = new Node(65);
    root3->right->right->right = new Node(80);

    largestBST(root3);
    cout<<"max Size : "<<maxSize<<endl;

    Node* root4 = new Node(2);
    root4->left = new Node(1);
    root4->right = new Node(4);

    Node* root5 =new Node(9);
    root5->left = new Node(3);
    root5->right = new Node(12);
     
    Node* root6 = mergeBSTs(root4, root5);
    preorder(root6);
    cout<<endl; 
return 0; 
}