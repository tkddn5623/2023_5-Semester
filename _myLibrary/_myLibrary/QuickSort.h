#ifndef ELEMENT_TYPE
#define ELEMENT_TYPE
typedef int Element;
#endif

#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#define PART_NOPIVOT (-1)
void _Select_kth_sort(Element* src, int left, int size, int segment);
int _Select_kth_impl(Element* src, int left, int right, int K);
int Partition(Element* src, int left, int right, int pivotidx);
void _Quickimpl(Element* src, int left, int right);
int Select_kth(Element* src, const int size, const int K);
Element* QuickSort(Element* src, const int size);
#endif
