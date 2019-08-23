#include <iostream>
#include <stdio.h>
#define llu unsigned long long
using namespace std;

llu fact(llu n){
    if(n == 1)
        return 1;
    else return n * fact(n - 1);
}
int main(){
    llu n , res;
    cin>>n;
    if(n>20)
        cout<<"Can't find the value because of huge number of output  :) \n";
     cout<<fact(n)<<endl;

    return 0;
}
