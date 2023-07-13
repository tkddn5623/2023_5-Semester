#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

static char* map;
static char output[5000001];
static int output_i;
void writeint(int n) {
	int j = 1000;
	while (n > 1 && !(n / j)) { j /= 10; }
	do {
		output[output_i++] = '0' | n / j;
		n %= j;
		j /= 10;
	} while (j);
	output[output_i++] = '\n';
}
/*
int readint() {
    int a, b, c;
    while ((c = *input) && c < '-') input++;
    if (c == '-') input++;
    for (b = *input++ & 0xf; (a = *input++) >= '0'; b = b * 10 + (a & 0xf));
    return c == '-' ? -b : b;
}
*/
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
	write(1, output, output_i);
}
int main() {
	struct stat st;
	fstat(0, &st);
	if ((map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, 0, 0)) == MAP_FAILED) return 1;
	solve15552();
	munmap(map, st.st_size);
}