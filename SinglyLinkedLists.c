/*

Author: https://github.com/ravikumark815

------- Singly Linked Lists -------

Enlink : Inserting Elements to Linked List
Delink : Deleting Elements from Linked List
Display : Display current elements in Linked List

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} Node;

typedef struct Node* NODE; // Declare a type named NODE for easy use

NODE first = NULL; // Pointing first node to NULL

/*
Function    : Enlink
Purpose     : To add a node at given position
*/
void enlink()
{
    int item, choice, pos;
    NODE temp, cur = first;
    
    printf("Enter the element to Enlink:\t");
    scanf("%d", &item);
    temp = (NODE)malloc(sizeof(NODE));
    temp->data = item;
    if (first == NULL){
        first = temp;
        temp->link = NULL;
        printf("%d has been inserted at the beginning\n", cur->data);
        return;
    }
    else {
        printf("\n1.Beginning\n2.Ending\n3.InBetween");
        printf("\nPosition to be inserted in:\t");
        scanf("%d", &choice);
        if (choice == 1) {
            first = temp;
            temp->link = NULL;
            printf("%d has been inserted at the beginning\n", cur->data);
        }
        else if (choice == 2) {
            while(cur->link!=NULL)
                cur = cur->link;
            cur->link = temp;
            temp->link = NULL;
            printf("%d has been inserted at the ending\n", temp->data);
        }
        else if (choice == 3) {
            NODE prev;
            printf("\nEnter the value of element before which the element should be inserted\t:");
            scanf("%d", &pos);
            while (cur->data != pos) {
                prev = cur;
                cur = cur->link;
            }
            cur = cur->link;
            prev->link = temp;
            temp->link = cur;
            printf("%d has been inserted before %d", temp->data, pos);
        }
    }
    return;
}

/*
Function    : Delink
Purpose     : To delete a node at given position
*/
void delink()
{
    int choice, pos;
    NODE cur, prev;

    cur = first;
    
    if (cur->link = NULL) {
        printf("\n>>> Error: Linked List UnderFlow <<<\n");
        return;
    }
    else {
        printf("\n1.Beginning\n2.Ending\n3.InBetween");
        printf("\nPosition to be deleted from:\t");
        scanf("%d", &choice);
        if (choice == 1) {
            first = cur->link;
            printf("%d has been deleted\n", cur->data);
            free(cur);
        }
        else if (choice == 2) {
            while(cur->link!=NULL)
                cur = cur->link;
            prev = cur;
            prev->link = NULL;
            cur = cur->link;            
            printf("%d has been deleted\n", cur->data);
            free(cur);
        }
        else if (choice == 3) {
            printf("\nEnter the element before which the element should be deleted\t:");
            scanf("%d", &pos);
            while (cur->data != pos) {
                prev = cur;
                cur = cur->link;
            }
            prev->link = cur->link;
            printf("%d has been deleted", cur->data);
            free(cur);
        }
    }
    return;
}

/*
Function    : Display
Purpose     : To display the current status of the linked list
*/
void display()
{
    NODE cur = first;

    if (cur->link == NULL) {
        printf("\n>>> Error: Linked List Underflow <<<\n");
    }
    else {
        while (cur->link != NULL){
            printf("%d -> ", cur->data);
            cur = cur->link;
        }
        printf("%d\n", (cur->link)->data);
    }
}


int main()
{
    int choice;

    printf("\n------- Singly Linked List -------\n");

    while(1) {
        printf("\n1.Enlink\n2.Delink\n3.Display\n4.Exit\n");
        printf("\nChoose your Option:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: enlink();
                    break;
            case 2: delink();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf("\n>> Error: Enter Valid Option <<\n");
        }
    }
}