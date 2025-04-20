#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int val){
        data=val;
        prev=NULL;
        next=NULL;

    }

};
void  traverse(Node *head)
{
    Node *trav=head;
    while(trav!=NULL)
    {
        cout<<trav->data<<" ";
        trav=trav->next;
    }
    cout<<endl;
}
int main()
{
    Node *head=NULL;
    Node *tail=NULL;
    int arr[]={1,2,3,4,5};
    for(int i=0;i<5;i++)
    {
        if(head==NULL)
        {
            head=new Node(arr[i]);
            tail=head;
        }
        else
        {
            Node *temp=new Node(arr[i]);
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
    
    
        }
    }
    traverse(head);
    int pos,element;
    cin>>pos>>element;
    //insert
    if(pos==0)
    {
        Node *ins=new Node(element);
        ins->next=head;
        head->prev=ins;
        head=ins;

    }
    else {
        Node *curr=head;
        while (--pos)
        {
            curr=curr->next;
        }
        if(curr->next==NULL)
        {
            Node *temp=new Node(element);
            temp->prev=curr;
            curr->next=temp;
        }
        else
        {
            Node *temp=new Node(element);
            temp->next=curr->next;
            temp->prev=curr;
            curr->next=temp;
            temp->next->prev=temp;
        }
    }
    traverse(head);

}