/*

Author: https://github.com/ravikumark815

------- Array -------

Enqueue : Inserting Elements into Array
Dequeue : Deleting Elements from Array
Display : Display current elements in Array

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arrayInsert(int *array, int * currentSize, int * arrayCapacity)
{
    int elem, index;
    
    printf("\nInsert:\nEnter the element to be inserted:\t");
    scanf("%d", &elem);
    
    if(*currentSize > *arrayCapacity)
    {
        // Double the size of array, if the current size is ge than current capacity
        array = (int *)realloc(array, (*arrayCapacity)*2);
        printf(">> Array size increased from %d to %d\n", *arrayCapacity, (*arrayCapacity)*2);
        *arrayCapacity = (*arrayCapacity)*2;
    }

    array[*currentSize] = elem;
    *currentSize = *currentSize + 1;
    printf(">> %d inserted into array successfully\n", elem);

    return 0;
}

int arrayDelete(int *array, int *currentSize, int *arrayCapacity)
{
    if (!(*currentSize)) {
        printf("\nDelete:\n>> Array Empty!\n");
        return 0;
    }
    
    printf(">> %d deleted from array successfully\n", array[*currentSize]);
    *currentSize = *currentSize - 1;

    // Reduce array size to half if the no of elements is less than half of current capacity
    if ((*currentSize + 1) < ((*arrayCapacity)/2)) {
        array = (int *)realloc(array, (*arrayCapacity)/2);
        printf(">> Array size decreased from %d to %d\n", *arrayCapacity, (*arrayCapacity)/2);
        *arrayCapacity = (*arrayCapacity)/2;
    }

    return 0;
}

int arrayDisplay(int * array, int currentSize)
{
    if (!currentSize) {
        printf("\nDisplay:\n>> Array Empty!\n");
        return 0;
    }
    printf("\nDisplay:\n|");
    for (int i=0; i<currentSize; i++)
    {
        printf("%d\t|", array[i]);
    }
    printf("\n");
    return 0;
}

int main()
{
    int currentSize = 0, choice = 0;
    int arrayCapacity = 1;
    int * array = malloc(arrayCapacity * sizeof(int));

    printf("\n---------------------\n");
    printf("------- Array -------");
    while(1){
        printf("\n---------------------\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("\nChoose your Option:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: arrayInsert(array, &currentSize, &arrayCapacity);
                    break;
            case 2: arrayDelete(array, &currentSize, &arrayCapacity);
                    break;
            case 3: arrayDisplay(array, currentSize);
                    break;
            case 4: return 0;
            default: printf("\n>> Error: Enter Valid Option! <<\n");
        }
    }
}