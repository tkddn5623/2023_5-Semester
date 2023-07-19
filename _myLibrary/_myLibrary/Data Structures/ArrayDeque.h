#ifndef ELEMENT_TYPE
#define ELEMENT_TYPE
typedef int Element;
#endif

#ifndef ARRAY_DEQUE_H
#define ARRAY_DEQUE_H
typedef struct {
	Element* items;
	int capacity;
	int front;
	int rear;
} ArrayDeque;
ArrayDeque* AD_new(const int max);
void AD_delete(ArrayDeque* pdeque);
int AD_isFull(const ArrayDeque* pdeque);
int AD_isEmpty(const ArrayDeque* pdeque);
int AD_size(const ArrayDeque* pdeque);
Element AD_front(const ArrayDeque* pdeque);
Element AD_back(const ArrayDeque* pdeque);
void AD_pushFront(ArrayDeque* pdeque, Element item);
void AD_pushBack(ArrayDeque* pdeque, Element item);
Element AD_popFront(ArrayDeque* pdeque);
Element AD_popBack(ArrayDeque* pdeque);
#endif


/*
* 2022.7.23 Sat
*/