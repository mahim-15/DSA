#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int v){
        data=v;
        next=NULL;
    }
};
void traverse(Node *head){
    Node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";

}
void insertHead(Node *&head,int val){
    Node *newNode=new Node(val);
    newNode->next=head;
    head=newNode;

}
void insertEnd(Node* &head,int val){
    if(head==NULL)
    {
        insertHead(head,val);
    }
    Node *newNode=new Node(val);
    Node *temp= head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;

}
void insertMid(Node *&head,int val,int pos)
{
    Node *newNode=new Node(val);
    Node *prev =head;
    int count=1;
    while(count<(pos-1))
    {
        prev=prev->next;
        count++;
    }
    newNode->next=prev->next;
    prev->next=newNode;
}
void deleteMid(Node* &head,int pos)
{
    Node *prev=head;
    int cnt=0;
    while(cnt<pos-1)
    {
        prev=prev->next;
        cnt++;
    }
    Node *crnt=prev->next;
    prev->next=crnt->next;
    free(crnt);

}


int main()
{
    Node *node1=new Node(1);
    Node *node2=new Node(2);
    Node *node3=new Node(7);
    node1->next=node2;
    node2->next=node3;
    Node *head= node1;
    insertHead(head,3);
    insertHead(head,5);
    insertEnd(head,4);
    traverse(head);
    insertMid(head,9,3);
    cout<<endl;
    traverse(head);


}