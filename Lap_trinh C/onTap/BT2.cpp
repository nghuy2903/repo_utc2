#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int x = 0){
            data = x;
            left = right =  nullptr;
        }
};

class BST{
    Node* root;
    public:
        BST(){root = nullptr;}
        void them(Node* &head, int x);
        void in(Node* head);

        Node* &getRoot(){return root;}

};

void BST::them(Node* &head, int x){
     
    if(head == nullptr) head = new Node(x);
    else {
        if(x > head->data) them(head->right, x);
        else if(x < head->data) them(head->left, x);
    }
}

void BST::in(Node* head){
    if(head == nullptr) return;

    in(head->left);
    cout << head->data << " ";
    in(head->right);

}

int main(){
    BST ds;
    Node* root = ds.getRoot();
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        ds.them(root, x);
    }
    ds.in(root);

    return 0;
}