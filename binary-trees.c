/*

Author: https://github.com/ravikumark815

------- Binary Trees -------

Insert              : Inserting Elements to Binary Tree
Delete              : Deleting Elements from Binary Tree
Display             : Display current elements in Binary Tree
findMax             : Returns highest element of the tree
findMin             : Returns lowest element of the tree
findHeight          : Find the Height of the tree
inorder_traversal   : Inorder traversal of the tree
preorder_traversal  : Preorder traversal of the tree
postorder_traversal : Postorder traversal of the tree

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

int tree_size = 0;

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
        tree_size++;
        printf("%d has been inserted. Current Size: %d\n", root->data, tree_size);
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
        printf("Deletion Successful. Current Size:%d\n", --tree_size);
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
Function    : findHeight
Purpose     : To find the height of a binary tree
*/
int findHeight(NODE root)
{
    if(root == NULL) {
        return 0;
    }
    int left_height = findHeight(root->left);
    int right_height = findHeight(root->right);

    return ((left_height > right_height)? (left_height + 1): (right_height + 1));
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
Purpose     : To find the postorder traversal of a binary tree
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

/*
Function    : levelorder_traversal
Purpose     : To find the levelorder traversal of a binary tree
*/
void levelorder_traversal(NODE root)
{
    if (root == NULL)
        return;

    // Create a queue to hold node pointers
    NODE queue[tree_size];
    int front = 0, rear = 0;

    printf("\nLevel Order Traversal: %d\n", tree_size);

    // Enqueue the root node
    queue[rear++] = root;

    while (front < rear) {
        // Dequeue a node and print its data
        NODE cur = queue[front++];
        printf("%d ", cur->data);

        // Enqueue left child if exists
        if (cur->left != NULL)
            queue[rear++] = cur->left;

        // Enqueue right child if exists
        if (cur->right != NULL)
            queue[rear++] = cur->right;
    }

    return;
}

int main()
{
    int choice, element;
    
    printf("\n------- Binary Trees ------\n");

    NODE root = NULL;
    while(1){
        printf("\n---------------------\n");
        printf("\n0.Preload Tree\n"
                "1.Insert\n"
                "2.Delete\n"
                "3.Display\n"
                "4.Highest Element\n"
                "5.Lowest Element\n"
                "6.Height of the Tree\n"
                "7.Inorder Traversal\n"
                "8.Preorder Traversal\n"
                "9.Postorder Traversal\n"
                "10.Levelorder Traversal\n"
            );
        printf(">> Choose your option:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 0: root = insert(root, 100);
                    root = insert(root, 50);
                    root = insert(root, 150);
                    root = insert(root, 30);
                    root = insert(root, 70);
                    root = insert(root, 130);
                    root = insert(root, 170);
                    root = insert(root, 20);
                    root = insert(root, 40);
                    root = insert(root, 60);
                    root = insert(root, 80);
                    root = insert(root, 110);
                    root = insert(root, 140);
                    root = insert(root, 160);
                    root = insert(root, 180);
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
            case 10: levelorder_traversal(root);
                    break;
            default: return 0;
        }
    }
}