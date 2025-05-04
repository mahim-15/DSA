#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
   int data;
   Node *right;
   Node *left;
   Node(int v){
    data=v;
    right=left=NULL;

   }

};
Node *buildtree(){
    int val;
    cout<<"Enter value:(-1 for NULL)";
    cin>>val;
    if(val==-1){
        return NULL;

    }
 
    Node* newNode=new Node(val);
    cout << "Enter left child of " << val << endl;
    newNode->left=buildtree();
    cout << "Enter right child of " << val << endl;
    newNode->right=buildtree();
    return newNode;

}
void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root){
    if(root==NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
int main(){
    Node *root= buildtree();
    cout<<"Inorder Taverse: "<<endl;
    inorder(root);
    cout<<"Preorder Traverse: "<<endl;
    preorder(root);
    cout<<"Postorder Traversal"<<endl;
    postorder(root);

}