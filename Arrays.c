#include <stdio.h>
#include <stdlib.h>

#define INITIAL 1

void push()

void arrayInsert(int *arr, int * currentSize, int * arrayCapacity)
{
    int elem, index;
    
    printf("\nInsert:\nEnter the element to be inserted:\t");
    scanf("%d", &elem);
    printf("\nEnter the index of the element to be inserted:\t");
    scanf("%d", &index);
    
    if(*currentSize > *arrayCapacity)
    {
        realloc(arr, sizeof(arr)*2);
        *arrayCapacity = sizeof(arr)*2;
    }

    arr[index] = elem;
    *currentSize = *currentSize + 1;
}

int main()
{
    int currentSize = 0;
    int arrayCapacity = INITIAL;
    int * arr = malloc(arrayCapacity * sizeof(int));

    printf("\n------- Dynamic Array -------\n");
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("\nChoose your Option:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: arrayInsert(arr, &currentSize, &arrayCapacity);
                    break;
            case 2: arrayDelete();
                    break;
            case 3: arrayDisplay();
                    break;
            case 4: return 0;
            default: printf("\n>> Error: Enter Valid Option <<\n");
        }
    }
}