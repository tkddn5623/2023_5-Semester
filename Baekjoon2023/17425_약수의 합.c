#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000
int* getFactorList(const int maxprime) {
	int length = 0;
	int* factorList = calloc(maxprime + 2, sizeof(int));
	int* primeList = calloc(maxprime, sizeof(int));
	if (factorList == NULL || primeList == NULL) exit(1);
	factorList[0] = -1, factorList[1] = -1;
	for (int i = 2; i <= maxprime; i++) {
		if (!factorList[i]) primeList[length++] = i;
		for (int j = 0; j < length; j++) {
			if (i * primeList[j] > maxprime) break;
			factorList[i * primeList[j]] = primeList[j];
			if (i % primeList[j] == 0) break;
		}
	}
	free(primeList);
	return factorList;
}
long long int sumFactor(const int X, const int* factor) {
	static int isInit = 0;
	static long long int* memo = NULL;
	if (!isInit) {
		isInit = 1;
		memo = calloc(MAX + 1, sizeof(long long int));
		memo[1] = 1;
		long long int answer = 1;
		for (int i = 2; i <= MAX; i++) {
			int number = i, base = 1, basesquare = 1, subproduct = 1;
			int product = 1;
			while (1) {
				if (factor[number] == 0) {
					if (number == base) {
						basesquare *= number;
						subproduct += basesquare;
						product *= subproduct;
						break;
					}
					else {
						product = product * subproduct * (1 + number);
						break;
					}
				}
				else if (factor[number] != base) {
					product *= subproduct;
					base = factor[number];
					basesquare = 1;
					subproduct = 1;
					continue;
				}
				else {
					basesquare *= factor[number];
					subproduct += basesquare;
					number /= factor[number];
				}
			}
			answer += product;
			memo[i] = answer;
		}
	}
	return memo[X];
}
int main() {
	int* factor = getFactorList(MAX);
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int X;
		scanf("%d", &X);
		printf("%lld\n", sumFactor(X, factor));
	}
	free(factor);
}

/*
* 두 자연수 A와 B가 있을 때, A = BC를 만족하는 자연수 C를 A의 약수라고 한다. 
* 예를 들어, 2의 약수는 1, 2가 있고, 24의 약수는 1, 2, 3, 4, 6, 8, 12, 24가 있다. 
* 자연수 A의 약수의 합은 A의 모든 약수를 더한 값이고, f(A)로 표현한다. 
* x보다 작거나 같은 모든 자연수 y의 f(y)값을 더한 값은 g(x)로 표현한다.
*
* 자연수 N이 주어졌을 때, g(N)을 구해보자.
* 첫째 줄에 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.
*/