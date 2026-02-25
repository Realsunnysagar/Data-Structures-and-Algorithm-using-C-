/*
1.Binary Trees
    -Hierarchical Data Structure
    -Major concept of Recurrsion is required here
    -Binary Tree is a special type of tree in which Each node has at max 2 children
    - root(top most) , leaf node, branch/edges, left child, right child, siblings (same level nodes), 
    - ancestor(all prev nodes in heirarchy) , descendent(all the nodes after that nodes)
    - 
2.Levels & Subtree
    Levels
    - We can divide a btree into multiple level
    - max level = height of the level
    - node'depth = current Level
    Subtree
    -Left subtree, right subtree for any node
    -we always use recursion to solve ques of trees
    - ans1 = call(left Subtree) , ans2 = call(right subtree)
    - return Operation 
3.Build Tree from Preorder
    -[1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1] ->preorder sequence
    -             1
             2         3
          4    5      n  6
        n  n  n  n      n  n
    - node{left, data, right}
4.Tree Traversals
    3 Recursive order -> 1.Preorder   2.Inorder    3.Postorder
    1 Iterative -> level order
    1.Preorder Traversal
        - root->left Subtree->right subtree
        - preorder(root){
            if(root == NULL)
                return;
            }
            cout<<root->data;
            preorder(root->left);
            preorder(root->right);
         }
        - n nodes therefore Time complexity : O(n)
    2.Inorder Traversal
        - LeftSubtree-> Root -> Right Subtree
        -       1           4 2 5 1 3 6 (root is in middle at every node)
              /   \
             2     3
            / \     \
           4   5     6
        - 
    3.Postorder Traversal
        - left Subtree-> right Subtree -> Root
        - 4, 5, 2, 3, 6, 1
5.Level Order Traversal
    - iterative way 
    -          1            1 23 456
             /   \
            2     3         23
           / \     \
          4   5     6       456
    - BFS (Breadth First Search) -> level order(less distance then will be traverse 1st)
    - DFS (Depth First Search)  -> preorder, inorder, postorder
    - We use Queue data structure for level order traversal
    - 1.q.push(root)
      2.while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr != NULL)
                print curr
            left != NULL (push into q)
            right != NULL (push into q)
       }
    -Another Variation
    -   1 n     null=>nextline
       23 n
       456
    - if(curr == NULL)
        if(q.empty())               //last NULL is pop then check for empty
            break;
        q.push(NULL)
    - This extra needs to be added to traverse like this
    - Questions like sum nodes at each level can be solved 
6.Height of a Tree
    - Max Distance from Root to Leaf
    - 1.Distance in terms of nodes      2.Distance in terms of edges
    - always edgeDistance = nodeDistance -1
    -           1           ht = 2 + 1 = 3
              /   \
             2     3        ht = 2
            / \     \
           4   5     6      ht = 1
    - height(root){         //O(n)
        if(root == NULL) return 0;     //base case
        leftH = height(root->left)
        rightH = height(root->right)
        currHt = max(leftH, rightH) + 1;
        return currHt;
    }
7.Count of Nodes
    - ans = 6 (same tree above)
    - count(root){          //O(n)
        if(root == NULL) return 0;

        leftC = count(root->left);
        rightC = count(root->right);

        return leftC + rightC + 1;
     }
8.Sum of Nodes
    - sum(root){        //O(n)
        if(root==null) return 0;

        leftSum = sum(root->left);
        rightSum = sum(root->right);

        return leftSum + rightSum + root->data;
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

static int idx = -1;
Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx] == -1){
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes); //left subtree
    currNode->right = buildTree(nodes); // right subtree

    return currNode;
}


// preorder O(n)
void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

//Inorder   O(n)
void inorder(Node* root){
    if(root == NULL) return;
    // left
    inorder(root->left);
    // root
    cout<< root->data << " ";
    // right
    inorder(root->right);
} 

// Postorder Traversal  O(n)
void postorder(Node* root){
    if(root == NULL) return;
    // left
    postorder(root->left);
    // right
    postorder(root->right);
    // root
    cout<<root->data << " ";
}

//Level Order like 1 23 456     O(n)
void levelOrder(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        cout<<curr->data<<" ";
        if(curr->left != NULL){
            q.push(curr->left);
        }

        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}

//Level Order like 1 nextline 23 nextline 456       O(n)
void levelOrder2(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            cout<<endl;
            if(q.empty()){
                break;
            }
            q.push(NULL);
        } else{
        cout<<curr->data<<" ";
        if(curr->left != NULL){
            q.push(curr->left);
        }

        if(curr->right != NULL){
            q.push(curr->right);
        }
        }
    }
}

//Height of Tree
int height(Node* root){
    if(root == NULL) return 0;

    int leftH = height(root->left);
    int rightH = height(root->right);

    int currHt = max(leftH, rightH) + 1;
    return currHt;
}

// Count Node of the Tree
int count(Node* root){
    if(root == NULL) return 0;

    int leftCount = count(root->left);
    int rightCount = count(root->right);

    return leftCount + rightCount + 1;
}

// Sum of Nodes in BT
int sum(Node* root){
    if(root == NULL) return 0;

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    int currSum = leftSum + rightSum + root->data;
    cout<<"currSum: "<< currSum<<endl;  //this line is just to check how rec work
    return currSum;
}

int main() {
 
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes); //1
    cout<<"root = "<<root->data<<endl;

    preorder(root); //Traverse the binary tree in pre order way
    cout<<endl;

    inorder(root);
    cout<<endl;
    
    postorder(root);
    cout<<endl;

    levelOrder(root);
    cout<<endl;
    
    levelOrder2(root);
    cout<<endl;

    cout<<"Height : "<< height(root) << endl; 

    cout<<"Count : " << count(root)<<endl;

    cout<<"Sum of Nodes : "<<sum(root)<<endl;
return 0; 
}