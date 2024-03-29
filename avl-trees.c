/*

Author: https://github.com/ravikumark815

------- Binary Trees -------

Insert  : Inserting Elements to Binary Tree
Delete  : Deleting Elements from Binary Tree
Display : Display current elements in Binary Tree
findMax : Returns highest element of the tree
findMin : Returns lowest element of the tree

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a > b) ? a : b; 

struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
};

typedef struct node* NODE; // Declare a type named NODE for easy use


/*
Function    : create_noew
Purpose     : To create a new node
*/
NODE create_node(int element)
{
    NODE new_node = (NODE) malloc (sizeof(struct node));
    if (new_node == NULL) {
        printf(">>Error: Memory insufficient!\n");
        exit(1);
    }
    new_node->height = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = element;

    return new_node;
}

/*
Function    : findHeight
Purpose     : To find the height of a binary tree
*/
int findHeight(NODE root)
{
    if(root == NULL)
        return 0;
    return root->height;
}

/*
Function    : getBalance
Purpose     : To find balance value at any node level
*/
int getBalance(NODE root)
{
    if (root == NULL)
        return 0;

    int leftHeight = (root->left != NULL) ? root->left->height : 0;
    int rightHeight = (root->right != NULL) ? root->right->height : 0;

    return (leftHeight - rightHeight);
}

/*
Function    : leftRotate
Purpose     : Left Rotation
*/
NODE leftRotate(NODE x)
{
    NODE y = x->right;
    NODE temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = MAX(findHeight(x->left), findHeight(x->right)) + 1;
    y->height = MAX(findHeight(y->left), findHeight(y->right)) + 1;

    return y;
}

/*
Function    : rightRotate
Purpose     : Right Rotation
*/
NODE rightRotate(NODE x)
{
    NODE y = x->left;
    NODE temp = y->right;

    y->right = x;
    x->left = temp;

    x->height = MAX(findHeight(x->left), findHeight(x->right)) + 1;
    y->height = MAX(findHeight(y->left), findHeight(y->right)) + 1;

    return y;
}

/*
Function    : findMax
Purpose     : To find the highest element in a tree
*/
NODE findMax(NODE root)
{
    if(root == NULL)
    	return NULL;
    else if(root->right == NULL)
    	return root;
    else
    	return findMax(root->right);
}

/*
Function    : findMax
Purpose     : To find the lowest element in a tree
*/
NODE findMin(NODE root)
{
    if(root == NULL)
    	return NULL;
    else if(root->left == NULL)
    	return root;
    else
    	return findMin(root->left);
}

/*
Function    : insert
Purpose     : To insert node into the AVK tree
*/
NODE insert(NODE node, int element)
{
    if (node == NULL)
        return create_node(element);

    if (element < node->data) {
        node->left = insert(node->left, element);
    }
    else if (element > node->data){
        node->right = insert(node->right, element);
    }
    else return node;

    node->height = 1 + MAX(findHeight(node->left), findHeight(node->right));
    
    int balance = getBalance(node);

    // Left Left Case 15->10->5
    if ((balance > 1) && element < node->left->data)
        return rightRotate(node);
    
    // Right Right Case 5->10->15
    if ((balance < -1) && element > node->right->data)
        return leftRotate(node);
    
    // Left Right Case 15->5->10
    if ((balance > 1) && element > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case 5->15->10
    if ((balance < -1) && element < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
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
    else if (root->left && root->right) { 
        NODE temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, root->data);
    }
    else {
        NODE temp = root;
        if(root->left == NULL)
            root = root->right;
        else if(root->right == NULL)
            root = root->left;
        free(temp);
    }
    return root;
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

    display(root->right, level + 1);
    for (int i = 0; i < level; ++i) {
        printf("   ");
    }
    printf("%d\n", root->data);

    display(root->left, level + 1);
}

/*
Function    : inorder_traversal
Purpose     : To find the inorder traversal of a binary tree
*/
void inorder_traversal(NODE root)
{
    if(root == NULL)
        return;
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);

    return;
}

/*
Function    : preorder_traversal
Purpose     : To find the preorder traversal of a binary tree
*/
void preorder_traversal(NODE root)
{
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);

    return;
}

/*
Function    : postorder_traversal
Purpose     : To find the preorder traversal of a binary tree
*/
void postorder_traversal(NODE root)
{
    if(root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);

    return;
}

int main()
{
    int choice, element;
    
    printf("\n------- AVL Trees ------\n");

    NODE root = NULL;
    while(1){
        printf("\n---------------------\n");
        printf("\n0.Prefill Tree\n"
                "1.Insert\n"
                "2.Delete\n"
                "3.Display\n"
                "4.Highest Element\n"
                "5.Lowest Element\n"
                "6.Height of the Tree\n"
                "7.Inorder Traversal\n"
                "8.Preorder Traversal\n"
                "9.Postorder Traversal\n"
            );
        printf(">> Choose your option:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 0: root = insert(root, 10); 
                    root = insert(root, 20); 
                    root = insert(root, 30); 
                    root = insert(root, 40); 
                    root = insert(root, 50); 
                    root = insert(root, 25); 
                    break; 
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
            case 4: printf("Highest Element: %d", findMax(root)->data);
                    break;
            case 5: printf("Lowest Element: %d", findMin(root)->data);
                    break;
            case 6: printf("Height: %d", findHeight(root));
                    break;
            case 7: inorder_traversal(root);
                    break;
            case 8: preorder_traversal(root);
                    break;
            case 9: postorder_traversal(root);
                    break;
            default: return 0;
        }
    }
}