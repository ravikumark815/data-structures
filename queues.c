/*

Author: https://github.com/ravikumark815

------- Queue -------

Enqueue : Pushing Elements to Queue
Dequeue : Popping Elements from Queue
Display : Display current elements in Queue
Search  : Search for an element in Queue
Reverse : Reverse all elements in Queue

*/
#include <stdio.h>

int rear = -1;
int front = 0;
int size = 0;

#define SWAP(a,b) a=a^b; b=a^b; a=a^b;

void enqueue(int *queue)
{
    int elem;

    if ((rear - front) == size-1) {
        printf("\n>>> Error: Queue OverFlow <<<\n");
        return;
    }
    printf("\nEnter the element to be inserted:\t");
    scanf("%d", &elem);
    printf("front:%d, rear:%d\n", front, rear);
    queue[++rear] = elem;
    printf("%d has been pushed.\n", queue[rear]);
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

void search (int *queue)
{
    int i = 0, element;
    
    if (rear < front) {
        printf("front:%d, rear:%d", front, rear);
        printf("\n>>> Error: Queue Empty <<<\n");
        return;
    }
    printf("Enter the Element to be searched:\t");
    scanf("%d", &element);
    for (i = front; i <= rear; i++) {
        if (queue[i] == element) {
            printf("%d found at index: %d", queue[i], i);
            return;
        }
    }
    printf(">>> %d not found in the queue\n", element);
    return;
}

void reverse (int * queue)
{
    if (rear < front) {
        printf("front:%d, rear:%d", front, rear);
        printf("\n>>> Error: Queue Empty <<<\n");
        return;
    }
    
    for (int i = front, j = (rear); i < j; i++, j--) {
        SWAP(queue[i], queue[j]);
    }
    printf("\nQueue Reversed Successfully");
    display(queue);
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
        printf("--------------------");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Search\n5.Reverse\n6.Exit\n");
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
            case 4: search(queue);
                    break;
            case 5: reverse(queue);
                    break;
            case 6: return 0;
            default: printf("\n>> Error: Enter Valid Option <<\n");
        }
    }
}