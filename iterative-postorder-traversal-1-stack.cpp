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

vector<int>postorder(Node *root){
    vector<int>ans;
    if(root==NULL) return ans;
    stack<Node *>st;
    Node *curr=root;
    Node *temp;
    while(curr!=NULL ||  !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            temp=st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }

            }
            else{
                curr=temp;
            }
        }
    }
    return ans;

}

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root -> right -> left =new Node(6);
    root -> right -> left -> right =new Node(7);
    root -> right -> left -> right -> right =new Node(8);
    vector<int> result = postorder(root);
    cout << "Postorder traversal: ";
    printVector(result);
    return 0;
}