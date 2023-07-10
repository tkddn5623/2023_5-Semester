//Reference: sagit25's 46547042 C++17 code[https://www.acmicpc.net/source/46547042]
//Some ideas refer to sagit25's code.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define xy2i(x, y) (x * (N + 1) + y)

typedef struct {
	int x;
	int y;
} pair_t;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };
int N, K, queue_f, queue_r;
pair_t* queue;
int* visited;

int UF_find(int* roots, const int key) {
	if (roots[key] < 0) return key;
	else return roots[key] = UF_find(roots, roots[key]);
}
void UF_union(int* roots, int A, int B) {
	A = UF_find(roots, A);
	B = UF_find(roots, B);
	if (A == B) return;
	roots[A] += roots[B];
	roots[B] = A;
}
int UF_size(int* roots, const int key) {
	return -roots[UF_find(roots, key)];
}
int _flood(int x, int y, int value) {
	if (x < 1 || x > N || y < 1 || y > N || visited[xy2i(x, y)] != -1) return 0;
	visited[xy2i(x, y)] = value;
	queue[queue_r++] = (pair_t){ x,y };
	int a = -1;
	for (int i = 0; i < 4; i++) { a += _flood(x + dx[i], y + dy[i], value); }
	return a;
}
int solve14868() {
	int answer = 0;
	int disjset_size = 0;
	int visited_total = 0;
	int* disjset = calloc(K + 1, sizeof(int));            if (!disjset) exit(1);
	visited = calloc((N + 1) * (N + 1) + 1, sizeof(int)); if (!visited) exit(1);
	queue = calloc((N + 1) * (N + 1), sizeof(pair_t));    if (!queue) exit(1);
	memset(disjset, -1, sizeof(int) * (K + 1));
	queue_f = 0;
	queue_r = 0;
	for (int i = 0; i < K; i++) {
		pair_t xy;
		scanf("%d%d", &xy.x, &xy.y);
		//queue[queue_r++] = xy; //This single line of code makes the program VERY slow
		visited[xy2i(xy.x, xy.y)] = -1;
		visited_total++;
	}
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
		if (visited[xy2i(i, j)] != -1) continue;
		disjset_size++;
		disjset[disjset_size] = _flood(i, j, disjset_size); // 1, 2, 3 ...
	}
	while (UF_size(disjset, 1) != visited_total) {
		for (int i = queue_r - queue_f; i >= 1; i--) {
			pair_t xy = queue[queue_f++];
			int disj_num1 = UF_find(disjset, visited[xy2i(xy.x, xy.y)]);
			for (int j = 0; j < 4; j++) {
				int x2 = xy.x + dx[j];
				int y2 = xy.y + dy[j];
				if (x2 < 1 || x2 > N || y2 < 1 || y2 > N) continue;
				if (visited[xy2i(x2, y2)]) continue;
				visited[xy2i(x2, y2)] = disj_num1;
				visited_total++;
				disjset[disj_num1]--;
				queue[queue_r++] = (pair_t){ x2, y2 };
				for (int k = 0; k < 4; k++) {
					int x3 = x2 + dx[k];
					int y3 = y2 + dy[k];
					int disj_num2;
					if (x3 < 1 || x3 > N || y3 < 1 || y3 > N) continue;
					if (!(disj_num2 = visited[xy2i(x3, y3)])) continue;
					UF_union(disjset, disj_num1, disj_num2);
				}
			}
		}
		answer++;
	}
	free(queue);
	free(disjset);
	free(visited);
	return answer;
}
int main() {
	//freopen("i2.txt", "r", stdin);
	scanf("%d%d", &N, &K);
	printf("%d\n", solve14868());
}