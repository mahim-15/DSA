#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

// Function to evaluate postfix expression
int evaluatePostfix(string expr) {
    stack<int> st;
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        // If it's an operand, push to stack
        if (isdigit(token[0])) {
            st.push(stoi(token));
        }
        // If it's an operator, pop two elements and compute
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            switch (token[0]) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top(); // Final result
}

// Driver Code
int main() {
    string expression = "10 2 8 * + 3 -";
    cout<<"Enter postfix expression: ";
    getline(cin,expression);
    //cin>>expression;
    cout << "Result: " << evaluatePostfix(expression) << endl; // Output: 23
    return 0;
}

