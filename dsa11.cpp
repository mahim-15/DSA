#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int>element;
    cout<<"Enter elements(press -1 to stop):"<<endl;
    while(true){
        int input;
        cin>>input;
        if(input==-1)
        {
            break;
        }
        element.push(input);
    }
    int choice,temp;
    while(true){
        cout<<"-------Menu------\n"<<endl;
        cout<<"1.Insert element:"<<endl;
        cout<<"2.Delete elemnt:"<<endl;
        cout<<"3.Print stack"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        if(choice==1){
            cout<<"Enter element to insert:";
        cin>>temp;
        element.push(temp);
        }
        else if(choice==2)
        {
            if(element.empty()){
                    cout<<"Stack is empty";
                }
            element.pop();
            cout<<"Element deleted form top successfully";
        }
        else if(choice==3){
                if(element.empty()){
                    cout<<"Stack is empty";
                }
                cout<<"Elements are:";
                stack<int>tempp;
                //tempp=element;
                 while (!element.empty()) {
        tempp.push(element.top());
        element.pop();
    }
                while(!tempp.empty()){
                    cout<<tempp.top()<<" " ;
                    tempp.pop();
                }
                cout<<endl;
    }
    else if(choice==4){
        cout<<"Exiting....";
        break;
    }
    else{
        cout<<"Invalid choice"<<endl;
    }
    }
}
