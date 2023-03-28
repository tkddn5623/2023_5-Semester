//Boj 27652
#include <stdio.h>
#include <string.h>
#define MAXBUF (1010)
#define MAXARG (2)
int main() {
	int N;
	char buffer[MAXBUF] = { 0 };
	char* args[MAXARG + 1] = { 0 };
	int argslen;
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		char* p;
		if (p = strchr(fgets(buffer, MAXBUF, stdin), '\n')) *p = '\0';
		if (!(args[(argslen = 0)] = strtok(buffer, " "))) continue;
		while (args[++argslen] = strtok(NULL, " "));
		
		if (!strcmp(args[0], "add")) {
			
		}
		else if (!strcmp(args[0], "delete")) {
			
		}
		else if (!strcmp(args[0], "find")) {
			
		}
	}
}