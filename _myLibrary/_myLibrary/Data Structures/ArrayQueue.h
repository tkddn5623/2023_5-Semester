#ifndef ELEMENT_TYPE
#define ELEMENT_TYPE
typedef int Element;
#endif

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H
typedef struct {
	Element* items;
	int capacity;
	int front;
	int rear;
} ArrayQueue;
ArrayQueue* AQ_new(int max);
void AQ_delete(ArrayQueue* pqueue);
int AQ_isEmpty(const ArrayQueue* pqueue);
Element AQ_front(const ArrayQueue* pqueue);
void AQ_push(ArrayQueue* pqueue, Element item);
Element AQ_pop(ArrayQueue* pqueue);
int AQ_size(const ArrayQueue* pqueue);
int AQ_isFull(const ArrayQueue* pqueue);
//Element AQ_back(const ArrayQueue* pqueue);
#endif


/*
* 2022.7.22 Fri
* 2023.7.27 Thu: Delete AQ_back, change func names
*/