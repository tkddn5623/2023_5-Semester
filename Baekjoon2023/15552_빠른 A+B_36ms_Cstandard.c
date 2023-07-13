#include <stdio.h>
#include <stdlib.h>

static char* input;
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
	while ((a = *input++) && a < '0');
	for (b = a & 0xf; (a = *input++) >= '0'; b = b * 10 + (a & 0xf));
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
	puts(output);
}
void _io() {
	fseek(stdin, 0, 2);
	int input_sz = ftell(stdin);
	if (!(input = calloc(input_sz, sizeof(char)))) exit(1);
	fseek(stdin, 0, 0);
	fread(input, 1, input_sz, stdin);
}
int main() {
	_io();
	solve15552();
}