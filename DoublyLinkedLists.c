/*

Author: https://github.com/ravikumark815

------- Doubly Linked Lists -------

Enlink : Inserting Elements to Linked List
Delink : Deleting Elements from Linked List
Display : Display current elements in Linked List

*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};

typedef struct node* NODE; // Declare a type named NODE for easy use
NODE first;

void init_list()
{
    first = NULL;
}

/*
Function    : create_node
Purpose     : To create a new NODE with data and link->NULL
*/
NODE create_node()
{
    int data;
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    
    printf("Enter the element to Enlink:\t");
    scanf("%d", &data);
    if (temp == NULL) {
        printf(">>> Error: Insufficient Memory\n");
        exit (0);
    }
    temp->data = data;
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}

/*
Function    : enlink_first
Purpose     : To insert node at the beginning of list
*/
void enlink_start()
{
    NODE temp;
    
    temp = create_node();

    if (first == NULL) {
        first = temp;
        return;
    }
    temp->rlink = first;
    first = temp;
    first->rlink->llink = temp;
    
    printf("%d has been inserted at the beginning\n", first->data);    
    return;
}

/*
Function    : enlink_end
Purpose     : To insert node at the end of list
*/
void enlink_end()
{
    NODE temp, cur = first;
    temp = create_node();

    while(cur->rlink != NULL) {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    printf("%d has been inserted at the end\n", temp->data);
    
    return;
}

/*
Function    : enlink_pos
Purpose     : To insert node at a given position
*/
void enlink_pos()
{
    int choice, pos;
    NODE temp, cur = first, next;
    
    temp = create_node();

    printf("\nEnter the value of element after which new element will be inserted: ");
    scanf("%d", &pos);
    while (cur->data != pos) {
        cur = cur->rlink;
    }
    next = cur->rlink;
    temp->rlink = next;
    temp->llink = cur;
    cur->rlink = temp;
    if(next) next->llink = temp;
    printf("%d has been inserted after %d", temp->data, cur->data);

    return;
}

/*
Function    : delink_first
Purpose     : To delete node at the beginning of list
*/
void delink_start()
{
    NODE cur = first;
    
    if (cur == NULL) {
        printf("\n>>> Error: Linked List UnderFlow <<<\n");
        return;
    }
    first = first->rlink;
    first->llink = NULL;
    free(cur);
    
    printf("\nFirst element deleted\n");
    return;
}

/*
Function    : delink_end
Purpose     : To delete node at the end of list
*/
void delink_end()
{
    NODE cur = first, prev = NULL;
    
    if (cur == NULL) {
        printf("\n>>> Error: Linked List UnderFlow <<<\n");
        return;
    }
    while (cur->rlink != NULL) {
        prev = cur;
        cur = cur->rlink;
    }
    prev->rlink = NULL;
    free(cur);
    
    printf("\nLast element deleted\n");
    return;
}

/*
Function    : delink_pos
Purpose     : To delete a node after given pos
*/
void delink_pos()
{
    int choice, pos;
    NODE cur = first, next = NULL;

    
    if (cur == NULL) {
        printf("\n>>> Error: Linked List UnderFlow <<<\n");
        return;
    }
    printf("\nEnter the element whose next node should be deleted: ");
    scanf("%d", &pos);
    while (cur->data != pos) {
        cur = cur->rlink;
    }
    next = cur->rlink;
    cur->rlink = next->rlink;
    next->rlink->llink = cur;
    printf("%d has been deleted", next->data);
    free(next);
    return;
}

/*
Function    : Display
Purpose     : To display the current status of the linked list
*/
void display()
{
    if (first == NULL) {
        printf("\n>>> Error: Linked List Underflow <<<\n");
        return;
    }
    
    NODE cur = first;
    int count = 0;
    
    printf("\n");
    while (cur->rlink != NULL){
        printf("|%d|->", cur->data);
        cur = cur->rlink;
        count++;
    }
    printf("|%d|\n", cur->data);
    printf("\nNo. of nodes: %d\n", count+1);
    
    return;
}

int main()
{
    int choice, enlink_choice, delink_choice;

    printf("\n------- Doubly Linked List -------");

    init_list();
    while(1) {
        printf("\n----------------------------------\n");
        printf("1.Enlink\n2.Delink\n3.Display\n4.Exit\n");
        printf(">> Choose your Option:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\n1.Enlink at Start\n2.Enlink at End\n3.Enlink after a node\n");
                    printf("\nChoose your Option:\t");
                    scanf("%d", &enlink_choice);
                    switch(enlink_choice)
                    {
                        case 1: enlink_start();
                                break;
                        case 2: enlink_end();
                                break;
                        case 3: enlink_pos();
                                break;
                        default: printf("\n>> Error: Enter Valid Option <<\n");
                    }
                    break;
            case 2: printf("\n1.Delink first\n2.Delink last\n3.Delink after a node\n");
                    printf("\nChoose your Option:\t");
                    scanf("%d", &delink_choice);
                    switch(delink_choice)
                    {
                        case 1: delink_start();
                                break;
                        case 2: delink_end();
                                break;
                        case 3: delink_pos();
                                break;
                        default: printf("\n>> Error: Enter Valid Option <<\n");
                    }
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf("\n>> Error: Enter Valid Option <<\n");
        }
    }
}