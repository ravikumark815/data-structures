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

    if (root == NULL) {
        root = temp;
        return;
    }
    temp->right = root;
    root = temp;
    root->right->left = temp;
    
    printf("%d has been inserted at the beginning\n", root->data);    
    return;
}

/*
Function    : delete
Purpose     : To delete a node from the binary tree
*/

void delete()
{
    NODE cur = root;
    
    if (cur == NULL) {
        printf("\n>>> Error: Binary Tree Empty <<<\n");
        return;
    }
    root = root->right;
    root->left = NULL;
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
    if (root == NULL) {
        printf("\n>>> Error: Binary Tree Empty <<<\n");
        return;
    }
    
    NODE cur = root;
    int count = 0;
    
    printf("\n");
    while (cur->right != NULL){
        printf("|%d|->", cur->data);
        cur = cur->right;
        count++;
    }
    printf("|%d|\n", cur->data);
    printf("\nNo. of nodes: %d\n", count+1);
    
    return;
}

int main()
{
    int choice;
    
    printf("\n------- Binary Trees ------\n");

    while(1){
        printf("\n---------------------\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf(">> Choose your option:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf(">>> Error: Enter Valid Option <<<");
        }
    }
}