/*
1.Binary Search Trees(BST)
    -Special Binary Tree
    -Time Complexity --> O(Height) === O(log n) 
    -left Subtree value < node value < right subtree value
    -           4
               / \
              2   5
             / \   \
            1   3   6   all nodes must satisfy above BST property
    - BST nodes -> generally unique in most of the case
    - Inorder : 1.left subtree  2. root  3. right subtree
            123456
    -          5
              / \
             3   8
            / \ / \
           1  4 6  9
                 \
                  7     Inorder : 13456789
    - Inorder is always sorted in form
2.Search in BST
    - search key = 3
    -          5            - worst O(n) in BT
              / \           - This is similar to Binary Search as node will be mid 
             2   6          - BST
            / \   \             1.root->data == key -> return 
           1   4   7            2.root<key --> right subtree
               /                3.root>key --> left subtree
              3             - We can observe that at each level we need to compare/check for only one node therefore TC : O(height) == O(log n)
    - worst case --> skewed tree == n nodes = O(n) = n height = O(height)
    - therefore depending upon the tree structure timecomplexity can differ but it will always be O(height)
    - Balanced tree = O(height) = O(log n)
3.Build a BST from Array
    1.insert 2.search 3.delete
    - arr = [5, 1, 3, 4, 2, 7]
    -       5         - root = insert(root, arr[i])
           / \          insert(root, val){
          1   7         root = Null => root = new Node (val) ->BC
           \            (val > root) -> insert (right subtree)
            3           (val < root) -> insert (left subtree)
           / \          }
          2   4
4.Delete a Node in BST
    Cases
        1.having No child (leaf node)
        2.having 1 child
        3.having 2 childeren 
        Node* delNode(root, val){           //Basic logic
            if(root = NULL) return NULL;

            if(val < root)          //searching
                delNode(left)
            else if(val > root)
                root->right = delNode(right)
        }

        root == val
    case:1. root -> leaf    //node with 0 children
            delete root;    //as dynamically allocated
            return NULL;
    case:2.         node    //node with 1 child
                   /    \ 
                left or right
              (valid)   (valid)
               /             \ 
        retrun root->left  return root->right
    case:3. node with 2 children
            1. replace val with inorder successor
            2. delete inorder successor
                8
               / \          1 3 4 *5 6 8 10 11 14
             *5   10        - 6 is inorder successor, therefore 5 will be replaced by 6
             / \    \         inorder successor always have 0 or 1 child now as we have copied the value 6 at deleting node 5 therefore we need to delete the node as per case 01 or 2
            3   6    11
           / \         \ 
          1   4         14
          Inorder Successor
            In BST it is left-most node in right subtree of a node.
            (This is always has 0 or 1 right child only)
            4           -root node => root->right subtree
           / \      1 *4 5 7 8 9 10  IS -> left most node i.e 5 here
          1   5                          1. no left child* (always)
               \                IS(root->right)            
                9               Node* IS(root){
               / \                  while(root->left == NULL){
              7   10                    root = root->left;
               \                    }
                8                       return root; //IS
                                    }
5.Print in Range
    -we have been given with starting and ending value and we in to print all the values between that range
    - start = 5, end = 12
            8               5,6,8,10,11
           / \            -One way is to traverse entire tree which will take O(n) time 
          5   10          -Using the BST property we can solve it in minimum time 
         / \    \           case 01 : when root lies in the range
        3   6    11             (start =< root <=end)
       / \         \                print root
      1   4        14               left subtree
                                    right subtree
                            case 02 : when root is smaller than start
                                right subtree
                            case 03 : when root is greater than the end
                                left subtree
6.Root to Leaf Path
    - It can be for any tree 
    - Time complexity O(n)
    -           8               8 5 3 1
               / \              8 5 3 4
              5   10            8 5 6
             / \    \           8 10 11 14
            3   6    11
           / \        \
          1   4        14 
    - vector<int> path;
7.Validate BST
    - If this is a valid binary search tree or not
    - 1. leftsubtree < node, 2. right subtree >  node
    Approach
        node > maxValue in left Subtree
        node < minValue in right subtree

    -                   5   min = N, max = N
                      /   \
        min=N,max=5  3     6    min=5,max=N
                    / \      \ 
     min=N,max=3   1   4      7  min=6,max=N
                     min=3,
                     max=5
    -valid BST(root, min, max){
        if(min != NULL && root < min)
            return false
        if(max != null && root>max){
            return false
        }
        validate(r->left, min , root->d)    --false then return f
        validate(r->right, root->d, max)    --false then return f
    }
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

// Build a BST from Array
Node* insert(Node* root, int val){
    if(root == NULL) {
        root = new Node(val);
        return root;
    }

    if(val < root->data){   //left subtree
        root->left = insert(root->left , val);
    }else{  //right subtree
        root->right = insert(root->right , val);
    }
}
Node* buildBST(int arr[], int n){
    Node* root = NULL;

    for(int i = 0; i<n; i++){
        root = insert(root,arr[i]);
    }
    return root;
}

// Inorder traversal
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// Search in BST
bool search(Node* root, int key){
    if(root == NULL) return false;

    if(root->data == key) return true; //found
    if(root->data > key){
        return search(root->left, key);
    }else{
        return search(root->right, key);
    }
}

// Delete a Node 
Node* getInorderSuccessor(Node* root){
    while(root->left != NULL){
        root = root->left;
    } 
    return root;    //IS
}
Node* delNode(Node* root, int val){
    if(root==NULL) return NULL;

    if(val < root->data){       //left subtree
        root->left = delNode(root->left, val);
    }else if(val > root->data){
        root->right = delNode(root->right, val);
    }else{
        //root==val
        //case 1 : 0 children
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // Case 2 : 1 children
        if(root->left == NULL || root->right == NULL){
            return root->left == NULL ? root->right : root->left;
        }

        // case 03: 2 children
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right, IS->data);   //case1 , case 2
        return root;
    }
    return root;
}

// Print in Range 
void printInRange(Node* root, int start, int end){
    if(root == NULL) return;

    if(start <= root->data && root->data <= end){       //in range case 1
          printInRange(root->left, start, end);
          cout<<root->data << " ";
          printInRange(root->right, start, end);
    }else if(root->data < start){       //case 2
        printInRange(root->right, start, end);
    }else{      //case 3
        printInRange(root->left, start, end);
    }
}

// Root to Leaf Path}
void printPath(vector<int> path){
    cout<<"path : ";
    for(int i=0; i<path.size(); i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void pathHelper(Node* root, vector<int> &path){
    if(root == NULL) return;

    path.push_back(root->data);

    if(root->left == NULL && root->right == NULL){  //leaf
        printPath(path);
        path.pop_back();
        return;
    }

    pathHelper(root->left, path);
    pathHelper(root->right, path);

    path.pop_back();
}
void rootToLeafPath(Node* root){
    vector<int> path;
    pathHelper(root, path);
}

// Validate BST
bool validateHelper(Node* root, Node* min, Node* max){
    if(root == NULL) return true;

    if(min != NULL && root->data < min->data){
        return false;
    }
    if(max != NULL && root->data > max->data){
        return false;
    }

    return validateHelper(root->left, min, root)
        && validateHelper(root->right, root, max);

}
bool validateBST(Node* root){
    return validateHelper(root, NULL, NULL);
}

int main() {
    int arr[6] = {5, 1, 3, 4, 2, 7};
    Node* root = buildBST(arr,6);
    inorder(root);
    cout<<endl;

    cout<<search(root, 6)<<endl; 

    int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root1 = buildBST(arr2, 9);
    inorder(root1);
    cout<<endl;
    delNode(root1, 1);
    inorder(root1);
    cout<<endl;

    printInRange(root1, 5, 12);
    cout<<endl;

    rootToLeafPath(root1);

    cout<<validateBST(root1) <<endl;
return 0; 
}