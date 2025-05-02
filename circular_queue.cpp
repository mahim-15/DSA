#include<bits/stdc++.h>
using namespace std;
const int N=5;
int queu[N];
int front=-1;
int rear=-1;
void enqueu(int x){
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queu[front]=x;

    }
    else if((rear+1)%N==front){
        cout<<"Queue is full !!"<<endl;

        return;
    }
    else{
        rear=(rear+1)%N;
        queu[rear]=x;
       
    }
   
}
void dequeu(){
    if(front==-1 && rear==-1){
        cout<<"Queue is empty!!"<<endl;
        return;

    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        cout<<"Dequeed elemenets:"<<queu[front]<<endl;
        front=(front+1)%N;

    }

}
void display(){
    for(int i=0;i<N;++i){
        cout<<queu[i]<<" - ";
    }
    cout<<endl;

}

int main(){

    enqueu(2);
    enqueu(-1);
    enqueu(5);
    enqueu(6);
    enqueu(7);
    display();
    dequeu();
    dequeu();
    display();
    enqueu(0);
    display();
    enqueu(11);
    enqueu(12);


}