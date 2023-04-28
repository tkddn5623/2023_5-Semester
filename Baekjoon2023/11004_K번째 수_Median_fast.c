#include <stdio.h>
typedef int Element;
#define PART_NOPIVOT (-1)
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
    pivotidx = Partition(src, left, right, mid, K);
    k = pivotidx - left;

    if (K == k) return pivotidx;
    else if (K < k) return _Select_kth_impl(src, left, pivotidx - 1, K);
    else return _Select_kth_impl(src, pivotidx + 1, right, K - k - 1);
}
int Partition(Element* src, int left, int right, int pivotidx, int K) {
    int temp, pivot, low, equal;
    low = left - 1;
    if (pivotidx == PART_NOPIVOT) pivotidx = _Select_kth_impl(src, left, right, (right - left + 1) / 2);
    pivot = src[pivotidx];

    temp = src[right];
    src[right] = src[pivotidx];
    src[pivotidx] = temp;
    for (int i = left; i < right; i++) { //Smaller
        if (src[i] < pivot) {
            temp = src[++low];
            src[low] = src[i];
            src[i] = temp;
        }
    }
    equal = low;
    for (int i = low + 1; i < right; i++) { //Equal
        if (src[i] == pivot) {
            temp = src[++equal];
            src[equal] = src[i];
            src[i] = temp;
        }
    }
    temp = src[++equal];
    src[equal] = src[right];
    src[right] = temp;
    
    if (K < low + 1) return low + 1;
    else if (K <= equal) return K;
    else return equal;
}
int Select_kth(Element* src, const int size, const int K) {
    return _Select_kth_impl(src, 0, size - 1, K);
}
int main() {
    int N, K;
    static int nums[5000000];
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) { scanf("%d", &nums[i]); }
    printf("%d\n", nums[Select_kth(nums, N, K - 1)]);
}