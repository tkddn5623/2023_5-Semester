#include <stdio.h>
#include <stdlib.h>
#define MAX (1000)
void solveA(const int row, const int col, const int K) {
	static int arr[MAX + 2][MAX + 2];
	for (int i = 1; i <= row; i++) for (int j = 0; j < col; j++) {
		arr[i][j + 1] = i + j;
	}
	if (arr[row][col] > K) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			printf("%d ", arr[i][j]);
		}
		putchar('\n');
	}
}
int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	solveA(N, M, K);
}