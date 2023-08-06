// Hopcroft Implementation, boj 3593
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> // <time
#define MAXROW (5000)
#define MAXLEN (30)
#define MAXSYMBOL (26)
int INL, TOTALJ1, TOTALJ2;
typedef struct {
    int e1;
    int e2;
} Pair_t;
typedef struct _State {
    int next[MAXSYMBOL];
    int accept;
} State;
typedef struct {
    State states[MAXROW * MAXLEN + 1];
    int len;
} Automaton;
int Binary_exist(const int arr[], int size, int key) {
    int left = 0, mid;
    size = size - 1;
    while (left <= size) {
        mid = left + (size - left) / 2;
        if (arr[mid] == key) return 1;
        else if (arr[mid] < key) left = mid + 1;
        else size = mid - 1;
    }
    return 0;
}
void _MergeSort_impl(int* list, int* sorted, const int left, const int right) {
    if (left >= right) return;
    const int mid = left + (right - left) / 2;
    _MergeSort_impl(list, sorted, left, mid);
    _MergeSort_impl(list, sorted, mid + 1, right);
    int idx, first, second;
    idx = left, first = left, second = mid + 1;
    while (first <= mid && second <= right) {
        if (list[first] <= list[second]) sorted[idx++] = list[first++];
        else sorted[idx++] = list[second++];
    }
    while (first <= mid)    sorted[idx++] = list[first++];
    while (second <= right) sorted[idx++] = list[second++];
    for (int i = left; i <= right; i++) list[i] = sorted[i];
}
void MergeSort(int* list, int size) {
    static int sorted[MAXROW * MAXLEN + 1];
    _MergeSort_impl(list, sorted, 0, size - 1);
}
void AM_construct(Automaton* am, const char* strs[], int inv[][MAXSYMBOL], const int N) {
    const char* cp;
    int value, n, m;
    State* state;
    am->len = 1;
    for (int i = 0; i < N; i++) {
        cp = strs[i];
        n = 0;
        while (1) {
            state = &am->states[n];
            if ((value = (*cp++ - 'a')) < 0) {
                state->accept |= 0x1;
                break;
            }
            if (!(m = state->next[value])) {
                m = am->len++;
                state->next[value] = m;
            }
            inv[m][value] = n;
            n = m;
        }
    }
}
int _Hopcroft_set_exist(int worksets[], int from, int to, int key) {
    while (from <= to) {
        if (worksets[from++] == key) return 1;
    }
    return 0;
}
int Hopcroft(const char* strs[], const int N) {
    static Automaton am;
    static int* partitions[MAXROW * MAXLEN + 2];
    static int partitions_size[MAXROW * MAXLEN + 2];
    static int partitions_image_size[MAXROW * MAXLEN + 2];
    static int state_part_pointer[MAXROW * MAXLEN * 1]; // input: State number
    static int inv_pointer[MAXROW * MAXLEN + 1][MAXSYMBOL];
    static int worksets[MAXROW * MAXLEN + 1];
    static int imageset[MAXROW * MAXLEN + 1];
    int partitions_cnt, worksets_idx, worksets_cnt;

    AM_construct(&am, strs, inv_pointer, N);
    partitions_cnt = 3;
    worksets_idx = 0;
    worksets_cnt = 2;
    if (!(partitions[1] = calloc(N * MAXLEN + 1, sizeof(int)))) exit(1);
    if (!(partitions[2] = calloc(N * MAXLEN + 1, sizeof(int)))) exit(1);
    memset(state_part_pointer, -1, sizeof(state_part_pointer));
    memset(worksets, -1, sizeof(worksets));
    worksets[0] = 1;
    worksets[1] = 2;
    for (int j = am.len, i = 0; i < j; i++) {
        if (am.states[i].accept) {
            partitions[1][partitions_size[1]++] = i;
            state_part_pointer[i] = 1;
        }
        else {
            partitions[2][partitions_size[2]++] = i;
            state_part_pointer[i] = 2;
        }
    }
    //printf("%d-%d\n", partitions_size[1], partitions_size[2]);
    while (1) {
        int w;
        if ((w = worksets[worksets_idx]) == -1) break;
        //printf("~~~~~~~~~~~~~~~~~~w is %d, size %d\n", w, partitions_size[w]);
        //if (partitions_size[w] == 1) continue;
        if (partitions_size[w] < 1) {
            //printf("W: %d, size: %d\n", w, partitions_size[w]);
            exit(-1); //Debug code
        }
        for (int i = 0; i < MAXSYMBOL; i++) {
            int imageset_size = 0;
            memset(partitions_image_size, 0, partitions_cnt * sizeof(int));
            for (int k = partitions_size[w], j = 0; j < k; j++) {
                int state;
                if (!(state = inv_pointer[partitions[w][j]][i])) continue;
                imageset[imageset_size++] = state;
                partitions_image_size[state_part_pointer[state]]++;
                //printf("Temp %d raise the idx %d\n", state, state_part_pointer[state]);

            }
            MergeSort(imageset, imageset_size);
            for (int j = 1; j < partitions_cnt; j++) {
                TOTALJ1++;
                int* p1, * p2, p1size, p2size, p0size;
                //printf("(j %d), Jump condition: %d,%d\n", j, partitions_image_size[j], partitions_size[j]);
                if (partitions_image_size[j] == 0 || partitions_size[j] == 0 ||
                    partitions_image_size[j] == partitions_size[j]) continue;
                p0size = partitions_size[j];
                p1size = 0;
                p2size = 0;
                p1 = calloc(p0size, sizeof(int));
                p2 = calloc(p0size, sizeof(int));
                TOTALJ2++;
                if (!p1 | !p2) exit(1);
                for (int k = 0; k < p0size; k++) {
                    INL++;
                    int state = partitions[j][k];
                    if (Binary_exist(imageset, imageset_size, state)) {
                        p1[p1size++] = state;
                        //printf("State %d is detected\n", state);
                    }
                    else p2[p2size++] = state;
                }
                //printf("p1size %d, p2size %d\n", p1size, p2size);
                //worksets[worksets_cnt++] = partitions_cnt;
                free(partitions[j]);
                p1 = realloc(p1, p1size * sizeof(int));
                p2 = realloc(p2, p2size * sizeof(int));
                if (p1size <= p2size) {
                    partitions[j] = p1;
                    partitions[partitions_cnt] = p2;
                    partitions_size[j] = p1size;
                    partitions_size[partitions_cnt++] = p2size;
                    for (int k = 0; k < p2size; k++) {
                        state_part_pointer[p2[k]] = partitions_cnt - 1;
                    }
                    //partitions_image_size[j] = p1size;
                }
                else {
                    partitions[j] = p2;
                    partitions[partitions_cnt] = p1;
                    partitions_size[j] = p2size;
                    partitions_size[partitions_cnt++] = p1size;
                    for (int k = 0; k < p1size; k++) {
                        state_part_pointer[p1[k]] = partitions_cnt - 1;
                    }
                    partitions_image_size[j] = 0;
                    partitions_image_size[partitions_cnt] = p1size;
                }
                if (_Hopcroft_set_exist(worksets, worksets_idx + 1, worksets_cnt, j)) {
                    worksets[worksets_cnt++] = partitions_cnt - 1;
                }
                else if (w == j) {
                    worksets_idx--;
                    goto ESCAPE;
                }

            }



        } ESCAPE:;
        worksets_idx++;
    }


    return partitions_cnt - 1;
}
int main() {
    //FILE* fo = fopen("o.txt", "w");
    static char fpath[15] = "./tests/"
        "03";
    freopen(fpath, "r", stdin);
    FILE* FANS = fopen(strcat(fpath, ".a"), "r");
    static int ANSW;
    fscanf(FANS, "%d", &ANSW);

    static char text[MAXROW][MAXLEN + 1];
    static const char* ptext[MAXROW];
    int N;
    scanf("%d ", &N);
    for (int i = 0; i < N; i++) {
        char* p;
        if ((p = strchr(fgets(text[i], sizeof(text[i]), stdin), '\n'))) *p = '\0';
        ptext[i] = text[i];
    }
    /*N = 100;
    srand(1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < MAXLEN; j++) {
            text[i][j] = rand() % 26 + 'a';
        }
        fprintf(fo, "%s\n", text[i]);
    }
    for (int i = 0; i < N; i++) {
        ptext[i] = text[i];
    }*/
    double RT = (double)clock() / CLOCKS_PER_SEC;
    printf("%d\n", Hopcroft(ptext, N));
    printf("%d\n", ANSW);
    double ET = (double)clock() / CLOCKS_PER_SEC;
    printf("Time : %f\n", ET - RT);
    printf("INL %d\n", INL);
    printf("TOTALJ %d, %d.\n", TOTALJ1, TOTALJ2);
}