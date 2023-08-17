#include <stdio.h>
#include <string.h>
#define MAXN (200)

void solve1013(const char* str) {
	static int states[16][3] = {
		{0, 0},
		{2, 3},
		{0, 4},
		{5, 0},
		{2, 3, 1},
		{6, 0},
		{6, 7},
		{2, 8, 1},
		{9, 8, 1},
		{6, 4},
	};
	char ch;
	int current = 1;
	while ((ch = *str++) >= '0' && (current = states[current][ch & 0xf]));
	if (states[current][2]) puts("YES");
	else puts("NO");
}
int main() {
	static char str[MAXN + 2];
	int N;
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		fgets(str, sizeof(str), stdin);
		solve1013(str);
	}
}