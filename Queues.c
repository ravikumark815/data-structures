/*

Author: https://github.com/ravikumark815

------- Queue -------

Enqueue : Pushing Elements to Queue
Dequeue : Popping Elements from Queue
Display : Display current elements in Queue

*/
#include <stdio.h>

int rear = -1;
int front = 0;
int size = 0;

void enqueue(int *queue)
{
    int elem;

    if ((rear - front) == size-1) {
        printf("\n>>> Error: Queue OverFlow <<<\n");
        return;
    }
    else {
        printf("\nEnter the element to be inserted:\t");
        scanf("%d", &elem);
        printf("front:%d, rear:%d\n", front, rear);
        queue[++rear] = elem;
        printf("%d has been pushed.\n", queue[rear]);
    }
    return;
}
void dequeue(int *queue)
{
    int elem;
    
    if (rear < front) {
        printf("\n>>> Error: Queue UnderFlow <<<\n");
        return;
    }
    else {
        printf("front:%d, rear:%d\n", front, rear);
        printf("\n%d has been removed\n", queue[front++]);
    }
    return;
}
void display(int *queue)
{
    int i=0;
    
    if (rear < front) {
        printf("front:%d, rear:%d", front, rear);
        printf("\n>>> Error: Queue Empty <<<\n");
        return;
    }
    else {
        printf("front:%d, rear:%d\n", front, rear);
        printf("\n|");
        for (i = front; i <= rear; i++) {
            printf(" %d |", queue[i]);
        }
        printf("\n");
    }
    return;
}

int main()
{
    int choice;
    
    printf("\n------- Queue ------\n");
    printf("\nEnter the size of queue:\t");
    scanf("%d", &size);
    int queue[size];

    while(1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("\nChoose your option:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: enqueue(queue);
                    break;
            case 2: dequeue(queue);
                    break;
            case 3: display(queue);
                    break;
            case 4: return 0;
            default: printf("\n>> Error: Enter Valid Option <<\n");
        }
    }
}