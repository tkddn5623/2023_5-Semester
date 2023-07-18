#ifndef ELEMENT_TYPE
#define ELEMENT_TYPE
typedef int Element;
#endif

#ifndef ARRAY_HEAP_H
#define ARRAY_HEAP_H
typedef struct {
	Element item;
	int priority;
} HNode;
typedef struct {
	HNode* nodes;
	int capacity;
	int size;
} ArrayHeap;
ArrayHeap* AH_new(int max);
void AH_delete(ArrayHeap* pheap);
int AH_isEmpty(ArrayHeap* pheap);
void AH_push(ArrayHeap* pheap, Element item, int priority);
Element AH_pop(ArrayHeap* pheap);
void AH_heapSort(Element* Base, int NumOfElement);
// int AH_isFull(ArrayHeap* pheap);
#endif