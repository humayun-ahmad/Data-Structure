#include <bits/stdc++.h>
#define MAX 6

using namespace std;
int intArray[MAX];
int font = 0;
int rear = 0;


void push(int value)
{
    if((font == 0 && rear == MAX-1) || font == rear + 1){
        printf("Overflow\n");
    }
    if(intArray[font] == NULL){
        font = 0;
        rear = 0;
    }
    else if(rear == MAX-1){
        rear = 1;
    }
    else{
        rear = rear + 1;
    }
    intArray[rear] = value;
}

void dequeue()
{
    if(intArray[font] == NULL){
        printf("Underflow\n");
    }
    int item = intArray[font];
    printf("%d\n", item);
}

void pop()
{
    if(intArray[font] == NULL){
        printf("Underflow\n");
    }
    if(font == rear){
        intArray[font] = NULL;
        intArray[rear] = NULL;
    }
    else if(font == MAX-1){
        font = 0;
    }
    else{
        font = font + 1;
    }
}

int main()
{
    memset(intArray,NULL,sizeof(intArray));

    push(4);
    push(5);
    push(6);
    dequeue();
    pop();
    dequeue();
    pop();
    dequeue();
    pop();
    push(4);
    dequeue();

    return 0;
}
