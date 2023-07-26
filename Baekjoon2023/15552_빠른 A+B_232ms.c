#include <stdio.h>
#include <stdlib.h>
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

	if ((cp = strchr(fgets(buf, sizeof(buf), stdin), '\n'))) *cp = '\0';
	map = buf;
	T = readint();
	while (T--) {
		if ((cp = strchr(fgets(buf, sizeof(buf), stdin), '\n'))) *cp = '\0';
		map = buf;
		a = readint();
		b = readint();
		printf("%d\n", a + b);
	}
}
int main() {
	solve15552();
}