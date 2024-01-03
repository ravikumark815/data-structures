/*

Author: https://github.com/ravikumark815

------- Min Heaps -------

Insert  : Inserting Elements into maxHeap
Delete  : Deleting Elements from maxHeap
Display : Display current elements in maxHeap

*/

#include <stdio.h>
#include <stdlib.h>

#define SWAP(a,b) int temp = a; a=b; b=temp;

struct minHeap {
    int *array;
    int cur_size;
    int capacity;
};

struct minHeap *create_heap (int capacity)
{
    struct minHeap *new_heap = (struct minHeap*) malloc (sizeof(struct minHeap));
    if (new_heap == NULL) {
        printf(">>> Error: Memory insufficient\n");
        exit(1);
    }
    new_heap->capacity = capacity;
    new_heap->cur_size = 0;
    new_heap->array = (int*) malloc(capacity*sizeof(int));

    return new_heap;
}

int getParentIndex(int index) {
    return (index - 1)/2;
}
int getLeftChildIndex(int index) {
    return (2*index)+ 1;
}
int getRightChildIndex(int index) {
    return (2*index) + 2;
}

void minHeapify (struct minHeap* heap, int index)
{
    int smallest = index;
    int left_index = getLeftChildIndex(index);
    int right_index = getRightChildIndex(index);

    if (heap->array[index] > heap->array[left_index]){
        SWAP(heap->array[index], heap->array[left_index]);
        index = left_index;
    }
    if (heap->array[index] > heap->array[right_index]){
        SWAP(heap->array[index], heap->array[right_index]);
        index = right_index;
    }

    if (smallest != index)
        minHeapify(heap, index);
    return;
}

void minHeapInsert(struct minHeap*heap)
{
    if (heap->cur_size == heap->capacity) {
        printf(">> Error: Heap Overflow!\n");
        return;
    }

    int elem, index;
    printf("Enter the element to be inserted:");
    scanf("%d", &elem);

    if (heap->cur_size == 0) {
        heap->array[0] = elem;
        heap->cur_size++;
        printf("%d inserted into the heap successfully\n", elem);
        return;
    }
    
    heap->cur_size++;
    index = heap->cur_size-1;
    heap->array[index] = elem;

    while((index > 0) && (heap->array[index] < heap->array[getParentIndex(index)])) {
        SWAP(heap->array[index], heap->array[getParentIndex(index)]);
        index = getParentIndex(index);
    }

    printf("%d inserted into the heap successfully\n", elem);
    return;
}

void minHeapDelete (struct minHeap * heap)
{
    if (heap->cur_size == 0) {
        printf(">> Error: Heap Empty!\n");
        return;
    }

    heap->array[0] = heap->array[heap->cur_size];
    heap->cur_size--;

    minHeapify(heap, 0);

    return;
}

void minHeapDisplay (struct minHeap*heap)
{
    if (heap->cur_size == 0) {
        printf(">> Error: Heap Empty!\n");
        return;
    }

    for (int i=0; i<heap->cur_size; i++) {
        printf("| %d ", heap->array[i]);
    }
    printf("|\n");
    return;
}

int main()
{    
    printf("\n---------------------\n");
    printf("------- Min Heap -------");
    printf("\nEnter the capacity of the heap: ");
    int choice = 0, capacity = 0;
    scanf("%d", &capacity);
    struct minHeap* heap = create_heap (capacity);
    while(1){
        printf("\n---------------------\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Search\n");
        printf("\nChoose your Option:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: minHeapInsert(heap);
                    break;
            case 2: minHeapDelete(heap);
                    break;
            case 3: minHeapDisplay(heap);
                    break;
            default: return 0;
        }
    }
}