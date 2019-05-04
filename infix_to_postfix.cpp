#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int operatorPrecedence(char ch)
{
    if(ch == '^') return 5;
    else if(ch == '/') return 4;
    else if(ch == '*') return 3;
    else if(ch == '+') return 2;
    else if(ch == '-') return 1;
    else return 0;
}

string convertInfixToPostfix(string infix)
{
    string postfix = "";
    stack <char> myStack;
    char ch;

    for(int i = 0; infix[i]; i++){
        ch = infix[i];
        if(ch == '(') // if found closing bracket
                myStack.push(ch);
        else if(ch == ')'){ //if found closing bracket
            while(!myStack.empty() && myStack.top() != '('){
                    postfix = postfix + myStack.top();
                    myStack.pop();
                  }
                  if(!myStack.empty() && myStack.top() == '(')
                        myStack.pop();
        }
        else{ // found operator or operand
            int priority = operatorPrecedence(ch);
            if(priority == 0)// found operand
                postfix = postfix + ch;
            else{ // found operator
                if(myStack.empty())
                    myStack.push(ch);
                else{
                    while(!myStack.empty() && myStack.top()!= '(' && priority <= operatorPrecedence(myStack.top())){
                        postfix = postfix + myStack.top();
                        myStack.pop();
                    }
                    myStack.push(ch);
                }
            }
        }
    }
    while(!myStack.empty()){
        postfix += myStack.top();
        myStack.pop();
    }
    return postfix;
}

int Calculate(int a, int b, char ch)
{
    int op = operatorPrecedence(ch);
    if(op==1) return a-b;
    else if(op==2) return a+b;
    else if(op==3) return a*b;
    else if(op==4) return a/b;
    else if(op==5)return pow(a,b);
    else return 0;
}

int evaluate_postfix(string postfix)
{
    stack<int>myStack;
    char ch;
    int a,b;
    for(int i=0; postfix[i]; i++){
        ch = postfix[i];
        if(ch >= '0' && ch <= '9')
            myStack.push(ch - '0');
        else{
            b = myStack.top();
            myStack.pop();
            a = myStack.top();
            myStack.pop();
            int result = Calculate(a,b,ch);
        //cout << result <<endl;
            myStack.push(result);
        }
    }
    return myStack.top();
}


int main()
{
    string s,p;
    int tc;
    cin >> tc;
    getchar();
    while(tc--){
        cin >> s;
        p = convertInfixToPostfix(s);
        cout << p <<endl;

        int result = evaluate_postfix(p);
        cout << result <<endl;
    }
        return 0;
}
