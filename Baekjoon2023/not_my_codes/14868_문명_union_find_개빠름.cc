//REF: https://www.acmicpc.net/source/46547042
#include <bits/stdc++.h>
using namespace std;

const int LM = 2005;
int n, k, g[LM][LM], gcnt, fr, re, ans, now;
int group[LM * LM];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

struct Civil {
    int r, c, lev;
} que[LM * LM];

void ffill(int r, int c) {
    if (g[r][c] >= 0) return;
    g[r][c] = gcnt;
    que[re++] = {r, c, 0};
    for (int k = 0; k < 4; k++) {
        ffill(r + dr[k], c + dc[k]);
    }
}

void input() {
    scanf("%d %d", &n, &k);
    int i, j, r, c;
    for (i = 0; i < k; i++) {
        scanf("%d %d", &r, &c);
        g[r][c] = -1;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (g[i][j] < 0) {
                gcnt++;
				/// No significant impact on total time
                ffill(i, j);
				/// No significant impact on total time
            }
        }
    }
    for (i = 1; i <= gcnt; i++) group[i] = i;
}

int Find(int k) {
    if (k == group[k]) return k;
    return group[k] = Find(group[k]);
}

int push(int r, int c, int lev) {
    if (r < 1 || r > n || c < 1 || c > n || g[r][c]) return 0;
    g[r][c] = now; // The biggest difference 3: G contains the Group number! (I used UF_union function instead.)
    que[re++] = {r, c, lev};
    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k], nc = c + dc[k];
        if (g[nr][nc] == 0) continue;
		/// The biggest difference 1
        int next = Find(g[nr][nc]);
        if (now == next) continue;
        group[next] = now;
		/// The biggest difference 1
        gcnt--;
    }
    if (gcnt == 1) ans = lev;
    return gcnt == 1;
}

int bfs(){
    if (gcnt == 1) return ans;
    while (fr < re) {
        Civil&t = que[fr++];
		/// The biggest difference 2
        now = Find(g[t.r][t.c]);
		/// The biggest difference 2
        for (int k = 0; k < 4; k++) {
            if (push(t.r + dr[k], t.c + dc[k], t.lev + 1)) {
                return ans;
            }
        }
    }
    return ans;
}

int main() {
    input();
    printf("%d\n", bfs());
    return 0;
}