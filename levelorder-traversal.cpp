#include<bits/stdc++.h>
using namespace std;
// Created a Node
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
//Main Function for Level Order Traversal
vector<vector<int>> levelordertraversal(Node *root){

    vector<vector<int>>ans;
    //If the root is initially empty, return empty vector as answer

    if(root==NULL) return ans;
// Create a queue of Node type and push root into it

    queue<Node*>q;
    q.push(root);

// while q doesn't become empty, create a 1-D level vector and push all the data into it alongwith checking for the left and right nodes and pushing them
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            Node *node=q.front();
            q.pop();
            if(node -> left !=NULL) q.push(node ->left);
            if(node -> right !=NULL) q.push(node ->right);
            level.push_back(node ->data);
        }
        ans.push_back(level);
    }
    return ans;
}
// Function to print each level of a 2 - D vector

void printlevel(const vector<int>&vec){
    for(auto it : vec){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    Node *root=new Node(1);
    root->left= new Node(2);
    root ->right =new Node(3);
    root->left->left=new Node(4);
    root -> left ->right=new Node(5);
    root -> right ->left =new Node(6);
    root ->right ->right =new Node(7);

// Calling the function to print all the levels of the Binary Tree
    vector<vector<int>>result=levelordertraversal(root);
    for(const vector<int>it : result){
        printlevel(it);
    }
    return 0;
}