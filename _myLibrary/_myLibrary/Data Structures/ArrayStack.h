#ifndef ELEMENT_TYPE
#define ELEMENT_TYPE
typedef int Element;
#endif

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
typedef struct {
	Element* items;
	int capacity;
	int top;
} ArrayStack;
ArrayStack* AS_new(int max);
void AS_delete(ArrayStack* pstack);
int AS_isFull(const ArrayStack* pstack);
int AS_isEmpty(const ArrayStack* pstack);
int AS_size(const ArrayStack* pstack);
Element AS_peek(const ArrayStack* pstack);
void AS_push(ArrayStack* pstack, Element item);
Element AS_pop(ArrayStack* pstack);
#endif


/*
* 2022.7.22 Friday
*/