#include <unistd.h>
#include <stdio.h> // <<<
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>

static char* map;

void writeint(int n) {
	char s[12] = { '0' };
	int i = 0;
	int j = 1000;
	while (j > 1 && !(n / j)) { j /= 10; }
	do {
		s[i++] = '0' | n / j;
		n %= j;
		j /= 10;
	} while (j);
	printf("%s\n", s);
}
int readint() {
	int a, b;
	while ((a = *map++) && a < '0');
	for (b = a & 0xf; (a = *map++) >= '0'; b = b * 10 + (a & 0xf));
	return b;
}
void solve15552() {
	int T = readint();
	int a, b;
	while (T--) {
		a = readint();
		b = readint();
		writeint(a + b);
	}
}
int main() {
	struct stat st;
	fstat(0, &st);
	if ((map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, 0, 0)) == MAP_FAILED) exit(1);
	solve15552();
	munmap(map, st.st_size);
}