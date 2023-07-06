#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MASK_SET(mk, i, j, value) (mk[i][j / 16] |= (value & 0x3) << (j % 16 * 2))
#define MASK_GET(mk, i, j) ((mk[i][j / 16] >> (j % 16 * 2)) & 0x3)
typedef struct {
	int e1;
	int e2;
}Element;
typedef struct {
	Element* items;
	int capacity;
	int front;
	int rear;
} ArrayQueue;
ArrayQueue* AQ_new(const int max) {
	ArrayQueue* pqueue;
	if ((pqueue = malloc(sizeof(ArrayQueue))) == NULL) exit(1);
	if ((pqueue->items = calloc(max + 1, sizeof(Element))) == NULL) exit(1);
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
Element AQ_front(const ArrayQueue* pqueue) {
	return pqueue->items[pqueue->front];
}
void AQ_push(ArrayQueue* pqueue, const Element item) {
	const int rear = pqueue->rear;
	pqueue->items[rear] = item;
	pqueue->rear = (rear + 1) % pqueue->capacity;
}
Element AQ_pop(ArrayQueue* pqueue) {
	const int front = pqueue->front;
	pqueue->front = (front + 1) % pqueue->capacity;
	return pqueue->items[front];
}
int main() {
	static int mask[1000][125];
	static int dist[1000][1000];
	const int dx[4] = { -1, +1, 0, 0 };
	const int dy[4] = { 0, 0, -1, +1 };
	int N, M;
	int row2 = -1, col2 = -1;
	ArrayQueue* queue;
	scanf("%d%d", &N, &M);
	queue = AQ_new(N * M * 2);
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M;) {
			char ch = getchar();
			if (ch == ' ' || ch == '\n') continue;
			if (ch == '2') {
				AQ_push(queue, (Element) { i, j });
				dist[i][j] = 0;
			}
			MASK_SET(mask, i, j, ch);
			j++;
		}
	}
	while (!AQ_isEmpty(queue)) {
		Element c = AQ_pop(queue);
		int row, col;
		for (int i = 0; i < 4; i++) {
			row = c.e1 + dx[i];
			col = c.e2 + dy[i];
			if (row < 0 || row >= N || col < 0 || col >= M ||
				dist[row][col] != -1 || MASK_GET(mask, row, col) == 0) continue;
			dist[row][col] = dist[c.e1][c.e2] + 1;
			AQ_push(queue, (Element) { row, col });
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dist[i][j] != -1) printf("%d ", dist[i][j]);
			else if (MASK_GET(mask, i, j) == 0) printf("0 ");
			else printf("-1 ");
		}
		putchar('\n');
	}
	AQ_delete(queue);
}