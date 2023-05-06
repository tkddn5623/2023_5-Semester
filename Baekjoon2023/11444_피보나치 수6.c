#include <stdio.h>
#define RANGE (1000000007)
#define DIM (2)
int* matmul(int dest[][DIM], int operand[][DIM], int N) {
	int mat[DIM][DIM] = { 0 };
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		int sum = 0;
		for (int k = 0; k < N; k++) {
			sum += ((long long)operand[i][k] * dest[k][j]) % RANGE;
			sum %= RANGE;
		}
		mat[i][j] = sum % RANGE;
	}
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		dest[i][j] = mat[i][j];
	}
	return dest;
}
int* matsqr(int dest[][DIM], int N, long long E) {
	int mat[DIM][DIM];
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		mat[i][j] = dest[i][j];
	}
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		if (i == j) dest[i][i] = 1;
		else dest[i][j] = 0;
	}
	while (E > 0LL) {
		if (E % 2 == 1) { matmul(dest, mat, N); }
		matmul(mat, mat, N);
		E /= 2;
	}
	return dest;
}
int nth_fibonacci(const long long N) {
	static const int fib[2] = { 0,1 };
	if (N < sizeof(fib) / sizeof(fib[0])) return fib[N];
	int mat_left[DIM][DIM] = { {1,1},{1,0} };
	matsqr(mat_left, DIM, N - 1);
	return mat_left[0][0];

}
int main() {
	long long N;
	scanf("%lld", &N);
	printf("%d\n", nth_fibonacci(N));
}