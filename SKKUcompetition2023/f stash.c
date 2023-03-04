#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX (100000)
typedef struct {
	int id;
	int value;
} Pair_t;
typedef struct _GNode {
	int id;
	struct _GNode* next;
} GNode;
typedef struct {
	int vtxsize;
	int edgesize;
	int edgecount;
	GNode** tails;
	GNode* _edges;
} Graph;
void _MergeSort_impl(Pair_t* list, Pair_t* sorted, const int left, const int right) {
	if (left >= right) return;
	const int mid = left + (right - left) / 2;
	_MergeSort_impl(list, sorted, left, mid);
	_MergeSort_impl(list, sorted, mid + 1, right);
	int idx, first, second;
	idx = left, first = left, second = mid + 1;
	while (first <= mid && second <= right) {
		if (list[first].value <= list[second].value) sorted[idx++] = list[first++];
		else sorted[idx++] = list[second++];
	}
	while (first <= mid)    sorted[idx++] = list[first++];
	while (second <= right) sorted[idx++] = list[second++];
	for (int i = left; i <= right; i++) list[i] = sorted[i];
}
Pair_t* MergeSort(Pair_t* list, const int size) {
	Pair_t* sorted = calloc(size, sizeof(Pair_t));
	_MergeSort_impl(list, sorted, 0, size - 1);
	free(sorted);
	return list;
}
Graph* GR_newGraph(const int vtxsize, const int edgesize) {
	Graph* graph;
	if ((graph = malloc(sizeof(Graph))) == NULL) exit(1);
	if ((graph->tails = calloc(vtxsize, sizeof(GNode*))) == NULL) exit(1);
	if ((graph->_edges = calloc(edgesize + vtxsize, sizeof(GNode))) == NULL) exit(1);
	graph->vtxsize = vtxsize;
	graph->edgesize = edgesize + vtxsize;
	graph->edgecount = vtxsize;
	for (int i = 0; i < vtxsize; i++) {
		graph->tails[i] = &graph->_edges[i];
		graph->tails[i]->next = graph->tails[i];
	}
	return graph;
}
void GR_deleteGraph(Graph* graph) {
	free(graph->_edges);
	free(graph->tails);
	free(graph);
}
void GR_addEdge(Graph* graph, const int from, const int to) {
	graph->_edges[graph->edgecount].id = to;
	graph->_edges[graph->edgecount].next = graph->tails[from]->next;
	graph->tails[from]->next = &graph->_edges[graph->edgecount];
	graph->tails[from] = &graph->_edges[graph->edgecount++];
}
long long solveF(Graph* graph, const int goal[], const int N) {
	static Pair_t pair[MAX];
	static int deleted[MAX];
	long long answer = 0;
	int count = 0, totalgraph = 1;
	for (int i = 0; i < N; i++) {
		pair[i].id = i;
		pair[i].value = goal[i];
	}
	MergeSort(pair, N);
	memset(deleted, 0, sizeof(deleted));
	for (int i = 0; i < N; i++) {
		if (deleted[i]) continue;
		deleted[i] = 1;
		count += goal[i];
	}


	return 0;
}
int main() {
	static int goal[MAX];
	Graph* graph;
	int N;
	scanf("%d", &N);
	graph = GR_newGraph(N, 2 * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &goal[i]);
	}
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		GR_addEdge(graph, a, b);
	}
	printf("%lld\n", solveF(graph, goal, N));
	GR_deleteGraph(graph);
}