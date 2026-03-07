/*
1.Kth Level of a Tree
    -       1          level = 1(x)
           / \
          2   3        level = 2(x+1)
         / \   \
        4   5   6      level = 3
      for K = 3
      Output : 4,5,6
    - root -> x, leftSubtree -> x+1 , rightSubtree -> x+1
2.Lowest Common Ancestor
    -       1
           / \
          2   3
         / \   \ 
        4   5   6
      n1=4, n2=6    n1 = 4, n2 = 5      n1=3, n2=6
      LCA = 1       LCA = 2             LCA = 3
    -Approach 01 (TC : O(n), SC : O(n))
        1.Calculate node to root path of each node i.e. from root to node as both is same
            path1 : [1,2,4]
            path2 : [1,2,5]     for 4 and 5
        2.path1 & path2 last common node = LCA i.e 2 here which is common last in both
        bool finPath(root, n , path){
            if(root == NULL) return false;
            path.push_back(root->data)
            if(root->data == n){
                return true;
            }
            findPath -> left subtree
            findPath -> right subtree
        }
    -Approach 02 (TC : O(n), SC : O(1))
        we are going to find n1 and n2 recusively at a node
        base case ->root == null return null
        if(root->data = n1 || n2){
            return root;
        }
        leftsubtree(n1,n2) = leftLCA(L)
        rightsubtree(n1,n2) = rightLCA(R)
        I.L = NULL
          R = NULL 
            return NULL
        II.L = valid
           R = NULL 
             return L
        III.L = NULL
            R = valid 
              return R
        IV.L = valid
           R = valid 
             return root
3.Min Distance between nodes    O(n)
    - n1 = 4, n2 = 6
    - lca(n1, n2)       //1
      dist1 = lca to n1
      dist2 = lca to n2
      return dist1 + dist2
    - int dist(root, n){
        if(root == n) return 0;
        dist -> left
        dist -> right
      }
4.Kth Ancestor of node
    -    1
        / \ 
       2   3
      / \   \ 
     4   5   6
     node = 5, K = 2
     therefore ans = 1  (kth ancestor of an element k distance toward the root from the node )
    - int KthAnces(root, node, k){
        1.BC -> root == NULL => -1
        2.if (root == node) return 0;
        leftSubtree -> leftDist
        rightSubtree -> rightDist
     }
      I. L = -1, R = -1
            return -1
      II. L = valid, R = -1
            return L+1
      III. L = -1, R = valid
            return R+1
5.Transform to Sum Tree
    - Each node = sum of left & right subtree
    -           1               20
               / \             /  \
              2   3           9    6
             / \   \         / \    \ 
            4   5   6       0   0    0
    -int transform(root){
        leftOld = trans(root->left)
        rightOld = trans(root->right)
        currOld =  root->data

        root->data = leftOld + rightOld + root->left->data + root->right->data
        return currOld
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

// Kth level of a Tree      O(n)
void KthHelper(Node* root, int k, int currLevel){

    if(root == NULL) return;

    if(currLevel == k){
        cout<< root->data<<" ";
        return;
    }
    KthHelper(root->left, k, currLevel+1);  //left
    KthHelper(root->right, k, currLevel+1); //right  
}
void KthLevel(Node* root, int k){
    KthHelper(root, k, 1);
    cout<<endl;
}

// Lowest Common Ancestor Approach 01(TC : O(n), SC : O(n))
bool rootToNodePath(Node* root, int n, vector<int> &path){  //calculating root to a node path
    if(root == NULL) return false;

    path.push_back(root->data);
    if(root->data == n){
        return true;
    }

    int isLeft = rootToNodePath(root->left, n, path);
    int isRight = rootToNodePath(root->right, n, path);

    if(isLeft || isRight){
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2){    //TC : O(n) SC : O(n)
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;
    for(int i=0, j=0; i<path1.size() && j<path2.size(); i++,j++){
        if(path1[i] != path2[j]){
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}

// Lowest Common Ancestor Approach 02(TC : O(n), SC : O(1))
Node* LCA2(Node* root, int n1, int n2){
    if(root == NULL) return NULL;

    if(root->data == n1 || root->data==n2){
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }
    return leftLCA == NULL ? rightLCA : leftLCA;
}

// Minimum Distance between Nodes   O(n)
int dist(Node* root, int n){
    if(root == NULL) return -1;

    if(root->data == n){
        return 0;
    }

    int leftDist = dist(root->left, n);
    if(leftDist != -1){
        return leftDist + 1;
    }

    int rightDist = dist(root->right, n);
    if(rightDist != -1){
        return rightDist + 1;
    }
}
int minDist(Node* root, int n1, int n2){
    Node* lca = LCA2(root, n1, n2);

    int dist1 = dist(lca , n1);
    int dist2 = dist(lca, n2);

    return dist1 + dist2;
}

// Kth Ancestor
int KthAncestor(Node* root, int node, int k){   //O(n )
    if(root == NULL){
        return -1;
    }
    if(root->data == node){
        return 0;
    }

    int leftDist = KthAncestor(root->left, node, k);
    int rightDist = KthAncestor(root->right,node , k);

    if(leftDist == -1 && rightDist == -1){
        return -1;
    }

    int validVal = leftDist == -1 ? rightDist : leftDist;
    if(validVal + 1 == k){
        cout<<"Kth Ancestor : "<< root->data<<endl;
    }

    return validVal + 1;
}

// Transform to Sum tree
int transform(Node* root){      //O(n)
    if(root == NULL) return 0;

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->data;

    root->data = leftOld + rightOld;
    if(root->left != NULL)
        root->data += root->left->data;
    if(root->right != NULL)
        root->data += root->right->data;
    return currOld;
}
int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    KthLevel(root,3);

    int n1 = 5, n2 = 3;
    cout<<"lca = "<<LCA(root,n1,n2) << endl;
    cout<<"lca = "<<LCA2(root,n1,n2)->data << endl;

    cout<<"min dist = " <<minDist(root, n1, n2)<<endl;

    int node = 4, k = 2;
    KthAncestor(root, node, k);

    transform(root);
    levelOrder2(root);
return 0; 
}