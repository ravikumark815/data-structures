/*

Author: https://github.com/ravikumark815

------- Stack -------

Enstack : Pushing Elements to Stack
Destack : Popping Elements from Stack
Display : Display current elements in Stack
Search  : Search for an element in Stack
Reverse  : Reverse all elements in Stack

*/
#include <stdio.h>

#define SWAP(a,b) a = a ^ b; b = a ^ b; a = a ^ b;

int top = -1;
int size =  0;

void enstack (int *stack)
{
    int elem;

    if (top == size-1) {
        printf("\n>>> Error: Stack OverFlow! <<<\n");
        return;
    }
    else {
        printf("\nEnter the element to be inserted:\t");
        scanf("%d",&elem);
        stack[++top] = elem;
        printf(">> %d has been inserted\n",stack[top]);
    }
    return;
}

void destack (int *stack)
{
    int elem;
    
    if (top == -1) {
        printf("\n >>> Error: Stack UnderFlow! <<<\n");
        return;
    }
    else {
        printf(">> %d has been removed\n",stack[top--]);
    }
    return;
}

void display (int *stack)
{
    int i=0;
    
    if (top == -1) {
        printf("\n >>> Error: Stack UnderFlow! <<<\n");
        return;
    }
    else {
        printf("\n|");
        for (i = 0; i <= top; i++) {
            printf(" %d |", stack[i]);
        }
        printf("\n");
    }
    return;
}

void search (int *stack)
{
    int i = 0, element;
    
    if (top == -1) {
        printf("\n >>> Error: Stack UnderFlow! <<<\n");
        return;
    }
    else {
        printf("Enter the Element to be searched:\t");
        scanf("%d", &element);
        for (i = 0; i <= top; i++) {
            if (stack[i] == element) {
                printf("%d found at index: %d", stack[i], i);
                return;
            }
        }
    }
    return;
}

void reverse (int * stack)
{
    if (top == -1) {
        printf("\n >>> Error: Stack UnderFlow! <<<\n");
        return;
    }
    
    for (int i = 0, j = (top); i < j; i++, j--) {
        SWAP(stack[i], stack[j]);
    }
    printf("\nStack Reversed Successfully");
    display(stack);
    return;
}

int main()
{
    int choice;
    
    printf("\n------- Stacks ------\n");
    printf("\nEnter the size of stack:\t");
    scanf("%d", &size);
    int stack[size];

    while(1){
        printf("\n---------------------\n");
        printf("1.Enstack\n2.Destack\n3.Display\n4.Search\n5.Reverse\n6.Exit\n");
        printf(">> Choose your option:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: enstack(stack);
                    break;
            case 2: destack(stack);
                    break;
            case 3: display(stack);
                    break;
            case 4: search(stack);
                    break;
            case 5: reverse(stack);
                    break;
            case 6: return 0;
            default: printf(">>> Error: Enter Valid Option <<<");
        }
    }
}