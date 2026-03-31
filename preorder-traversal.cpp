#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorder(Node *root,vector<int>&vec){
 if(root == NULL) return;
 vec.push_back(root -> data);
 preorder(root -> left,vec);
 preorder(root -> right, vec);
}

vector<int>preOrder(Node *root){
     vector<int>vec;
     preorder(root,vec);
     return vec;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = preOrder(root);

    for(auto it : result){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}