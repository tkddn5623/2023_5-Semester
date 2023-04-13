#include <stdio.h>
#include <stdlib.h>
#define MAX (1000010)

int main() {
	static long long presum[MAX + 1] = { 0 }; //right to left.
	static int num[MAX] = { 0 };
	long long total = 0;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = N - 1; i >= 0; i--) {
		presum[i] = presum[i + 1] + num[i];
	}
	for (int i = 1; i < N - 1; i++) {
		long long leftsum = presum[0] - presum[i];
		int left, right, mid;
		int border_l = -1, border_r = -1;

		left = i, right = N;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (presum[mid] > leftsum) {
				border_r = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		if (border_r == -1) continue;

		left = i, right = border_r;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (presum[i] -presum[mid] > presum[mid]) {
				border_l = mid;
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		if (border_l > border_r || border_l == -1 || border_r == -1) continue;
		total += border_r - border_l + 1;
	}
	printf("%lld\n", total);
}