#include <stdio.h>
#include <stdlib.h>
#define MAX (50)
int* UF_init(const int maxsize) {
    int* roots;
    if ((roots = calloc(maxsize, sizeof(int))) == NULL) exit(1);
    for (int i = 0; i < maxsize; i++) roots[i] = i;
    return roots;
}
int UF_find(int* roots, const int key) {
    if (roots[key] == key) return key;
    else return roots[key] = UF_find(roots, roots[key]);
}
void UF_union(int* roots, int A, int B) {
    A = UF_find(roots, A);
    B = UF_find(roots, B);
    roots[A] = B;
}
int solve1043(const int N, int M) {
    int* disjoint = UF_init(N + 1);
    int lists[MAX][MAX];
    int lists_len[MAX];
    int m, answer = M, truth = -1;
    scanf("%d", &m);
    if (m > 0) {
        int b;
        scanf("%d", &truth);
        for (int i = 1; i < m; i++) {
            scanf("%d", &b);
            UF_union(disjoint, truth, b);
        }
    }
    for (int i = 0; i < M; i++) {
        int len, a;
        scanf("%d", &lists_len[i]);
        len = lists_len[i];
        if (len > 0) {
            scanf("%d", &lists[i][0]);
            a = lists[i][0];
            for (int j = 1; j < len; j++) {
                scanf("%d", &lists[i][j]);
                UF_union(disjoint, a, lists[i][j]);
            }
        }
    }
    for (int i = 0; i < M; i++) {
        if (lists_len[i] > 0 && UF_find(disjoint, truth) == UF_find(disjoint, lists[i][0])) {
            answer--;
        }
    }
    free(disjoint);
    return answer;
}
int main() {
    //freopen("i.txt", "r", stdin);
    int N, M;
    scanf("%d%d", &N, &M);
    printf("%d\n", solve1043(N, M));
}