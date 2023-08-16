#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#define MAXN (1000000)
static char* map;
void solve7570(int pos[], int N) {
	int count = 1;
	int max = 1;
	for (int i = 1; i < N; i++) {
		if (pos[i - 1] < pos[i]) {
			count++;
			if (max < count) max = count;
		}
		else count = 1;
	}
	printf("%d\n", N - max);
}
int readint() {
	int a, b;
	while ((a = *map++) && a < '0');
	for (b = a & 0xf; (a = *map++) >= '0'; b = b * 10 + (a & 0xf));
	return b;
}
int main() {
	static int pos[MAXN + 1];
	int N;
	struct stat st;
	fstat(0, &st);
	if ((map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, 0, 0)) == MAP_FAILED) return 1;
	N = readint();
	for (int i = 0; i < N; i++) { 
		pos[readint()] = i;
	}
	solve7570(pos, N);
}