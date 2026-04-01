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

vector<int> inordertraversal(Node *root){
    vector<int>ans;
    Node *node=root;
    stack<Node *>st;
    if(root==NULL) return ans;
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()) break;
            node =st.top();
            st.pop();
            ans.push_back(node->data);
            node=node->right;
        }
    }
    return ans;
}

int main() {
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = inordertraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
