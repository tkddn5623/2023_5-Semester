#include <stdio.h>
#define MAXN (1000000)
typedef struct _Node_t{
	int value;
	struct _Node_t* prev;
	struct _Node_t* next;
} Node_t;
void push_front(Node_t* head, Node_t* cur) {
	Node_t* head_next, * cur_prev, * cur_next;
	if ((head_next = head->next) == cur) return;
	cur_prev = cur->prev;
	cur_next = cur->next;

	cur_prev->next = cur_next;
	cur_next->prev = cur_prev;
	cur->prev = head;
	cur->next = head_next;
	head_next->prev = cur;
	head->next = cur;
}
void push_back(Node_t* tail, Node_t* cur) {
	Node_t* tail_prev, * cur_prev, * cur_next;
	if ((tail_prev = tail->prev) == cur) return;
	cur_prev = cur->prev;
	cur_next = cur->next;

	cur_prev->next = cur_next;
	cur_next->prev = cur_prev;
	cur->prev = tail_prev;
	cur->next = tail;
	tail_prev->next = cur;
	tail->prev = cur;
}
int peek_front(Node_t* head) {
	return head->next->value;
}
int peek_back(Node_t* tail) {
	return tail->prev->value;
}
void solve7570(int arr[], int N) {
	static struct List_t {
		Node_t nodes[MAXN + 2];
		Node_t* head;
		Node_t* tail;
	} list;
	const int value_mid = (N + 1) / 2;
	Node_t *cur;
	do {
		Node_t* last;
		list.head = &list.nodes[0];
		list.tail = &list.nodes[MAXN + 1];
		last = &list.nodes[0];
		for (int i = 0; i < N; i++) {
			int j = arr[i];
			list.nodes[j].value = j;
			list.nodes[j].prev = last;
			last->next = &list.nodes[j];
			last = &list.nodes[j];
		}
		list.nodes[MAXN + 1].prev = last;
		last->next = &list.nodes[MAXN + 1];
	} while (0);
}
int main() {
	static int arr[MAXN];
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) { scanf("%d", &arr[i]); }
	solve7570(arr, N);
}