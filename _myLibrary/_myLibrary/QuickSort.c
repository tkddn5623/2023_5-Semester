#include "QuickSort.h"
void _Select_kth_sort(Element* src, int left, int size, int segment) {
    int key;
    for (int i = 1; i < size; i++) {
        int j = i - 1;
        key = src[left + (i * segment)];
        while (j >= 0 && src[left + (j * segment)] > key) {
            src[left + ((j + 1) * segment)] = src[left + (j * segment)];
            j--;
        }
        src[left + ((j + 1) * segment)] = key;
    }
}
int _Select_kth_impl(Element* src, int left, int right, int K) {
    int temp, segment, mid, pivotidx, k;
    while ((right - left + 1) % 5) {
        for (int i = left + 1; i <= right; i++) {
            if (src[left] > src[i]) { // src[left] : put the minimum integer.
                temp = src[left];
                src[left] = src[i];
                src[i] = temp;
            }
        }
        if (K == 0) return left;
        left++;
        K--;
    }
    segment = (right - left + 1) / 5;
    for (int i = 0; i < segment; i++) {
        _Select_kth_sort(src, i + left, 5, segment);
    }
    mid = _Select_kth_impl(src, left + (2 * segment), left + (3 * segment) - 1, segment / 2);
    pivotidx = Partition(src, left, right, mid);
    k = pivotidx - left;

    if (K == k) return pivotidx;
    else if (K < k) return _Select_kth_impl(src, left, pivotidx - 1, K);
    else return _Select_kth_impl(src, pivotidx + 1, right, K - k - 1);
}
int Partition(Element* src, int left, int right, int pivotidx) {
    int temp, pivot, low = left - 1;
    if (pivotidx == PART_NOPIVOT) pivotidx = _Select_kth_impl(src, left, right, (right - left + 1) / 2);
    pivot = src[pivotidx];

    temp = src[right];
    src[right] = src[pivotidx];
    src[pivotidx] = temp;
    for (int i = left; i < right; i++) {
        if (src[i] <= pivot) {
            temp = src[++low];
            src[low] = src[i];
            src[i] = temp;
        }
    }
    temp = src[++low];
    src[low] = src[right];
    src[right] = temp;
    return low;
}
void _Quickimpl(Element* src, int left, int right) {
    if (left >= right) return;
    int mid = Partition(src, left, right, PART_NOPIVOT);
    _Quickimpl(src, left, mid - 1);
    _Quickimpl(src, mid + 1, right);
}
int Select_kth(Element* src, const int size, const int K) {
    return _Select_kth_impl(src, 0, size - 1, K);
}
Element* QuickSort(Element* src, const int size) {
    _Quickimpl(src, 0, size - 1);
    return src;
}

/*
* 2023.4.28 Fri
* But in ps, median of median Quicksort is slower than
* MergeSort or qsort than 1.5 times.
*/