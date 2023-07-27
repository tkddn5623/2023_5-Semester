#include <stdio.h>
#include <stdlib.h>
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
typedef struct {
	int* items;
	int top;
} ArrayStack;
ArrayStack* AS_new(int max) {
	ArrayStack* pstack;
	if ((pstack = malloc(sizeof(ArrayStack))) == NULL) exit(1);
	if ((pstack->items = calloc(max, sizeof(int))) == NULL) exit(1);
	pstack->top = -1;
	return pstack;
}
void AS_delete(ArrayStack* pstack) {
	free(pstack->items);
	free(pstack);
}
int AS_isEmpty(const ArrayStack* pstack) {
	return pstack->top == -1;
}
int AS_peek(const ArrayStack* pstack) {
	return pstack->items[pstack->top];
}
void AS_push(ArrayStack* pstack, int item) {
	pstack->items[++(pstack->top)] = item;
}
int AS_pop(ArrayStack* pstack) {
	return pstack->items[(pstack->top)--];
}
Graph* GR_new(int vtxsize, int edgesize) {
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
void GR_delete(Graph* graph) {
	free(graph->_edges);
	free(graph->tails);
	free(graph);
}
void GR_addEdge(Graph* graph, int from, int to) {
	graph->_edges[graph->edgecount].id = to;
	graph->_edges[graph->edgecount].next = graph->tails[from]->next;
	graph->tails[from]->next = &graph->_edges[graph->edgecount];
	graph->tails[from] = &graph->_edges[graph->edgecount++];
}
void solve16947(Graph* graph) {
	const int vtxsize = graph->vtxsize;
	int* visited, * parent, vtx;
	ArrayStack* stack;

	if (!(visited = calloc(vtxsize, sizeof(int)))) exit(1);
	if (!(parent = calloc(vtxsize, sizeof(int)))) exit(1);
	stack = AS_new(vtxsize);
	AS_push(stack, 1);

	while (!AS_isEmpty(stack)) {
		int prev = AS_pop(stack);
		vtx = prev & ((1 << 12) - 1);
		prev >>= 12;
		if (visited[vtx] & 0x1) continue;
		GNode* const head = &graph->_edges[vtx];
		visited[vtx] |= 0x1; // Visit mark
		parent[vtx] = prev;
		for (GNode* cur = head->next; cur != head; cur = cur->next) {
			int next = cur->id;
			if (next == parent[vtx]) continue;
			AS_push(stack, next | vtx << 12);
			if (visited[next] & 0x1) {
				for (int i = vtx; i != next; i = parent[i]) {
					visited[i] |= 0x4; // Cycle mark
				}
				visited[next] |= 0x4;
				goto BRK;
			}
		}
	} BRK:;
	free(parent);
	for (int i = 1; i < vtxsize; i++) { visited[i] &= 0x4; }
	stack->top = -1;
	AS_push(stack, vtx);

	while (!AS_isEmpty(stack)) {
		int dist_mask = AS_pop(stack);
		vtx = dist_mask & ((1 << 12) - 1);
		dist_mask = dist_mask & ~((1 << 12) - 1); // Distance masking
		if (visited[vtx] & 0x1) continue;
		visited[vtx] |= (dist_mask | 0x1);
		GNode* const head = &graph->_edges[vtx];
		for (GNode* cur = head->next; cur != head; cur = cur->next) {
			int next = cur->id;
			if (visited[next] & 0x4) AS_push(stack, next);
			else AS_push(stack, next | (dist_mask + (1 << 12)));
		}
	}
	for (int i = 1; i < vtxsize; i++) {
		printf("%d ", visited[i] >> 12);
	}
	AS_delete(stack);
	free(visited);
}
int main() {
	Graph* graph;
	int N;
	scanf("%d", &N);
	graph = GR_new(N + 1, N * 2);
	for (int i = 0; i < N; i++) {
		int from, to;
		scanf("%d%d", &from, &to);
		GR_addEdge(graph, from, to);
		GR_addEdge(graph, to, from);
	}
	solve16947(graph);
	GR_delete(graph);
}