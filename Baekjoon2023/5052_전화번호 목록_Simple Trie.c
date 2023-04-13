// Trie Practice; boj 5052
#include <stdio.h>
#include <stdlib.h>
#define MAXROW (10000)
#define MAXCOL (10)
typedef struct _TreeNode {
	struct _TreeNode* next[MAXCOL];
	int state; // 1st bit: is final state?, 2nd bit: does it have child?
} TrieNode;
typedef struct {
	TrieNode* nodes;
	int len;
} Trie;
Trie* Trie_new(const int node) {
	Trie* t = malloc(sizeof(Trie)); if (!t) exit(1);
	t->nodes = calloc(node, sizeof(TrieNode)); if (!t->nodes) exit(1);
	t->len = 1;
	return t;
}
void Trie_delete(Trie* trie) {
	free(trie->nodes);
	free(trie);
}
void Trie_insert(Trie* trie, const char* str) {
	TrieNode* pn = &trie->nodes[0];
	int value;
	while (pn) {
		value = *str - '0';
		if (value < 0) {
			pn->state |= 0x1;
			break;
		}
		if (!pn->next[value]) {
			pn->next[value] = &trie->nodes[trie->len++];
			pn->state |= 0x2;
		}
		pn = pn->next[value];
		str++;
	}
}
int _Trie_search(TrieNode* node) {
	if (node->state == 0x3) return 0;
	else if (node->state == 0x2) {
		for (int i = 0; i < MAXCOL; i++) {
			if (node->next[i] && !_Trie_search(node->next[i])) return 0;
		}
	}
	return 1;
}
int solve5052(const char strs[][MAXCOL + 1], const int N) {
	Trie* trie = Trie_new(71110);
	int ret;
	for (int i = 0; i < N; i++) {
		Trie_insert(trie, strs[i]);
	}
	ret = _Trie_search(&trie->nodes[0]);
	Trie_delete(trie);
	return ret;
}
int main() {
	static char strs[MAXROW][MAXCOL + 1];
	int _t;
	scanf("%d", &_t);
	while (_t--) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) { scanf("%s", strs[i]); }
		switch (solve5052(strs, N)) {
		case 0: printf("NO\n"); break;
		case 1: printf("YES\n"); break;
		}
	}
}