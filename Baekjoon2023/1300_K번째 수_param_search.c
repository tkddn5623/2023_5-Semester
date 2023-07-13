#include <stdio.h>
#define MAXN (100000)
int binary_lower(const int coef, int size, const int key) {
    int pos = 0, left = 1, mid;
    while (left <= size) {
        mid = left + (size - left) / 2;
        if ((long long)coef * mid <= key) {
            pos = mid;
            left = mid + 1;
        }
        else size = mid - 1;
    }
    return pos;
}
int solve1300(int N, int K) {
    int bound_l = 1;
    int bound_r = N <= 31623 ? N * N : 31623 * 31623;
    int target;
    while (1) {
        int cnt_l = 0, cnt_r = 0;
        target = bound_l + (bound_r - bound_l) / 2;
        for (int i = 1; i <= N; i++) {
            int pos_l = binary_lower(i, N, target - 1);
            int pos_r = binary_lower(i, N, target);
            cnt_l += pos_l;
            cnt_r += pos_r;
        }
        if (cnt_l < K && K <= cnt_r) break;
        else if (cnt_l >= K) bound_r = target - 1;
        else bound_l = target + 1;
    }
    return target;
}
int main() {
    //freopen("i.txt", "r", stdin);
    int N, K;
    scanf("%d%d", &N, &K);
    printf("%d\n", solve1300(N, K));
}