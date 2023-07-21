#ifndef ELEMENT_TYPE
#define ELEMENT_TYPE
typedef int Element;
#endif

#ifndef MERGE_SORT_H
#define MERGE_SORT_H
void _MergeSort_impl(Element* list, Element* sorted, const int left, const int right);
Element* MergeSort(Element* list, int size);
#endif
