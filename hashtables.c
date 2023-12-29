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

// Structure to hold information about a person
struct person {
    char name[50];
    int age;
    struct person *link;
};

// Structure to represent the hash table
struct HashTable {
    struct person **table; // Pointer to an array of pointers to persons
    int size; // Size of the hash table
};

/*
Function    : create_hash
Purpose     : Hash function: Converts a string (name) into an index within the hash table
*/
int create_hash(char *name, int table_size)
{
    return ('z'-name[0])%table_size;
}

/*
Function    : create_person
Purpose     : To create a new person with given name and age
*/
struct person* create_person()
{
    struct person* new_person = (struct person*)malloc(sizeof(struct person));

    if (new_person == NULL) {
        printf(">>> Error: Insufficient Memory\n");
        exit (0);
    }

    int age;
    char name[50];
    
    printf("\nEnter the name of the person:\t");
    scanf("%s", name);
    printf("Enter the age of the person:\t");
    scanf("%d", &age);
    
    strcpy(new_person->name, name);
    new_person->age = age;
    
    return new_person;
}

/*
Function    : init_hashtable
Purpose     : Initializes the hash table with a specified size
*/
void init_hashtable(struct HashTable* hashtable, int table_size) {
    hashtable->size = table_size; // Assign the specified size to the hash table
    hashtable->table = (struct person**)malloc(table_size*sizeof(struct person*));
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
    struct person* new_person = create_person();
    printf("##%d\n", __LINE__);
    unsigned int new_person_hash_index = create_hash(new_person->name, hashtable->size);
    printf("##%d\n", __LINE__);

    if (hashtable->table[new_person_hash_index] == NULL) {
        printf("##%d\n", __LINE__);
        hashtable->table[new_person_hash_index] = new_person;
    }
    else {
        printf("##%d\n", __LINE__);
        // If collision occurs (slot is not empty), handle it using separate chaining
        struct person* temp = hashtable->table[new_person_hash_index];
        while (temp->link != NULL) { // Move to the end of the chain
            temp = temp->link;
        }
        temp->link = new_person; // Add the new person at the end of the chain
    }
    return;
}

/*
Function    : Delete
Purpose     : Deletes a person from hash table
*/
void delete()
{   
    return;
}

/*
Function    : Display
Purpose     : Display all elements in hash table
*/
void display(struct HashTable* hashtable)
{   
    printf("\nDisplay:\n");
    for (int i=0; i<hashtable->size; i++) {
        printf("\nIndex [%d]: ", i);
        struct person* temp = hashtable->table[i];
        while(temp != NULL) {
            printf("%s, %d", temp->name, temp->age);
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
            case 2: delete();
                    break;
            case 3: display(hashtable);
                    break;
            default: return 0;
        }
    }
}