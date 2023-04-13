#define __USE_MINGW_ANSI_STDIO 0
#include <stdio.h>
int solveB(const int arr[], const int N) {
	int avi_total = 0;
	int avi_used = 0;
	int gunp_total = 0;
	int unknown_gender = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] == 1) {
			gunp_total++;
			unknown_gender++;
			if (avi_total < avi_used + unknown_gender) {
				avi_total = avi_used + unknown_gender;
			}
		}
		else {
			if (gunp_total > 0) {
				avi_used = gunp_total / 2 + 1;
			}
			unknown_gender = 0;
		}
	}
	return avi_total;
}
int main() {
	static int arr[100000];
	int _t;
	scanf("%d", &_t);
	while (_t--) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		printf("%d\n", solveB(arr, N));
	}
	
}