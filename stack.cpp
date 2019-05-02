#include <stdio.h>
#define stacksize 100

int mystack[stacksize], top = -1; // global variables
void push(int value){
    if(top >= stacksize-1) printf("stack is full cannot push the value\n");
    else mystack[++top] = value;
}

void peek(){
    if(top < 0) printf("stack is Empty\n");
    else printf("%d\n", mystack[top]);
}

void pop(){
    if(top < 0) printf("stack is empty ! cannot pop any value !\n");
    else top--;
}

int main()
{
    int n,value;
    printf("\nHow many number you want to push in stack: ");
    scanf("%d", &n);


    printf("\n\nEnter the value for push in stack:\n\n");
    for(int i=0;i<n;i++){
        scanf("%d", &value);
        push(value);
    }
    printf("\n\nShow your stack value :\n\n");
     for(int i=0;i<n;i++){
       peek();
       pop();
    }
}
