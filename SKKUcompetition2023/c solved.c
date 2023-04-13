#include <stdio.h>
#include <stdlib.h>
int* getPrimeList(const int maxprime, int* psize) {
	int length = 0;
	int* notPrime = calloc(maxprime + 1, sizeof(int));
	int* primeList = calloc(maxprime, sizeof(int));
	int* shrunkList;
	if (notPrime == NULL || primeList == NULL) exit(1);
	notPrime[0] = 1;
	notPrime[1 <= maxprime ? 1 : 0] = 1;
	for (int i = 2; i <= maxprime; i++) {
		if (!notPrime[i]) primeList[length++] = i;
		for (int j = 0; j < length; j++) {
			if (i * primeList[j] > maxprime) break;
			notPrime[i * primeList[j]] = 1;
			if (i % primeList[j] == 0) break;
		}
	}
	free(notPrime);
	if (((shrunkList = malloc(length * sizeof(int))) == NULL)) exit(1);
	memcpy(shrunkList, primeList, length * sizeof(int));
	free(primeList);
	if (psize != NULL) *psize = length;
	return shrunkList;
}
int solveC(const int plist[], const int plist_len, const int N) {
	int query;
	int mid, pos = -1, left = 0, right = plist_len - 1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		printf("? %d\n", plist[mid]);
		fflush(stdout);
		scanf("%d", &query);
		if (query == 1) {
			left = mid + 1;
		}
		else {
			pos = mid;
			right = mid - 1;
		}
	}
	return plist[pos];
}
int main() {
	//freopen("o.txt", "w", stdout);
	int plist_len, N;
	int* plist;

	scanf("%d", &N);
	plist = getPrimeList(N, &plist_len);
	printf("! %d\n", solveC(plist, plist_len, N));

	free(plist);
}