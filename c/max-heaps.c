/*

Author: https://github.com/ravikumark815

------- Max Heaps -------

Insert : Inserting Elements into maxHeap
Delete : Deleting Elements from maxHeap
Display : Display current elements in maxHeap
Search: Search an element in maxHeap

*/

#include <stdio.h>
#include <stdlib.h>

#define SWAP(a,b) a = a ^ b; b = a ^ b; a = a ^ b;
#define MAX(a,b) (a > b) ? a : b;

struct maxHeap {
    int* array;
    int cur_size;
    int capacity;
};

struct maxHeap *create_heap (int capacity)
{
    struct maxHeap *new_heap = (struct maxHeap*) malloc (sizeof(struct maxHeap));
    if (new_heap == NULL) {
        printf(">>> Error: Insufficient Memory\n");
        exit (0);
    }
    new_heap->array = (int*) malloc (capacity*sizeof(int));
    new_heap->cur_size = 0;
    new_heap->capacity = capacity;
    return new_heap;
}

int getParentIndex(int i) {
    return (i-1)/2;
}

int getLeftChildIndex(int i) {
    return (2*i+1);
}

int getRightChildIndex(int i) {
    return (2*i+2);
}

void maxHeapify(struct maxHeap *heap, int index)
{
    int largest = index;
    int left_index = getLeftChildIndex(index);
    int right_index = getRightChildIndex(index);

    if((left_index < heap->cur_size) && (heap->array[left_index] > heap->array[largest]))
        largest = left_index;
    if((right_index < heap->cur_size) && (heap->array[right_index] > heap->array[largest]))
        largest = right_index;
    
    if (largest != index) {
        SWAP(heap->array[index], heap->array[largest]);
        maxHeapify(heap, largest);
    }
    return;
}

void maxHeapInsert(struct maxHeap *heap)
{
    if (heap->cur_size == heap->capacity) {
        printf(">>> Error: Heap Overflow\n");
        return;
    }
    
    int elem;
    
    printf("\nInsert:\nEnter the element to be inserted:\t");
    scanf("%d", &elem);

    if (heap->cur_size == 0) {
        heap->array[0] = elem;
        heap->cur_size++;
        printf(">> %d inserted into heap successfully\n", elem);
        return;
    }
    
    int index = heap->cur_size;
    heap->array[index] = elem;
    while ((index > 0) && (heap->array[getParentIndex(index)] < heap->array[index])) {
        SWAP(heap->array[index], heap->array[getParentIndex(index)]);
        index = getParentIndex(index);
    }
    
    heap->cur_size++;
    printf(">> %d inserted into heap successfully\n", elem);
    return;
}

void maxHeapDelete(struct maxHeap *heap)
{
    if (!(heap->cur_size)) {
        printf("\nDelete:\n>> Heap Empty!\n");
        return;
    }

    heap->array[0] = heap->array[heap->cur_size - 1];
    heap->cur_size--;

    maxHeapify(heap, 0);
    printf("Deletion Successful\n");
    return;
}

int maxHeapDisplay (struct maxHeap *heap)
{
    if (!(heap->cur_size)) {
        printf("\nDelete:\n>> Heap Empty!\n");
        return 0;
    }

    for (int i=0; i<heap->cur_size; i++) {
        printf("|%d", heap->array[i]);
    }
    printf("|\n");

    return 0;
}

int main()
{    
    printf("\n---------------------\n");
    printf("------- Max Heap -------");
    printf("\nEnter the capacity of the heap: ");
    int choice = 0, capacity = 0;
    scanf("%d", &capacity);
    struct maxHeap* heap = create_heap (capacity);
    while(1){
        printf("\n---------------------\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Search\n");
        printf("\nChoose your Option:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: maxHeapInsert(heap);
                    break;
            case 2: maxHeapDelete(heap);
                    break;
            case 3: maxHeapDisplay(heap);
                    break;
            default: return 0;
        }
    }
}