#include <stdio.h>
#include <stdlib.h>
#define RANGE (1000000)
typedef struct {
	int item1;
	int item2;
} Pair_t;
typedef struct {
	Pair_t* item;
	int len;
	int size;
} Vector;
Vector* V_new(int size) {
	Vector* v = malloc(sizeof(Vector)); if (!v) exit(1);
	v->item = calloc(size, sizeof(Pair_t)); if (!v->item) exit(1);
	v->len = 0;
	v->size = size;
	return v;
}
void V_delete(Vector* v) {
	free(v->item);
	free(v);
}
void V_push(Vector* v, Pair_t item) {
	if (v->len >= v->size) {
		void* p = realloc(v->item, (v->size *= 2) * sizeof(Pair_t));
		if (!p) exit(1);
		v->item = p;
	}
	v->item[v->len++] = item;
}
int V_len(Vector* v) {
	return v->len;
}
int binary_search(const int arr[], int size, const int key) { 
	int pos = -1, left = 0, mid;
	size = size - 1;
	while (left <= size) {
		mid = left + (size - left) / 2;
		if (arr[mid] >= key) {
			pos = mid;
			size = mid - 1;
		}
		else left = mid + 1;
	}
	return pos;
}
void LIS_print(const int seq[], const int N) {
	Vector** stacks = calloc(N, sizeof(Vector*)); if (!stacks) exit(1);
	int* stacks_tops = calloc(N, sizeof(int)); if (!stacks_tops) exit(1);
	int stacks_len = 1;
	stacks[0] = V_new(4);
	V_push(stacks[0], (Pair_t) { seq[0], -1 });
	stacks_tops[0] = seq[0];
	for (int i = 1; i < N; i++) {
		const int number = seq[i];
		int pos;
		pos = binary_search(stacks_tops, stacks_len, number);
		if (pos == -1) {
			stacks[stacks_len] = V_new(1);
			V_push(stacks[stacks_len], (Pair_t) { number, (V_len(stacks[stacks_len - 1]) - 1) });
			stacks_tops[stacks_len] = number;
			stacks_len++;
		}
		else {
			int top = pos - 1 >= 0 ? (V_len(stacks[pos - 1]) - 1) : -1;
			V_push(stacks[pos], (Pair_t) { number, top });
			stacks_tops[pos] = number;
		}
	}
	free(stacks_tops);
	int* answer = calloc(stacks_len, sizeof(int)); if (!answer) exit(1);
	for (int j = 0, i = stacks_len - 1; i >= 0; i--) {
		answer[i] = stacks[i]->item[j].item1;
		j = stacks[i]->item[j].item2;
	}
	printf("%d\n", stacks_len);
	for (int i = 0; i < stacks_len; i++) {
		printf("%d ", answer[i]);
	}
	putchar('\n');
	free(stacks);
	free(answer);
}
int main() {
	//freopen("i.txt", "r", stdin);
	static int seq[RANGE];
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) { scanf("%d", &seq[i]); }
	LIS_print(seq, N);
}