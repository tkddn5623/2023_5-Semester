/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>

int Answer;

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
void MergeSort(int* list, int size) {
    static int sorted[1000000];
    _MergeSort_impl(list, sorted, 0, size - 1);
}
int binary_least_greater(const int arr[], int size, int key) {
    int pos = -1, left = 0, mid;
    size = size - 1;
    while (left <= size) {
        mid = left + (size - left) / 2;
        if (arr[mid] <= key) left = mid + 1;
        else {
            pos = mid;
            size = mid - 1;
        }
    }
    return pos;
}
int binary_greatest_less(const int arr[], int size, int key) {
    int pos = -1, left = 0, mid;
    size = size - 1;
    while (left <= size) {
        mid = left + (size - left) / 2;
        if (arr[mid] >= key) size = mid - 1;
        else {
            pos = mid;
            left = mid + 1;
        }
    }
    return pos;
}
void solveB() {
    static int arr[1000000];
    int N, D;
    int zeroes, cur, lbound, lstart, rbound, rstart;
    int leftcnt, rightcnt;
    int answer;

    zeroes = 0;
    cur = 0;
    answer = 0;
    scanf("%d%d", &N, &D);

    for (int j = 0, i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        if (temp == 0) zeroes++;
        else arr[j++] = temp;
    }
    Answer = zeroes;
    N -= zeroes;
    MergeSort(arr, N);

    lstart = binary_greatest_less(arr, N, 0);
    rstart = binary_least_greater(arr, N, 0);
    lbound = binary_least_greater(arr, N, -(D + 1));
    rbound = binary_greatest_less(arr, N, D + 1);
    if (rstart != -1) {
        for (int i = rbound; i >= rstart; i--) {
            int remain, localanswer, lbnd;
            remain = D - 2 * arr[i];
            localanswer = i - rstart + 1;
            if (remain > 0 && lstart != -1) {
                lbnd = binary_least_greater(arr, N, -(remain + 1));
                if (lbnd <= lstart) localanswer += lstart - lbnd + 1;
            }
            if (answer < localanswer) answer = localanswer;

        }
    }
    if (lstart != -1 && lbound != -1) {
        for (int i = lbound; i <= lstart; i++) {
            int remain, localanswer, rbnd;
            remain = D + 2 * arr[i];
            localanswer = lstart - i + 1;
            if (remain > 0 && rstart != -1) {
                rbnd = binary_greatest_less(arr, N, remain + 1);
                if (rbnd >= rstart) localanswer += rbnd - rstart + 1;
            }
            if (answer < localanswer) answer = localanswer;

        }
    }
    Answer = answer;
}
int main(void)
{
    int T, test_case;
    /*
       The freopen function below opens input.txt file in read only mode, and afterward,
       the program will read from input.txt file instead of standard(keyboard) input.
       To test your program, you may save input data in input.txt file,
       and use freopen function to read from the file when using scanf function.
       You may remove the comment symbols(//) in the below statement and use it.
       But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */
     // freopen("input.txt", "r", stdin);

     /*
       If you remove the statement below, your program's output may not be recorded
       when your program is terminated after the time limit.
       For safety, please use setbuf(stdout, NULL); statement.
      */
    setbuf(stdout, NULL);

    scanf("%d", &T);
    for (test_case = 0; test_case < T; test_case++)
    {

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
           Implement your algorithm here.
           The answer to the case will be stored in variable Answer.
         */
         /////////////////////////////////////////////////////////////////////////////////////////////
        solveB();
        // Print the answer to standard output(screen).

        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);

    }

    return 0;//Your program should return 0 on normal termination.
}