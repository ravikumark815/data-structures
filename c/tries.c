/*

Author: https://github.com/ravikumark815

------- Tries -------

Insert : Inserting strings into trie
Delete : Deleting string from trie
Display : Display current strings in trie
Search: Search for a string in trie

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHA_SIZE 26

struct node {
    struct node *chars_arr[ALPHA_SIZE];
    bool delimiter;
};

struct node* create_node()
{
    struct node* new_node = (struct node*) malloc (sizeof(struct node));
    if (new_node == NULL){
        printf(">>> Error: Memory Insufficient\n");
        exit(1);
    }

    new_node->delimiter = false;
    for (int i=0; i<ALPHA_SIZE; i++) {
        new_node->chars_arr[i] = NULL;
    }
    return new_node;
}

void trieInsert(struct node * root)
{
    char elem[100];
    
    struct node* temp = root;
    printf("Enter the string to be inserted: ");
    scanf("%s", elem);

    for (int i=0; i<strlen(elem); i++) {
        int index = elem[i] - 'a';
        if (temp->chars_arr[index] == NULL)
            temp->chars_arr[index] = create_node();
        temp = temp->chars_arr[index];
    }
    temp->delimiter = true;

    return;
} 

void trieDisplay(struct node *root, char *buffer, int depth) {
    if (root->delimiter) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }

    for (int i = 0; i < ALPHA_SIZE; ++i) {
        if (root->chars_arr[i]) {
            buffer[depth] = 'a' + i;
            trieDisplay(root->chars_arr[i], buffer, depth + 1);
        }
    }
}

void trieSearch(struct node * root)
{
    struct node*temp = root;
    char elem[100];

    printf("Enter the string to be searched:");
    scanf("%s", elem);

    for (int i=0; i<strlen(elem); i++) {
        if (!temp->chars_arr[elem[i] - 'a']) {
            printf("\nString Not found\n");
            return;
        }
        temp = temp->chars_arr[elem[i] - 'a'];
    }

    if ((temp) && (temp->delimiter))
        printf("\nString Found");

    return;
}

void main()
{
    printf("------- Tries -------");
    struct node* root = create_node();
    int choice = 0;
    while(1){
        printf("\n---------------------\n");
        printf("1.Insert\n2.Display\n3.Search\n");
        printf("\nChoose your Option:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: trieInsert(root);
                    break;
            case 2: char buffer[100];
                    trieDisplay(root, buffer, 0);
                    break;
            case 3: trieSearch(root);
                    break;
            default: return;
        }
    }
    
    return;
}