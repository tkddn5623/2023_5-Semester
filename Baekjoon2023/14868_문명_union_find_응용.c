#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define xy2i(x, y) (x * (N + 1) + y)
typedef struct {
	int x;
	int y;
} pair_t;
typedef struct {
	pair_t* items;
	int capacity;
	int front;
	int rear;
} ArrayQueue;
ArrayQueue* AQ_new(const int max) {
	ArrayQueue* pqueue;
	if ((pqueue = malloc(sizeof(ArrayQueue))) == NULL) exit(1);
	if ((pqueue->items = calloc(max + 1, sizeof(pair_t))) == NULL) exit(1);
	pqueue->capacity = max + 1;
	pqueue->front = 0;
	pqueue->rear = 0;
	return pqueue;
}
void AQ_delete(ArrayQueue* pqueue) {
	free(pqueue->items);
	free(pqueue);
}
int AQ_isEmpty(const ArrayQueue* pqueue) {
	return pqueue->front == pqueue->rear;
}
int AQ_size(const ArrayQueue* pqueue) {
	const int subtract = pqueue->rear - pqueue->front;
	if (subtract >= 0) return subtract;
	else return pqueue->capacity + subtract;
}
pair_t AQ_front(const ArrayQueue* pqueue) {
	return pqueue->items[pqueue->front];
}
void AQ_push(ArrayQueue* pqueue, const pair_t item) {
	const int rear = pqueue->rear;
	pqueue->items[rear] = item;
	pqueue->rear = (rear + 1) % pqueue->capacity;
}
pair_t AQ_pop(ArrayQueue* pqueue) {
	const int front = pqueue->front;
	pqueue->front = (front + 1) % pqueue->capacity;
	return pqueue->items[front];
}
int* UF_init(const int maxsize) {
	int* roots;
	if ((roots = calloc(maxsize, sizeof(int))) == NULL) exit(1);
	memset(roots, -1, sizeof(int) * maxsize);
	return roots;
}
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
int solve14868(const int N, int K) {
	const int dx[4] = { 1, -1, 0, 0 };
	const int dy[4] = { 0, 0, 1, -1 };
	ArrayQueue* queue = AQ_new((N + 1) * (N + 1));
	int* disjset = UF_init((N + 1) * (N + 1));
	int* visited = calloc((N + 1) * (N + 1), sizeof(int)); if (!visited) exit(1);
	int visited_total = 0;
	int answer = 0;
	for (int i = 0; i < K; i++) {
		pair_t xy;
		scanf("%d%d", &xy.x, &xy.y);
		AQ_push(queue, xy);
		visited[xy2i(xy.x, xy.y)] = 1;
		visited_total++;
		for (int k = 0; k < 4; k++) {
			int x2 = xy.x + dx[k];
			int y2 = xy.y + dy[k];
			if (x2 < 1 || x2 > N || y2 < 1 || y2 > N) continue;
			if (!visited[xy2i(x2, y2)]) continue;
			UF_union(disjset, xy2i(xy.x, xy.y), xy2i(x2, y2));
		}
	}
	while (!AQ_isEmpty(queue)) {
		pair_t xy = AQ_front(queue);
		if (UF_size(disjset, xy2i(xy.x, xy.y)) == visited_total) break;
		for (int i = AQ_size(queue) - 1; i >= 0; i--) {
			xy = AQ_pop(queue);
			for (int j = 0; j < 4; j++) {
				int x2 = xy.x + dx[j];
				int y2 = xy.y + dy[j];
				if (x2 < 1 || x2 > N || y2 < 1 || y2 > N) continue;
				if (visited[xy2i(x2, y2)]) continue;
				visited[xy2i(x2, y2)] = 1;
				visited_total++;
				AQ_push(queue, (pair_t) { x2, y2 });
				UF_union(disjset, xy2i(xy.x, xy.y), xy2i(x2, y2));
				for (int k = 0; k < 4; k++) {
					int x3 = x2 + dx[k];
					int y3 = y2 + dy[k];
					if (x3 < 1 || x3 > N || y3 < 1 || y3 > N) continue;
					if (!visited[xy2i(x3, y3)]) continue;
					UF_union(disjset, xy2i(x2, y2), xy2i(x3, y3));
				}
			}
		}
		answer++;
	}
	AQ_delete(queue);
	free(disjset);
	free(visited);
	return answer;
}
int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	printf("%d\n", solve14868(N, K));
}