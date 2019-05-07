#include <bits/stdc++.h>
#include <string.h>
#include <cstring>
#include <cstdio>
#define MAX_SIZE 250
using namespace std;
int top=-1;
char Stack[MAX_SIZE];
void push(int value)
{
//    if(top >= MAX_SIZE-1)
//        printf("Overflow\n");
    //else
    if(top<MAX_SIZE-1)
        Stack[++top] = value;
}
char peek()
{
//    if(top < 0){
//        return 0;
//        //printf("Stack is empty\n");
//    }
    if(top>=0){
        //printf("%d", Stack[top]);
        return Stack[top];
    }
}
void pop()
{
//    if(top < 0)
//        int a;
    if(top>=0)
        top--;
}
int main()
{
    string s;
    //char s[140];
    int value,tc;
    //printf("Enter a string : ");

    cin >> tc;
    getchar();
    while(tc--){
        //gets(s);
        getline(cin,s);
        //int len = strlen(s);
        int len = s.size();
        if(len == 0){
            cout << "Yes" <<endl;
            continue;
        }
        else{
        for(int i = 0; i < len; i++){
            if(top >= 0 && peek() == '(' && s[i] == ')'){
                pop();
            }
            else if(top >= 0 && peek() == '[' && s[i] == ']'){
                pop();
            }
            else push(s[i]);
        }
        }
        if(top < 0) printf("Yes\n");
        else printf("No\n");

        while(top >= 0){
            pop();
        }

    }

    return 0;
}

