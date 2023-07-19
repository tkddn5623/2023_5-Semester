#include <stdio.h>
#include <stdlib.h>
#define MAXN (32000)
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
    int front;
    int rear;
} ArrayQueue;
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
ArrayQueue* AQ_new(int max) {
    ArrayQueue* pqueue;
    if (!(pqueue = calloc(1, sizeof(ArrayQueue)))) exit(1);
    if (!(pqueue->items = calloc(max, sizeof(int)))) exit(1);
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
    return pqueue->rear - pqueue->front;
}
int AQ_front(const ArrayQueue* pqueue) {
    return pqueue->items[pqueue->front];
}
void AQ_push(ArrayQueue* pqueue, int item) {
    pqueue->items[pqueue->rear++] = item;
}
int AQ_pop(ArrayQueue* pqueue) {
    return pqueue->items[pqueue->front++];
}
void _Indgree(int* indgree, Graph* graph) {
    int vtxsize = graph->vtxsize;
    int edgecount = graph->edgecount;
    const GNode* _edges = graph->_edges;
    for (int i = vtxsize; i < edgecount; i++) {
        indgree[_edges[i].id]++;
    }
}
void Topological_Sort(int* sorted, Graph* graph) {
    const int vtxmax = graph->vtxsize - 1;
    ArrayQueue* queue = AQ_new(vtxmax + 1);
    int* indgree = calloc(vtxmax + 1, sizeof(int)); if (!indgree) exit(1);
    int sorted_len = 0;
    _Indgree(indgree, graph);
    for (int i = 1; i <= vtxmax; i++) {
        if (indgree[i] > 0) continue;
        AQ_push(queue, i);
    }
    while (!AQ_isEmpty(queue)) {
        int vtx = AQ_pop(queue);
        sorted[sorted_len++] = vtx;
        GNode* head = &graph->_edges[vtx];
        for (GNode* cur = head->next; cur != head; cur = cur->next) {
            if (--indgree[cur->id] > 0) continue;
            AQ_push(queue, cur->id);
        }
    }
    AQ_delete(queue);
    free(indgree);
}
int main() {
    static int result[MAXN];
    int N, M;
    Graph* G;
    scanf("%d%d", &N, &M);
    G = GR_new(N + 1, M);
    for (int i = 0; i < M; i++) {
        int from, to;
        scanf("%d%d", &from, &to);
        GR_addEdge(G, from, to);
    }
    Topological_Sort(result, G);
    for (int i = 0; i < N; i++) {
        printf("%d ", result[i]);
    }
    GR_delete(G);
}