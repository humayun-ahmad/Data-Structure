//creating a linked list
//All operation of linked list is given in the code by separate function
//You can separate all the function
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cmath>

using namespace std;

struct node{
    int info;
    struct node *next;
};
typedef struct node *nodeptr;

nodeptr getnode(void);
nodeptr insertnode(nodeptr, int value);

int i, n, value, sum=0, mn=100000, mx=0, cnt=0, item, c=0, a=0, target_value, index;
double avg, sinvalue;
nodeptr start, ptr, save, loc, New, locp;

void display(){
    ptr = start -> next;
    cout << "Status of list is: ";
    while(ptr!=0){
        cout << ptr->info << ' ';
        ptr=ptr -> next;
        cnt++;
    }
    cout << endl;
}

int find_max(){
    ptr = start -> next;
    while(ptr!=0){
        if((ptr->info)>mx)
            mx=ptr->info;
        ptr=ptr -> next;
    }
    return mx;
}

int find_min(){
    ptr = start -> next;
    while(ptr!=0){
        if((ptr->info)<mn)
            mn=ptr->info;
        ptr=ptr -> next;
    }
    return mn;
}
int find_total(){
    ptr = start -> next;
    while(ptr!=0){
        sum+=ptr->info;
        ptr=ptr -> next;
    }
    return sum;
}
void Search(int item){
    ptr = start -> next;
    while(ptr!=0){
        if(a==0){
            c++;
            if(ptr->info==item)
                a=1;
        }
        ptr=ptr -> next;
    }
    if(a==0)
        cout << item << " isn't found in the list." << endl;
    else
        printf("\n%d is found at %dth position.\n", item, c);
}
void Sort(){
    nodeptr curr;
    int tmp;
    ptr = start -> next;
    while(ptr!=0){
        curr=ptr->next;
        while(curr!=0){
            if(ptr->info > curr->info){
                tmp=ptr->info;
                ptr->info=curr->info;
                curr->info=tmp;
            }
            curr=curr->next;
        }
        ptr=ptr->next;
    }
}
void insert1(int item){
    ptr = start -> next;

    if(start->next==NULL)
        loc=0;
    else if(item<ptr->info)
        loc=0;
    else{
        save=start; ptr = start -> next;
        while(ptr!=0 && item>=ptr->info){
            save=ptr; ptr=ptr->next;
        }
        loc=save;
    }

    New=getnode();
    New=insertnode(New, item);

    if(loc==0){
        New->next=start->next;
        start->next=New;
    }
    else{
        New->next=loc->next;
        loc->next=New;
    }
}
void insert2(int target_value){
    ptr=start->next;
    a=0;
    while(ptr!=0){
        if(ptr->info==target_value){
            a++;
            break;
        }
        ptr=ptr->next;
    }
    if(a==0)
        cout << "The value after which you want to insert isn't found." << endl;
    else{
        cout << "Enter the value you want to insert: ";
        cin >> item;
        loc=ptr->next;
        New=getnode();
        New=insertnode(New, item);
        New->next=loc;
        ptr->next=New;
    }
}

void insert3(int index){
    ptr = start -> next;
    save=start;
    a=0; c=0;
    while(ptr!=0){
        c++;
        if(c==index){
            a++;
            break;
        }
        ptr=ptr->next;
    }

    if(a==0 && index!=0)
        cout << "The given node isn't found." << endl;
    else{
        cout << "Enter the value you want to insert: ";
        cin >> item;
        New=getnode();
        New=insertnode(New, item);
        if(index==0){
            New->next=start->next;
            start->next=New;
        }
        else{
            loc=ptr->next;
            New->next=loc;
            ptr->next=New;
        }
    }
}
void delete1(int item){
    ptr=start->next;
    c=0;
    if(start->next==0){
        loc=0;
        locp=0;
    }
    else if(item==ptr->info){
        loc=start->next;
        locp=0;
        c++;
    }
    else{
        save=start; ptr = start -> next;
        while(ptr!=0){
            if(ptr->info==item){
                loc=ptr;
                locp=save;
                c++;
                break;
            }
            save=ptr; ptr=ptr->next;
        }
    }
    if(c==0)
        cout << "The item isn't found in the list which you want to delete." << endl;
    else{
        if(locp==0)
            start=start->next;
        else
            locp->next=loc->next;
    }
}

int main()
{
    start=getnode();
    ptr=start;
    cout << "Enter a negative value to Terminate:" << endl;
    cin >> value;
    while(value>=0){
        if(value>=0)
            ptr=insertnode(ptr, value);
        cin >> value;
    }

    ptr -> next =0;
    ptr = start -> next;

    display();

    //Traversing
    printf("\nThere are %d numbers in the list.\n", cnt);
    printf("The maximum value is %d\n", find_max());
    printf("The minimum value is %d\n", find_min());
    printf("The total value is %d\n", find_total());
    avg=(double)sum/cnt;
    printf("The average value is %.4lf\n", avg);

    //Searching
    cout << "Enter the value you want to search: ";
    cin >> item;
    Search(item);

    //soring
    Sort();
    cout << "Status after sorting: " << endl;
    display();

    //inserting in a sorted list
    cout << "Enter the value you want to insert in the sorted list: ";
    cin >> item;
    insert1(item);
    display();

    //inserting after a given item
    cout << "Enter the value after which you want to insert: ";
    cin >> target_value;
    insert2(target_value);
    display();

    //inserting after a given node
    cout << "Enter the node number after which you want to insert: ";
    cin >> index;
    insert3(index);
    display();

    //deleting a node with a given item
    cout << "Enter the value you want to delete: ";
    cin >> item;
    delete1(item);
    display();

    cout << endl;

    return 0;
}
nodeptr insertnode(nodeptr ptr, int value){
    nodeptr q;
    q=getnode();
    q -> info=value;
    ptr->next = q;
    return q;
}
nodeptr getnode(void){
    nodeptr p;
    p=(nodeptr)malloc(sizeof(struct node));
    return p;
}

