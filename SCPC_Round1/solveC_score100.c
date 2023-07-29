/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>

int Answer;

int KMPmatcher_boj1305(const int text[], const int L) {
    static int prefix[500001];
    prefix[1] = 0;
    for (int i = 1, k = 0; i < L; i++) {
        while (k > 0 && text[k] != text[i])
            k = prefix[k];
        if (text[k] == text[i])
            k = k + 1;
        prefix[i + 1] = k;
    }
    return L - prefix[L];
}
void solveC() {
    static int arr[500000];
    static int arr_update[500001];
    int N, count[2];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        arr_update[i] = 0;
    }
    do {
        count[0] = 0;
        count[1] = 0;
        for (int i = 0; i < N; i++) {
            int value = arr[i];
            if (!value) continue;
            arr_update[i]--;
            arr_update[(i + 1) % N]++;
        }
        for (int i = 0; i < N; i++) {
            if (arr_update[i]) {
                arr[i] += arr_update[i];
                arr_update[i] = 0;
            }
            if (arr[i] <= 1) count[arr[i]]++;
        }
    } while (count[0] > 0 && count[0] + count[1] < N);

    if (count[0] == 0) {
        Answer = 1;
    }
    else {
        int k = KMPmatcher_boj1305(arr, N);
        printf("kmp %d\n", k);
        Answer = N;
        if (N % k == 0) {
            Answer = k;
        }
    }
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
        solveC();
        // Print the answer to standard output(screen).

        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);

    }

    return 0;//Your program should return 0 on normal termination.
}