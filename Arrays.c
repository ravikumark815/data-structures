#include <stdio.h>
#include <stdlib.h>

int arrayInsert(int *array, int * currentSize, int * arrayCapacity)
{
    int elem, index;
    
    printf("\nInsert:\nEnter the element to be inserted:\t");
    scanf("%d", &elem);
    printf("\nEnter the index of the element to be inserted:\t");
    scanf("%d", &index);
    
    if(*currentSize > *arrayCapacity)
    {
        array = (int *)realloc(array, sizeof(array)*2);
        *arrayCapacity = sizeof(array)*2;
    }

    array[index] = elem;
    *currentSize = *currentSize + 1;

    return 0;
}

int arrayDelete()
{
    return 0;
}

int arrayDisplay()
{
    return 0;
}

int main()
{
    int currentSize = 0, choice = 0;
    int arrayCapacity = 1;
    int * array = malloc(arrayCapacity * sizeof(int));

    printf("\n------- Dynamic Array -------\n");
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("\nChoose your Option:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: arrayInsert(array, &currentSize, &arrayCapacity);
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