/*

Author: https://github.com/ravikumark815

------- Binary Trees -------

Insert : Inserting Elements to Binary Tree
Delete : Deleting Elements from Binary Tree
Display : Display current elements in Binary Tree

*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node* NODE; // Declare a type named NODE for easy use
NODE root;

void init_list()
{
    root = NULL;
}

/*
Function    : create_node
Purpose     : To create a new NODE with given data and childs as NULL
*/
NODE create_node()
{
    int data;
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    
    printf("Enter the element to Insert:\t");
    scanf("%d", &data);
    if (temp == NULL) {
        printf(">>> Error: Insufficient Memory\n");
        exit (0);
    }
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

/*
Function    : insert
Purpose     : To insert node into the binary tree
*/
void insert()
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
Function    : delete
Purpose     : To delete a node from the binary tree
*/

void delete()
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
Function    : Display
Purpose     : To display the current elements in binary tree
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