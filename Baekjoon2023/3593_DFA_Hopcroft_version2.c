/*
* Hopcroft DFA minimization C Implementation
* ==========================================
* Author: https://github.com/tkddn5623
* Date: 2023-8-10 Thu.
*
* I implemented this to solve the problem L of NEERC 2007 "Language Recognition"
* Online judge: https://www.acmicpc.net/problem/3593
*
* I referred to the book and papers to implement this code.
* Below are the references to implement this code:
* [1] Keith D. Cooper, "Engineering a Compiler"
* [2] Hang Zhou, "Implementation of Hopcroft's Algorithm"
*
* If you want to minimize your own DFA, see the examples.
*/
#include <stdio.h>
#include <string.h>
#define MAXSTATE  (150000)
#define MAXEDGE   (150000)
#define MAXSYMBOL (26)
typedef struct {
    struct _Node_int_t* prev_head[MAXSYMBOL];
    int next[MAXSYMBOL];
    int accept;
    int partition;
    int me;
} State_t;
typedef struct _Node_int_t {
    int value;
    struct _Node_int_t* next;
} Node_int_t;
typedef struct _Node_state_t {
    State_t state;
    struct _Node_state_t* prev;
    struct _Node_state_t* next;
} Node_state_t;
typedef struct {
    struct _Node_state_t* head;
    int size;
} Partition_t;
typedef struct {
    Node_state_t state_nodes[MAXSTATE + 1];
    Partition_t partitions[MAXSTATE + 1];
    Node_int_t _prev_nodes[MAXEDGE];
    int state_nodes_cnt;
    int partitions_cnt;
    int _prev_nodes_cnt;
} Automaton_t;
void AM_state_init(Automaton_t* pa) {
    pa->state_nodes_cnt = 2;
    pa->_prev_nodes_cnt = 0;
}
int AM_state_new(Automaton_t* pa) {
    return pa->state_nodes_cnt++;
}
void AM_state_set_connect(Automaton_t* pa, int state_from, int state_to, int value) {
    Node_state_t* nodes = &pa->state_nodes[0];
    Node_int_t* pnode = &pa->_prev_nodes[pa->_prev_nodes_cnt++];
    nodes[state_from].state.next[value] = state_to;
    pnode->next = nodes[state_to].state.prev_head[value];
    pnode->value = state_from;
    nodes[state_to].state.prev_head[value] = pnode;
}
void AM_state_set_accept(Automaton_t* pa, int state_number, int mask) {
    pa->state_nodes[state_number].state.accept = mask;
}
void AM_state_add_by_string(Automaton_t* pa, const char* text) {
    Node_state_t* nodes = &pa->state_nodes[0];
    int value, b, a = 1;
    while (1) {
        if ((value = (*text++ - 'a')) < 0) {
            AM_state_set_accept(pa, a, 0x1);
            break;
        }
        if ((b = nodes[a].state.next[value]) == 0) {
            b = AM_state_new(pa);
            AM_state_set_connect(pa, a, b, value);
        }
        a = b;
    }
}
void AM_state_split(Automaton_t* pa, int state_number, int dest_partition) {
    Partition_t* partitions = &pa->partitions[0];
    Node_state_t* nodes = &pa->state_nodes[0];
    Node_state_t* cur = &nodes[state_number];
    Node_state_t* temp;
    if (!(temp = cur->prev)) {
        partitions[cur->state.partition].head = cur->next;
    }
    else {
        temp->next = cur->next;
    }
    if ((temp = cur->next)) {
        temp->prev = cur->prev;
    }
    if ((temp = partitions[dest_partition].head)) {
        temp->prev = cur;
    }
    cur->prev = NULL;
    cur->next = temp;
    partitions[cur->state.partition].size--;
    partitions[dest_partition].size++;
    partitions[dest_partition].head = cur;
    cur->state.partition = dest_partition;
}
void AM_partition_init(Automaton_t* pa) {
    Node_state_t* nodes = &pa->state_nodes[0];
    int cnt = pa->state_nodes_cnt;
    pa->partitions[1].head = &nodes[cnt - 1];
    pa->partitions[1].size = cnt - 1;
    if (cnt <= 2) {
        nodes[1].state.partition = 1;
    }
    else {
        nodes[cnt - 1].next = &nodes[cnt - 2];
        nodes[cnt - 1].state.partition = 1;
        nodes[1].prev = &nodes[2];
        nodes[1].state.partition = 1;
    }
    for (int i = cnt - 2; i > 1; i--) {
        nodes[i].next = &nodes[i - 1];
        nodes[i].prev = &nodes[i + 1];
        nodes[i].state.partition = 1;
    }
    for (int i = 1; i < cnt; i++) {
        if (nodes[i].state.accept) AM_state_split(pa, i, 2);
    }
    if (pa->partitions[1].size == 0) {
        pa->partitions[1] = pa->partitions[2];
        pa->partitions_cnt = 2;
    }
    else {
        pa->partitions_cnt = pa->partitions[2].size == 0 ? 2 : 3;
    }
}
void Hopcroft_Minimization(Automaton_t* pa) {
    static struct _stack1 {
        int item[MAXSTATE + 1];
        int top;
    } invStack;
    static struct _stack2 {
        int item[MAXSTATE + 1];
        int instack[MAXSTATE + 1];
        int top;
    } workStack;
    static struct _list {
        Node_int_t nodes[MAXSTATE + 1];
        Node_int_t* head[MAXSTATE + 1];
        int inlist[MAXSTATE + 1];
        int len[MAXSTATE + 1];
        int nodes_size;
    } inverseList;
    Partition_t* partitions = &pa->partitions[0];
    Node_state_t* nodes = &pa->state_nodes[0];
    int partitions_cnt = pa->partitions_cnt;

    // If you want to call this function more than once, uncomment below.
    // memset(&inverseList, 0, sizeof(inverseList));
    memset(&workStack.instack, -1, sizeof(workStack.instack));
    workStack.top = -1;
    for (int i = 1; i < partitions_cnt; i++) {
        workStack.item[++workStack.top] = i;
        workStack.instack[i] = workStack.top;
    }
    while (workStack.top > -1) {
        int work_number = workStack.item[workStack.top--];
        workStack.instack[work_number] = -1;
        for (int c = 0; c < MAXSYMBOL; c++) {
            inverseList.nodes_size = 0;
            invStack.top = -1;
            for (Node_state_t* cur = partitions[work_number].head; cur != NULL; cur = cur->next) {
                for (Node_int_t* prev = cur->state.prev_head[c]; prev != NULL; prev = prev->next) {
                    int node_num = prev->value, part_num;
                    if (inverseList.inlist[node_num = prev->value]) continue;
                    part_num = nodes[node_num].state.partition;
                    inverseList.inlist[node_num] = 1;
                    inverseList.nodes[inverseList.nodes_size].value = node_num;
                    inverseList.nodes[inverseList.nodes_size].next = inverseList.head[part_num];
                    inverseList.head[part_num] = &inverseList.nodes[inverseList.nodes_size++];
                    if (inverseList.len[part_num] == 0) {
                        invStack.item[++invStack.top] = part_num;
                    }
                    inverseList.len[part_num]++;
                }
            }
            while (invStack.top > -1) {
                int i = invStack.item[invStack.top--];
                if (partitions[i].size <= 1 || inverseList.len[i] == partitions[i].size) {
                    for (Node_int_t* cur = inverseList.head[i]; cur != NULL; cur = cur->next) {
                        inverseList.inlist[cur->value] = 0;
                    }
                    inverseList.head[i] = NULL;
                    inverseList.len[i] = 0;
                    continue;
                }
                for (Node_int_t* cur = inverseList.head[i]; cur != NULL; cur = cur->next) {
                    int state_number = cur->value;
                    AM_state_split(pa, state_number, partitions_cnt);
                    inverseList.inlist[state_number] = 0;
                }
                if (workStack.instack[i] == -1) {
                    int smaller_number = partitions[i].size < inverseList.len[i] ? i : partitions_cnt;
                    workStack.item[++workStack.top] = smaller_number;
                    workStack.instack[smaller_number] = workStack.top;
                }
                else {
                    workStack.item[++workStack.top] = partitions_cnt;
                    workStack.instack[partitions_cnt] = workStack.top;
                }
                inverseList.head[i] = NULL;
                inverseList.inlist[i] = 0;
                inverseList.len[i] = 0;
                partitions_cnt++;
            }
        }
    }
    pa->partitions_cnt = partitions_cnt;
}
int main() {
    static Automaton_t am;
    char text[35];
    int N;
    scanf("%d ", &N);
    AM_state_init(&am);
    for (int i = 0; i < N; i++) {
        fgets(text, sizeof(text), stdin);
        AM_state_add_by_string(&am, text);
    }
    AM_partition_init(&am);
    Hopcroft_Minimization(&am);
    printf("%d\n", am.partitions_cnt - 1);
}