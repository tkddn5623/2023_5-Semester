#ifndef GRAPH_H
#define GRAPH_H
typedef struct _GNode {
	int id;
	int weight;
	struct _GNode* next;
} GNode;
typedef struct {
	int vtxsize;
	int edgesize;
	int edgecount;
	GNode** tails;
	GNode* _edges;
} Graph;
Graph* GR_new(int vtxsize, int edgesize);
void GR_delete(Graph* graph);
void GR_addEdge(Graph* graph, int from, int to, int weight);
#endif