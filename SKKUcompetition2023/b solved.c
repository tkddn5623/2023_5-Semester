#include <stdio.h>
#include <string.h>
#define MAXLEN (1000010)
void getline_(char* _Buffer) {
	char* cp;
	if (cp = strchr(fgets(_Buffer, MAXLEN, stdin), '\n')) *cp = '\0';
}
void printS(const char tok[]) {
	const int len = strlen(tok);
	int prev = 0;
	for (int i = 0; tok[i] != '\0'; i++) {
		char c;
		switch ((c = tok[i])) {
		case '<':
		case '>':
		case '(':
		case ')':
			if (i == 0) {
				printf("%c", c);
				if (i != len - 1) putchar(' ');
			}
			else if (i == len - 1) {
				if (prev == 0) putchar(' ');
				printf("%c", c);
			}
			else {
				if (prev == 0) putchar(' ');
				printf("%c ", c);
			}
			prev = 1;
			break;
		case '&':
		case '|':
			if (tok[i + 1] == c) {
				if (i == 0) {
					printf("%c%c", c, c);
					if (i != len - 2) putchar(' ');
				}
				else if (i == len - 2) {
					if (prev == 0) putchar(' ');
					printf("%c%c", c, c);
				}
				else {
					if (prev == 0) putchar(' ');
					printf("%c%c ", c, c);
				}
				prev = 1;
				i++;
			}
			else {
				printf("%c", c);
				prev = 0;
			}
			break;
		default:
			printf("%c", c);
			prev = 0;
			break;
		}
	}
}
int main() {
	static char buf[MAXLEN];
	static char* tokens[MAXLEN];
	int tokens_size = 0;
	getline_(buf);
	if ((tokens[0] = strtok(buf, " ")) != NULL) {
		while ((tokens[++tokens_size] = strtok(NULL, " ")) != NULL);
	}
	for (int i = 0; i < tokens_size; i++) {
		printS(tokens[i]);
		if (i != tokens_size - 1) putchar(' ');
	}
}