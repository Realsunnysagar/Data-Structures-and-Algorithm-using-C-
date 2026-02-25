/*
1.Diameter of a Tree
    - No. of nodes in the longest path between 2 leaves
    -       1       4/5 to 6 -> dia = 5         1       10 to 7 : dia = 7 (this will be consideres)
          /   \                                / \      10 to 3 : dia = 6
         2     3                              2   3     7 to 3  : dia = 6
        / \     \                            / \ 
       4   5     6                          4   5
                                           /     \
                                     10 - 9       6 - 7
    Approach 01  O(n^2)
    - 1.through the root -> leftHt + rightHt + 1   (5)
    - 2.subtree leftsubtree rightsubtree -> leftDiam(3), rightDiam(2)
    - currDiam = 5, leftDiam = 3, rightDiam = 2 (maximum among these)
    - diam(root){
        if(root == NULL) return 0;
        currDiam = height(left) + height(right) + 1
        leftDiam = diam(root->left)
        rightDiam = diam(root->root)

        return max(currDiam, leftDiam, rightDiam)
     }
    
    Approach 02   O(n)
    - previously LD, RD is calc recusively and CD is calc in n*O(n) times
    - therefore for each node we will calculate pair=>(diameter, height) in recursion
    - leftInfo -> LD, LH
    - rightInfo -> RD, RH 
    - max( LH+RH+1 , (LD,RD))   -->diam
    - max(LH,RH) +1 -->height  now return the pair of this two
    -               1   (5,3)       (diameter, height)
                   /  \
           (3,2)  2    3   (2,2)
                 / \     \
         (1,1)  4   5(1,1) 6  (1,1)
2.Subtree of a another Tree
    -Return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
    -       1  (Root)     
           / \
          2   3             2 (subRoot)
         / \   \           / \
        4   5   6         4   5
    - 1.Find subroot in tree
            ISS(root, subRoot){
                if(root->data == subroot->data){
                    poore tree => is identical or not(identical -> structure and node values should be same)
                }
                ISS(root->left, subRoot)
                ISS(root->right, subRoot)
            }
    - 2.Base Case
            I. root == NULL && subRoot == NULL then true
            II. root == NULL || subRoot == NULL then false
    - 3. isIdentical(root1, root2){
            (root1 == root2 == NULL) return true;       //base case
            (root2 == NUll || root1== NULL) return false    //base case

            if(root1->data != root2->data)
                return false;
            return isIdentical(root1->left, root2->left)    &&
                   isIdentical(root1->right, root2->right)
         }
    - 4. will isIdentical will return smth
            returns true then true
            if false then will check other side 
3.Map in C++
    - is a STL Container
    - map(key, value)  -->key is unique and value can be repeated
    - map<int, int> m;  //Creating a map
    - m[key] = val;     //insert in a map
    - cout<< m[key];    //access val using key
    - m.count(key);     //1 if key present, 0 if key not present
    - for(auto it : m){         //loop on map
        cout<<it.first<<it.second;
      }
4.Top View of a Tree
    -            1                              1       HD of 1,4 is 0
               /  \                            /  \ 
              2    3                          2    3    HD of 2 = -1, HD of 3,5 = +1 , HD of 6 = 2
             / \   / \                         \
            4   5 4   6                         4 - 5 - 6
          Output : 4,2,1,3,6              Output : 2,1,3,6
    - Bottom view is also similar problem
    - Horizontal Distance 
    - we can say that if we traverse level wise then 1st unique HD will comes under top view
    - hd = 0 => 1, hd = -1 => 2, hd = -1 => 3, hd = 2 => 6  {arrenged using hd 2,1,3,6}
    - Approach
        1.LevelOrder Traversal(BFS)
            q<pair<Node*, HD>>              //{(1,0),(2,-1),(3,1) . . .}

            while(!q.empty()){
                curr(having two values node* and HD{if this HD doesnt exits in map then it is unique value so store in map and if it exist already then ignore}) 
            }

*/

#include <bits/stdc++.h>
#include <algorithm>
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

//Height of Tree
int height(Node* root){
    if(root == NULL) return 0;

    int leftH = height(root->left);
    int rightH = height(root->right);

    int currHt = max(leftH, rightH) + 1;
    return currHt;
}

// Diameter of a Tree (Approach 01)  //O(n^2)
int diam1(Node* root){
    if(root == NULL) return 0;

    int currDiam = height(root->left) + height(root->right) + 1;    //O(n)
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}

// Diameter of a Tree (Approach 02)     //O(n)
pair<int, int> diam2(Node* root){       //n*O(1)
    if(root == NULL) return make_pair(0, 0);

    pair<int, int> leftInfo = diam2(root->left);    //(LD,LH)
    pair<int, int> rightInfo = diam2(root->right);  //(RD, RH)

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, finalHt);
}

//is Subtree of another Tree
bool isIdentical(Node* root1, Node* root2){     //here root1 and root2 is respective nodes from both the tree
     if(root1 == NULL && root2 == NULL){
        return true;
    }else if(root1 == NULL || root2 == NULL){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    return isIdentical(root1->left, root2->left)
           && isIdentical(root1->right, root2->right);
}
bool isSubtree(Node* root, Node* subRoot){      //here root will vary but subRoot pointing to main node 2 then isIdentical is called to traverse
    if(root == NULL && subRoot == NULL){
        return true;
    }else if(root == NULL || subRoot == NULL){
        return false;
    }

    if(root->data == subRoot->data){
        // Identical for subtrees
        if(isIdentical(root, subRoot)){
            return true;
        }
    }

    int isLeftSubtree =  isSubtree(root->left, subRoot);
    if(!isLeftSubtree){
        return isSubtree(root->right, subRoot);
    }
    return true;
}

// Top View of a Tree
void topView(Node* root){
    queue<pair<Node*, int>> q; //(node, HD)
    map<int, int> m;    //{HD, node->data}

    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node*, int> curr = q.front();
        q.pop();

        Node*currNode = curr.first;
        int currHD = curr.second;

        if(m.count(currHD) == 0){   //HD is unique ->add in map
            m[currHD] = currNode->data;
        }

        if(currNode->left != NULL){
            pair<Node*, int> left = make_pair(currNode->left, currHD-1);
            q.push(left);
        }
        if(currNode->right != NULL){
            pair<Node*, int> right = make_pair(currNode->right, currHD+1);
            q.push(right);
        }
    }

    for(auto it:m){
        cout<<it.second<< " ";
    }
    cout<<endl;
}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes); 

    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right= new Node(5); 

    cout<<"Diameter = "<< diam1(root) <<endl;
    cout<<"Diameter = "<< diam2(root).first <<endl;

    cout<< isSubtree(root, subRoot) << endl;

    map<int, string> m;
    m[101] = "Rahul";
    m[110] = "Neha";
    m[131] = "Rahul";
    m[101] = "Rajat"; //will overwrite rahul to rajat
    cout<<m[101]<<endl;
    for(auto it : m){
        cout<<"Key : "<<it.first<<" ,value : "<<it.second<<endl;
      }

    topView(root);

return 0; 
}