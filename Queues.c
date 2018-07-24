/*

Author: https://github.com/ravikumark815

------- Queue -------

Enqueue : Pushing Elements to Queue
Dequeue : Popping Elements from Queue
Display : Display current elements in Queue

*/
#include<stdio.h>

void enqueue();
void dequeue();
void display();
int queue[50];
int rear=-1;
int front=0;
int size=0;
int main()
{
    int choice;
    
    
    printf("\n------- Queue ------\n");
    printf("\nEnter the size of queue(Max 50):\t");
    scanf("%d",&size);
    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("\nChoose your option:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf("\n>> Error: Enter Valid Option <<\n");
        }
    }
}

void enqueue()
{
    int elem;

    if((rear-front)==size-1)
    {
        printf("\n>>> Error: Queue OverFlow <<<\n");
        return;
    }
    else
    {
        printf("\nEnter the element to be inserted:\t");
        scanf("%d",&elem);
        queue[++rear]=elem;
        printf("%d has been pushed\n",queue[rear]);
    }
    return;
}
void dequeue()
{
    int elem;
    
    if(rear<front)
    {
        printf("\n>>> Error: Queue UnderFlow <<<\n");
        return;
    }
    else
    {
        printf("\n%d has been removed\n",queue[front++]);
    }
    return;
}
void display()
{
    int i=0;
    
    if(front==-1)
    {
        printf("\n>>> Error: Queue UnderFlow <<<\n");
        return;
    }
    else
    {
        printf("\n|");
        for(i=front;i<=rear;i++)
        {
            printf(" %d |",queue[i]);
        }
        printf("\n");
    }
    return;
}