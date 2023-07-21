#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXBUF (1020)
#define MAXALPHA (26)
#define TRIESIZE (997704)
typedef struct {
	int items[MAXBUF];
	int top;
} ArrayStack;
typedef struct _TrieNode {
	struct _TrieNode* next[MAXALPHA];
	int state; 
} TrieNode;
typedef struct {
	TrieNode* nodes;
	int len;
} Trie;
void AS_init(ArrayStack* pstack) {
	pstack->top = -1;
}
int AS_isEmpty(const ArrayStack* pstack) {
	return pstack->top == -1;
}
void AS_push(ArrayStack* pstack, int item) {
	pstack->items[++(pstack->top)] = item;
}
int AS_pop(ArrayStack* pstack) {
	return pstack->items[(pstack->top)--];
}
Trie* Trie_new(int node) {
	Trie* t = malloc(sizeof(Trie)); if (!t) exit(1);
	if (!(t->nodes = calloc(node, sizeof(TrieNode)))) exit(1);
	t->len = 1;
	return t;
}
void Trie_delete(Trie* trie) {
	free(trie->nodes);
	free(trie);
}
void Trie_insert(Trie* trie, const char* str, int invert) {
	TrieNode* pn = &trie->nodes[0];
	int value, i, j, len = strlen(str);
	if (!invert) i = 0, j = 1;
	else i = len - 1, j = -1;
	while (pn && i >= 0 && i < len) {
		value = str[i] - 'a';
		i += j;
		if (!pn->next[value]) {
			pn->next[value] = &trie->nodes[trie->len++];
		}
		pn = pn->next[value];
		pn->state++;
	}
}
void Trie_remove(Trie* trie, const char* str, int invert) {
	TrieNode* pn = &trie->nodes[0];
	int value, i, j, len = strlen(str);
	if (!invert) i = 0, j = 1;
	else i = len - 1, j = -1;
	while (pn && i >= 0 && i < len) {
		value = str[i] - 'a';
		i += j;
		if (!pn->next[value]) {
			exit(1); //remove non-existent elements
		}
		pn = pn->next[value];
		pn->state--;
	}
}
void Trie_search(Trie* trie1, Trie* trie2, const char* str) {
	static ArrayStack stack;
	int i, answer = 0;
	int value1, value2;
	TrieNode* pn1 = &trie1->nodes[0];
	TrieNode* pn2 = &trie2->nodes[0];
	AS_init(&stack);
	i = strlen(str) - 1;
	while (pn2 && i > 0) {
		value2 = str[i] - 'a';
		if ((pn2 = pn2->next[value2]) && pn2->state) {
			i--;
			AS_push(&stack, pn2->state);
		}
	}
	for (int j = 0; j < i && pn1; j++) {
		pn1 = pn1->next[str[j] - 'a'];
	}
	while (pn1 && !AS_isEmpty(&stack)) {
		value1 = str[i++] - 'a';
		if ((pn1 = pn1->next[value1]) && pn1->state) {
			int k = AS_pop(&stack);
			answer += pn1->state * k;
		}
	}
	printf("%d\n", answer);
}
int main() {
	char buf[MAXBUF + 2];
	char* command[3];
	int command_size, Q;
	Trie* trie[2];
	scanf("%d ", &Q);
	trie[0] = Trie_new(TRIESIZE);
	trie[1] = Trie_new(TRIESIZE);
	while (Q--) {
		char* cp, ch;
		if ((cp = strchr(fgets(buf, sizeof(buf), stdin), '\n'))) *cp = '\0';
		command[(command_size = 0)] = strtok(buf, " ");
		while (++command_size < 3 && (command[command_size] = strtok(NULL, " ")));
		if (!strcmp(command[0], "add") && command_size == 3) {
			ch = command[1][0];
			Trie_insert(trie[ch - 'A'], command[2], ch - 'A');
		}
		else if (!strcmp(command[0], "delete") && command_size == 3) {
			ch = command[1][0];
			Trie_remove(trie[ch - 'A'], command[2], ch - 'A');
		}
		else if (!strcmp(command[0], "find") && command_size == 2) {
			Trie_search(trie[0], trie[1], command[1]);
		}
	}
}