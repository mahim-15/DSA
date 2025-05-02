#include<bits/stdc++.h>
#include<stack>
#include <sstream>
using namespace std;
int postfix(const string &s){
    stack<int>st;
    stringstream ss(s);
    string token;
    while(ss>>token){
        if(isdigit(token[0])){
            st.push(stoi(token));
        }
        else{
            int op2=st.top();st.pop();
            int op1=st.top();st.pop();
            switch (token[0])
            {
            case '+':
               st.push(op2+op1);
                break;
                case '-':
               st.push(op1-op2);
                break;
                case '*':
               st.push(op2*op1);
                break;
                case '/':
               st.push(op1/op2);
                break;
            
            
            }
        }
    }
    return st.top();

}
int main(){
 string s;
 getline(cin,s);
 cout<<"Postfix="<<postfix(s);
}