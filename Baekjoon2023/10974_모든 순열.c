#include <stdio.h>
#include <stdlib.h>
#define DOMAIN (8)
int _cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
void _printPermutations_impl(int nums[], const int count, const int N) {
	static int permutation[DOMAIN];
	static int visited[DOMAIN];
	if (count == N) {
		for (int i = 0; i < N; i++) {
			printf("%d ", permutation[i]);
		}
		putchar('\n');
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		permutation[count] = nums[i];
		_printPermutations_impl(nums, count + 1, N);
		visited[i] = 0;
	}
}
void printPermutations(int nums[], const int N) {
	qsort(nums, N, sizeof(int), _cmp);
	_printPermutations_impl(nums, 0, N);
}
int main() {
	int N;
	int nums[] = { 1,2,3,4,5,6,7,8 };
	scanf("%d", &N);
	printPermutations(nums, N);
}