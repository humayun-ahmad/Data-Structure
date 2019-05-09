#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc,value;
    string s;
    cin >> tc;
    getchar();
    stack<char>myStack;
    while(tc--){
        getline(cin,s);

        if(s.compare("\n")==0){
            printf("Yes\n");
            continue;
        }
        if(s.size() == 1 || s.size()%2 == 1){
            cout << "No" <<endl;
            continue;
        }

        for(int i=0;i<s.size();i++){
            if(!myStack.empty() && myStack.top() == '[' && s[i] == ']'){
                myStack.pop();
            }
            else if(!myStack.empty() && myStack.top() == '(' && s[i] == ')'){
                myStack.pop();
            }
            else{
                myStack.push(s[i]);
            }
        }

        if(!myStack.empty()) cout << "No" <<endl;
        else cout << "Yes" <<endl;

        while(!myStack.empty()){
            myStack.pop();
        }
    }

    return 0;
}

