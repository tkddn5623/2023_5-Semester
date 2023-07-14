#include <stdio.h>
#define MAXN (100000)

long long _sum(int arr[], int N, int dist) {
	long long sum = 0;
	for (int i = 1; i < N; i++) {
		long long a = ((long long)dist * i) - arr[i];
		sum += a >= 0 ? a : -a;
	}
	return sum;
}
long long solve8986(int arr[], int N) {
	long long answer = ~(1LL << 63);
	int low = 0, high = arr[N - 1];
	while (high - low >= 3) {
		int left, right;
		left = ((long long)low * 2 + high) / 3;
		right = (low + (long long)high * 2) / 3;
		if (_sum(arr, N, left) <= _sum(arr, N, right)) high = right;
		else low = left;
	}
	for (int i = low; i <= high; i++) {
		long long s = _sum(arr, N, i);
		if (answer > s) answer = s;
	}
	return answer;
}
int main() {
	static int arr[MAXN];
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) { scanf("%d", &arr[i]); }
	printf("%lld\n", solve8986(arr, N));
}