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


Node* morrishTraversal(Node* root){
    Node* curr = root;
    vector<int> result;
    while (curr){
        if(!curr->left){
            result.push_back(curr->data);
            curr = curr->left;
        }else{
            // Moving left
            Node* temp = curr->left;

            // traverse till right most
            while(temp && );
        }
    }
    
}
int main() {
 
return 0; 
}