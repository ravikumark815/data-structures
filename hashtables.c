/*

Author: https://github.com/ravikumark815

------- Hash Tables -------

Insert  : Inserting Elements to Hashtable
Delink  : Deleting Elements to Hashtable
Display : Display all elements in hash table

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent each data element stored
struct node {
    int key;
    int val;
    struct node *link;
};

// Structure to represent the hash table
struct HashTable {
    struct node **table; // Pointer to an array of pointers
    int table_size; // Maximum size of the hash table
    int cur_size; // Current size of the hash table

};

/*
Function    : create_hash
Purpose     : Hash function: Converts a string (name) into an index within the hash table
*/
int create_hash(int key, int table_size)
{
    return (key) % table_size;
}

/*
Function    : create_node
Purpose     : To create a new data node
*/
struct node* create_node()
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf(">>> Error: Insufficient Memory\n");
        exit (0);
    }

    int key, val;
    
    printf("\nEnter the Key:\t");
    scanf("%d", &key);
    printf("Enter the element to be inserted:\t");
    scanf("%d", &val);
    
    new_node->key = key;
    new_node->val = val;
    
    return new_node;
}

/*
Function    : init_hashtable
Purpose     : Initializes the hash table with a specified size
*/
void init_hashtable(struct HashTable* hashtable, int table_size) 
{
    hashtable->table_size = table_size;
    hashtable->cur_size = 0;
    hashtable->table = (struct node**)malloc(table_size*sizeof(struct person*));
    if (hashtable->table == NULL) {
        printf(">>> Error: Insufficient Memory\n");
        exit (0);
    }
    // Initialize each slot in the hash table to NULL
    for (int i = 0; i < table_size; i++) {
        hashtable->table[i] = NULL;
    }
}

/*
Function    : Insert
Purpose     : Inserts a new person into the hash table
*/
void insert(struct HashTable* hashtable)
{   
    struct node* new_node = create_node(); // Create a new data elem
    unsigned int index = create_hash(new_node->key, hashtable->table_size); // Generate hash key for this elem
    printf("Hash obtained:%d\n", index);

    if (hashtable->table[index] == NULL) {
        hashtable->table[index] = new_node; // Insert into the obtained index, if its NULL
    }
    else {
        printf("##%d\n", __LINE__);
        // If collision occurs (slot is not empty), handle it using separate chaining
        struct node* temp = hashtable->table[index];
        while (temp->link != NULL) { // Move to the end of the chain
            temp = temp->link;
        }
        temp->link = new_node; // Add the new person at the end of the chain
    }
    hashtable->cur_size++;
    return;
}

/*
Function    : Search
Purpose     : Search for an element in hashtable
*/
void search(struct HashTable* hashtable)
{   
    int key, index = create_hash(key, hashtable->table_size);

    printf("\nEnter the key to be deleted: ");
    scanf("%d", &key);

    struct node* temp = hashtable->table[index];
    if (hashtable->table[index] == NULL)
        printf(">> Element Not Found\n");
        return;
    
    while(temp != NULL){
        if (temp->key == key)
            printf("\nElement found at Index:%d Key:%d Value:%d", index, temp->key, temp->val);
    }
    
    return;
}

/*
Function    : Delete
Purpose     : Deletes a person from hash table
*/
void delete(struct HashTable* hashtable)
{   
    int key, index;
    
    printf("\nEnter the key to be deleted: ");
    scanf("%d", &key);

    index = create_hash(key, hashtable->table_size);

    struct node* prev;
    struct node* temp = hashtable->table[index];
    
    if (hashtable->table[index] == NULL)
        printf(">> Element Not Found\n");
    
    while(temp != NULL){
        if (temp->key == key) {
            if (temp->link)
                prev->link = temp->link;
            else
                prev->link = NULL;
            free(temp);
            printf("Deletion Successful\n");
            return;
        }
        prev = temp;
        temp = temp->link;
    }
    
    printf(">> Element Not Found\n");
    return;
}

/*
Function    : Display
Purpose     : Display all elements in hash table
*/
void display(struct HashTable* hashtable)
{   
    printf("\nDisplay:\n");
    int count = 0;
    // struct node* temp = hashtable->table[i];

    for (int i = 0; i < hashtable->table_size; i++) {
        printf("\nIndex [%d]: ", i);
        struct node* temp = hashtable->table[i];
        while(temp != NULL) {
            printf("(%d, %d) ", temp->key, temp->val);
            temp = temp->link;
        }
    }
    return;
}

int main()
{
    int choice, table_size;

    printf("\n------- Hash Tables -------");

    printf("\nEnter the size of the hash table:");
    scanf("%d", &table_size);
    struct HashTable* hashtable = (struct HashTable*)malloc(sizeof(struct HashTable));
    init_hashtable (hashtable, table_size);
    
    while(1) {
        printf("\n----------------------------------\n");
        printf("1.Insert\n2.Delete\n3.Display\n");
        printf(">> Choose your Option:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: insert(hashtable);
                    break;
            case 2: delete(hashtable);
                    break;
            case 3: display(hashtable);
                    break;
            default: return 0;
        }
    }
}