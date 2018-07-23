/*

Author: https://github.com/ravikumark815

------- Stack -------

Enstack : Pushing Elements to Stack
Destack : Popping Elements from Stack
Display : Display current elements in Stack

*/
#include<stdio.h>

void enstack();
void destack();
void display();
int stack[50];
int top=-1;
int size=0;
int main()
{
    int choice;
    
    
    printf("\n------- Stacks ------\n");
    printf("\nEnter the size of stack(Max 50):\t");
    scanf("%d",&size);
    while(1){
        printf("\n1.Enstack\n2.Destack\n3.Display\n4.Exit\n");
        printf("Choose your option:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enstack();
                    break;
            case 2: destack();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf("Error: Enter Valid Option");
        }
    }
}

void enstack()
{
    int elem;

    if(top==size-1)
    {
        printf("\n Error: Stack OverFlow \n");
        return;
    }
    else
    {
        printf("Enter the element to be inserted:\t");
        scanf("%d",&elem);
        stack[++top]=elem;
        printf("\n%d has been pushed\n",stack[top]);
    }
    return;
}
void destack()
{
    int elem;
    
    if(top==-1)
    {
        printf("\n Error: Stack UnderFlow \n");
        return;
    }
    else
    {
        printf("\n%d has been removed",stack[top--]);
    }
    return;
}
void display()
{
    int i=0;
    
    printf("Display\n\n");
    if(top==-1)
    {
        printf("\n Error: Stack UnderFlow \n");
        return;
    }
    else
    {
        printf("\n|");
        for(i=0;i<=top;i++)
        {
            printf(" %d |",stack[i]);
        }
        printf("\n");
    }
    return;
}