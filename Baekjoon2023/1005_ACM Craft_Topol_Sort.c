#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN (1000)
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
    int items[MAXN];
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
int AQ_isEmpty(const ArrayQueue* pqueue) {
    return pqueue->front == pqueue->rear;
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
int ACMcraft(Graph* graph, const int time[], int W) {
    static int result[MAXN + 1];
    static int indgree[MAXN + 1];
    static ArrayQueue queue;
    const int vtxmax = graph->vtxsize - 1;
    queue.front = 0;
    queue.rear = 0;
    memset(result, 0, sizeof(int) * (vtxmax + 1));
    memset(indgree, 0, sizeof(int) * (vtxmax + 1));
    _Indgree(indgree, graph);
    for (int i = 1; i <= vtxmax; i++) {
        if (indgree[i] > 0) continue;
        AQ_push(&queue, i);
        result[i] = time[i];
    }
    while (!AQ_isEmpty(&queue) && indgree[W] > 0) {
        int vtx1 = AQ_pop(&queue);
        GNode* head = &graph->_edges[vtx1];
        for (GNode* cur = head->next; cur != head; cur = cur->next) {
            int vtx2 = cur->id;
            if (result[vtx2] < result[vtx1] + time[vtx2]) {
                result[vtx2] = result[vtx1] + time[vtx2];
            }
            if (--indgree[vtx2] > 0) continue;
            AQ_push(&queue, vtx2);
        }
    }
    return result[W];
}
int main() {
    static int time[MAXN + 1];
    int T_, N, K, W;
    Graph* G;
    scanf("%d", &T_);
    while (T_--) {
        int from, to;
        scanf("%d%d", &N, &K);
        G = GR_new(N + 1, K);
        for (int i = 1; i <= N; i++) { scanf("%d", &time[i]); }
        for (int i = 0; i < K; i++) {
            scanf("%d%d", &from, &to);
            GR_addEdge(G, from, to);
        }
        scanf("%d", &W);
        printf("%d\n", ACMcraft(G, time, W));
        GR_delete(G);
    }
}