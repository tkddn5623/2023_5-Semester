// Hopcroft Implementation, boj 3593
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> // <time
#define MAXROW (5000)
#define MAXLEN (30)
#define MAXSYMBOL (26)
typedef struct _State {
    int next[MAXSYMBOL];
    int accept;
} State;
typedef struct {
    State* states;
    int len;
} Automaton;
typedef struct {
    int* items;
    int capacity;
    int front;
    int rear;
} ArrayQueue;
int binary_search(const int arr[], int size, const int key) {
    int pos = -1, left = 0, mid;
    size = size - 1;
    while (left <= size) {
        mid = left + (size - left) / 2;
        if (arr[mid] == key) return 1;
        else if (arr[mid] < key) left = mid + 1;
        else size = mid - 1;
    }
    return 0;
}
Automaton* AM_new(const int size) {
    Automaton* am = malloc(sizeof(Automaton)); if (!am) exit(1);
    am->states = calloc(size, sizeof(State)); if (!am->states) exit(1);
    am->len = 1;
    return am;
}
ArrayQueue* AQ_new(const int max) {
    ArrayQueue* q;
    q = malloc(sizeof(ArrayQueue)); if (!q) exit(1);
    q->items = calloc(max + 1, sizeof(int)); if (!q->items) exit(1);
    q->capacity = max + 1;
    q->front = 0;
    q->rear = 0;
    return q;
}
void AQ_delete(ArrayQueue* q) {
    free(q->items);
    free(q);
}
int AQ_isEmpty(const ArrayQueue* q) {
    return q->front == q->rear;
}
int AQ_size(const ArrayQueue* q) {
    const int subtract = q->rear - q->front;
    if (subtract >= 0) return subtract;
    else return q->capacity + subtract;
}
void AQ_push(ArrayQueue* q, const int item) {
    const int rear = q->rear;
    q->items[rear] = item;
    q->rear = (rear + 1) % q->capacity;
}
int AQ_pop(ArrayQueue* q) {
    const int front = q->front;
    q->front = (front + 1) % q->capacity;
    return q->items[front];
}
int AQ_peek(const ArrayQueue* q) {
    return q->items[q->front];
}
int* AQ_search(ArrayQueue* q, int key) {
    if (AQ_isEmpty(q)) return NULL;
    int rear = q->rear;
    int capacity = q->capacity;
    for (int i = q->front; i <= rear; i = (i + 1) % capacity) {
        if (q->items[i] == key) { return &q->items[i]; }
    }
    return NULL;
}
void AM_delete(Automaton* am) {
    free(am->states);
    free(am);
}
void AM_construct(Automaton* am, const char* const strs[], const int N) {
    State* state;
    char* cp;
    int value, n;
    for (int i = 0; i < N; i++) {
        cp = strs[i];
        n = 0;
        while (1) {
            state = &am->states[n];
            if ((value = (*cp - 'a')) < 0) {
                state->accept |= 0x1;
                break;
            }
            if (!state->next[value]) {
                state->next[value] = am->len++;
            }
            n = state->next[value];
            cp++;
        }
    }
}
int Hopcroft(const char strs[][MAXLEN + 1], const int N) {
    static int* Partition[MAXROW * MAXLEN];
    static int Partition_len[MAXROW * MAXLEN];
    int Partition_size = 2;
    ArrayQueue* Worklist = AQ_new(MAXROW * MAXLEN);
    Automaton* am = AM_new(MAXROW * MAXLEN + 1);
    AM_construct(am, strs, N);
    Partition[0] = calloc(MAXROW * MAXLEN, sizeof(int)); if (!Partition[0]) exit(1);
    Partition[1] = calloc(MAXROW * MAXLEN, sizeof(int)); if (!Partition[1]) exit(1);
    for (int len = am->len, i = 0; i < len; i++) {
        if (am->states[i].accept) Partition[0][Partition_len[0]++] = i;
        else Partition[1][Partition_len[1]++] = i;
    }
    AQ_push(Worklist, 0); AQ_push(Worklist, 1);
    while (!AQ_isEmpty(Worklist)) {
        int w = AQ_pop(Worklist);
        if (w == -1) continue;
        int* workset = Partition[w];
        int workset_len = Partition_len[w];
        int* P1, P1_len = 0;
        int* P2, P2_len = 0;
        for (int c = 0; c <= 'z' - 'a'; c++) {
            for (int i = 0; i < Partition_size; i++) {
                int plen = Partition_len[i];
                P1 = calloc(plen, sizeof(int)); if (!P1) exit(1);
                P2 = calloc(plen, sizeof(int)); if (!P2) exit(1);
                P1_len = 0;
                P2_len = 0;
                for (int j = 0; j < plen; j++) { //Maybe slow.
                    int state_curr = Partition[i][j];
                    int state_next = am->states[state_curr].next[c]; 
                    if (binary_search(workset, workset_len, state_next)) P1[P1_len++] = state_curr;
                    else P2[P2_len++] = state_curr;
                }
                if (P1_len <= 0 || P2_len <= 0) {
                    free(P1);
                    free(P2);
                }
                else {
                    int* qptr = NULL;
                    free(Partition[i]);
                    Partition[i] = P1;
                    Partition_len[i] = P1_len;
                    Partition[Partition_size] = P2;
                    Partition_len[Partition_size] = P2_len;

                    if (qptr = AQ_search(Worklist, i)) {
                        *qptr = -1;
                        AQ_push(Worklist, i);
                        AQ_push(Worklist, Partition_size);
                    }
                    else if (P1_len < P2_len) {
                        AQ_push(Worklist, i);
                    }
                    else {
                        AQ_push(Worklist, Partition_size);
                    }
                    Partition_size++;
                    if (i == w) goto CONTINUE;
                }
            }
        }
    CONTINUE:;
    }
    for (int i = 0; i < Partition_size; i++) { free(Partition[i]); }
    AQ_delete(Worklist);
    AM_delete(am);
    return Partition_size;
}
int main() {
    static char text[MAXROW][MAXLEN + 1];
    static char* ptext[MAXROW];
    int N;
    /*scanf("%d ", &N);
    for (int i = 0; i < N; i++) {
        char* p;
        if (p = strchr(fgets(text[i], sizeof(text[i]), stdin), '\n')) *p = '\0';
        ptext[i] = text[i];
    }*/
    N = 10;
    srand(1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < MAXLEN; j++) {
            text[i][j] = rand() % 26 + 'a';
        }
        ptext[i] = text[i];
    }
    double RT = (double)clock() / CLOCKS_PER_SEC;
    printf("%d\n", Hopcroft(ptext, N));
    double ET = (double)clock() / CLOCKS_PER_SEC;
    printf("Time : %f\n", ET - RT);
}