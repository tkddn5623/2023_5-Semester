#include <unistd.h>
#define MAX (1000000)
#define MAXINT (1000000)
#define BFSIZE (2000000)

static char _buf[BFSIZE];
static int _buf_i;
static int _buf_max;
static char _bufout[BFSIZE];
static int _bufout_i;


void writeflush() {
    write(1, _bufout, _bufout_i);
    _bufout_i = 0;
}
void writech(int c) {
    if (_bufout_i >= BFSIZE) writeflush();
    _bufout[_bufout_i++] = c;
}
void writeint(int n) {
    int j = MAXINT;
    if (n < 0) {
        writech('-');
        n = -n;
    }
    while (j > 1 && !(n / j)) { j /= 10; }
    do {
        writech('0' | n / j);
        n %= j;
        j /= 10;
    } while (j);
    writech('\n');
}
int readch() {
    if (_buf_i >= _buf_max) {
        _buf_max = read(0, _buf, BFSIZE);
        _buf_i = 0;
    }
    return _buf[_buf_i++];
}
int readint() {
    int a, b, c;
    while ((c = readch()) && c < '-');
    for (b = c < '0' ? 0 : c & 0xf; (a = readch()) >= '0'; b = b * 10 + (a & 0xf));
    return c == '-' ? -b : b;
}
void _MergeSort_impl(int* list, int* sorted, const int left, const int right) {
    if (left >= right) return;
    const int mid = left + (right - left) / 2;
    _MergeSort_impl(list, sorted, left, mid);
    _MergeSort_impl(list, sorted, mid + 1, right);
    int idx, first, second;
    idx = left, first = left, second = mid + 1;
    while (first <= mid && second <= right) {
        if (list[first] <= list[second]) sorted[idx++] = list[first++];
        else sorted[idx++] = list[second++];
    }
    while (first <= mid)    sorted[idx++] = list[first++];
    while (second <= right) sorted[idx++] = list[second++];
    for (int i = left; i <= right; i++) list[i] = sorted[i];
}
int* MergeSort(int* list, int size) {
    static int sorted[MAX];
    _MergeSort_impl(list, sorted, 0, size - 1);
    return list;
}
int main() {
    static int arr[MAX] = { 0 };
    int len;
    len = readint();
    for (int i = 0; i < len; i++) {
        arr[i] = readint();
    }
    MergeSort(arr, len);
    for (int i = 0; i < len; i++) {
        writeint(arr[i]);
    }
    writeflush();
}