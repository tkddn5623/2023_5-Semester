#include <stdio.h>
#include <string.h>
static char* map;

int readint() {
	int a, b;
	while ((a = *map++) && a < '0');
	for (b = a & 0xf; (a = *map++) >= '0'; b = b * 10 + (a & 0xf));
	return b;
}
void solve15552() {
	char* cp;
	char buf[11];
	int T, a, b;

	fgets(buf, sizeof(buf), stdin);
	map = buf;
	T = readint();
	while (T--) {
		fgets(buf, sizeof(buf), stdin);
		map = buf;
		a = readint();
		b = readint();
		printf("%d\n", a + b);
	}
}
int main() {
	solve15552();
}