#ifndef MAXCOL
#define MAXCOL (26)
#endif

#ifndef TRIE_H
#define TRIE_H
typedef struct _TreeNode {
	struct _TreeNode* next[MAXCOL];
	int state; // 1st bit: is final state?, 2nd bit: does it have child?
} TrieNode;
typedef struct {
	TrieNode* nodes;
	int len;
} Trie;
Trie* Trie_new(int node);
void Trie_delete(Trie* trie);
void Trie_insert(Trie* trie, const char* str);
int _Trie_search(TrieNode* node);
#endif

/*
* 2023.7.19 Wed
*/