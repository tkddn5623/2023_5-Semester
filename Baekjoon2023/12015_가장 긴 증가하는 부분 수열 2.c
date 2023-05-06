#include <stdio.h>
#include <stdlib.h>
#define RANGE (1000000)
/* This function has side effect.*/
int binary_lower(const int arr[], int size, const int key) {
	int pos = -1, left = 0, mid;
	size = size - 1;
	while (left <= size) {
		mid = left + (size - left) / 2;
		if (arr[mid] >= key) {
			pos = mid;
			size = mid - 1;
		}
		else left = mid + 1;
	}
	return pos;
}
int lengthOfLIS(int nums[], int N) {
	int* pseudoLIS = calloc(N, sizeof(int)); if (!pseudoLIS) exit(1);
	int L = 0;
	pseudoLIS[L++] = nums[0];
	for (int i = 1; i < N; i++) {
		register int n = nums[i], p = pseudoLIS[L - 1];
		if (n > p) {
			pseudoLIS[L++] = nums[i];
		}
		else if (n < p) {
			pseudoLIS[binary_lower(pseudoLIS, L, n)] = n;
		}
	}
	free(pseudoLIS);
	return L;
}
int main() {
	static int nums[RANGE];
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}
	printf("%d\n", lengthOfLIS(nums, N));
}

/* BOJ 12015 */