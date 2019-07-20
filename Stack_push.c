#include <stdio.h>
#define MAX 10

int stk[MAX],t=-1;

void push(int value)
{
    if(t < MAX - 1){
        stk[++t] = value;
    }
    else{
        printf("not available space\n");
    }
}

int pop()
{
    int value;
    if(t == -1){
        return -1;
    }
    else{
        value = stk[t];
        t--;
        return value;
    }
}

int main()
{
    int n,value,temp;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter your value for push in stack: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        push(value);
    }

    for(int i = 0; i < n+3; i++){
        temp = pop();
        if(-1 == temp){
            printf("stack is empty\n");
        }
        else{
            printf("output = %d\n", temp);
        }
    }

    return 0;
}
