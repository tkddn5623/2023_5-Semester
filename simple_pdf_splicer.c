#include <stdio.h>
#include <string.h>
#define MAXSIZE (5000000)

/*
* Usage:
* 1. Modify prefix string.
* 2. Determining whether 48 lines are even or odd.
* 3. Done.
* 4. (Optional) modify maxint in writeint function.
* 2023. 7. 21. Fri.
*/
const char* prefix = "The Rust Programming Language (2019) ";
const char* suffix = ".pdf";
const char* outname = "Rust(2019) - ";
static char big[MAXSIZE];
char buf[100];
char buf2[100];

char* writeint(char* str, int n) {
	int i = 0;
	int j = 1000;
	while (j > 1 && !(n / j)) { j /= 10; }
	do {
		str[i++] = '0' | n / j;
		n %= j;
		j /= 10;
	} while (j);
	str[i++] = '\0';
	return str;
}
int main() {
	char numstr[10];
	int i;
	FILE* fin, *fout;
	for (i = 1;; i++) {
		int input_sz;
		memset(big, 0, sizeof(big));

		memset(buf, 0, sizeof(buf));
		memset(buf2, 0, sizeof(buf2));

		strcat(buf, prefix);
		strcat(buf, writeint(numstr, i));
		strcat(buf, suffix);

		strcat(buf2, outname);
		strcat(buf2, writeint(numstr, i * 2));
		strcat(buf2, suffix);

		if (!(fin = fopen(buf, "rb"))) {
			printf("File(in) open error\n");
			break;
		}
		if (!(fout = fopen(buf2, "wb"))) {
			printf("File(out) open error\n");
			break;
		}
		fseek(fin, 0, 2);
		input_sz = ftell(fin);
		fseek(fin, 0, 0);

		fread(big, 1, input_sz, fin);
		fwrite(big, 1, input_sz, fout);

		fclose(fin);
		fclose(fout);
	}
}