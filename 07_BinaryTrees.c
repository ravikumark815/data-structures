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

/*
Function    : insert
Purpose     : To insert node into the binary tree
*/
NODE insert(NODE root, int element)
{
    if (root == NULL) {
        root = (NODE)malloc(sizeof(struct node));;
        if (root == NULL) {
            printf(">>> Error: Insufficient Memory\n");
            exit (0);
        }
        root->data = element;
        root->left = NULL;
        root->right = NULL;
        printf("%d has been inserted\n", root->data);
    }

    if (element < root->data) {
        root->left = insert(root->left, element);
    }
    else if (element > root->data){
        root->right = insert(root->right, element);
    }
    return root;
}

/*
Function    : delete
Purpose     : To delete a node from the binary tree
*/

NODE delete(NODE root, int element)
{
    if (root == NULL) {
        printf("%d doesn't exist in tree.\n", element);
        return NULL;
    }
    if (element < root->data) {
        root->left = delete(root->left, element);
    }
    else if (element > root->data) {
        root->right = delete(root->right, element);
    }
    else if (root->data == element) { 
        if (root->left && root->right){

        }
        else if (root->left == NULL){
            root = root->right;
        }
    }
    
    
    
}

/*
Function    : Display
Purpose     : To display the current elements in binary tree
*/
void display(NODE root, int level)
{
    if (root == NULL) {
        return;
    }

    for (int i = 0; i <= level; i++) {
        printf("  ");
    }
    printf("%d\n", root->data);

    display(root->left, level + 1);
    display(root->right, level + 1);
}

int main()
{
    int choice, element;
    
    printf("\n------- Binary Trees ------\n");

    NODE root = NULL;
    while(1){
        printf("\n---------------------\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf(">> Choose your option:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the element to be inserted: ");
                    scanf("%d", &element);
                    root = insert(root, element);
                    break;
            case 2: printf("Enter the element to be deleted: ");
                    scanf("%d", &element);
                    delete(root, element);
                    break;
            case 3: display(root, 0);
                    break;
            case 4: return 0;
            default: printf(">>> Error: Enter Valid Option <<<");
        }
    }
}