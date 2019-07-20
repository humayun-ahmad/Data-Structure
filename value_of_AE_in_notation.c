#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 10

int stk[MAX],t=-1;

int oparation(int a,int b, char ch)
{
    int value;
   if(ch == '+') value = b+a;
   else if(ch == '-') value = b - a;
   else if(ch == '*') value = b * a;
   else if(ch == '^') value = pow(b,a);
   else value = b / a;
   return value;
}

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
    printf("Please enter the postfix string separated by comma\n");
    char ch[100];
    scanf("%s", ch);
    int len = strlen(ch);
    int A,B,num=0;
    for(int i = 0; i < len; i++){
        if(isdigit(ch[i])){
            int x = ch[i] - '0';
            num = num*10 + x;
        }
        else if(ch[i] == ','){
            push(num);
            num = 0;
        }
        else{
            int a = pop();
            int b = pop();
            printf("a = %d b = %d\n", a,b);
            push(oparation(a,b,ch[i]));
        }
    }

    printf("Output is %d \n", pop());

    return 0;
}

