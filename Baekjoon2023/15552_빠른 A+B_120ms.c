#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>

static char* map;

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
		printf("%d\n", a + b);
	}
}
int main() {
	struct stat st;
	fstat(0, &st);
	if ((map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, 0, 0)) == MAP_FAILED) exit(1);
	solve15552();
	munmap(map, st.st_size);
}