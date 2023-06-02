// Hopcroft Implementation, boj 3593
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
Automaton* AM_new(const int size) {
    Automaton* am = malloc(sizeof(Automaton)); if (!am) exit(1);
    am->states = calloc(size, sizeof(State)); if (!am->states) exit(1);
    am->len = 1;
    return am;
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
    //ArrayQueue* Worklist = AQ_new(MAXROW * MAXLEN);
    Automaton* am = AM_new(MAXROW * MAXLEN + 1);
    AM_construct(am, strs, N);
    Partition[0] = calloc(MAXROW * MAXLEN, sizeof(int)); if (!Partition[0]) exit(1);
    Partition[1] = calloc(MAXROW * MAXLEN, sizeof(int)); if (!Partition[1]) exit(1);
    for (int len = am->len, i = 0; i < len; i++) {
        if (am->states[i].accept) Partition[0][Partition_len[0]++] = i;
        else Partition[1][Partition_len[1]++] = i;
    }
    //while (!AQ_isEmpty(Worklist)) {}
}
int main() {
    static char text[MAXROW][MAXLEN + 1] = { 0 };
    static char* ptext[MAXROW] = { 0 };
    int N;
    scanf("%d ", &N);
    for (int i = 0; i < N; i++) {
        char* p;
        if (p = strchr(fgets(text[i], sizeof(text[i]), stdin), '\n')) *p = '\0';
        ptext[i] = text[i];
    }
    printf("%d\n", Hopcroft(ptext, N));
}