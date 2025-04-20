#include<iostream>
using namespace std;
class stack{
    public:
    int top;
    int arr[5];
    int mx;
    stack(){
        top=-1;
        mx=5;

    }
    void push(int x){
        if(top>=mx-1)
        {
            cout<<"Stack Overflowed! Cannot Push!"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(top<0)
        {
            cout<<"Stack Underflow!cannot POP!"<<endl;
            return;
        }
        top--;
    }
    void display()
    {
        for(int i=0;i<=top;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};
int main()
{
    stack s;
    int elements[]={15,20,45,16,-12,30};
    for(int i=0;i<6;i++)
    {
        s.push(elements[i]);
    }
    s.display();
    for(int i=0;i<6;i++)
    {
        s.pop();
        s.display();
    }


}