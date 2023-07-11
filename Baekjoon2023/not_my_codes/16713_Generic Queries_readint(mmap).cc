//https://www.acmicpc.net/source/11883808
#include <cstdio>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
using namespace std;

char *p;
inline int readInt() {
	int t, r;
	for (r = *p++ & 15; (t = *p++) > 40; r = r * 10 + (t & 15));
	return r;
}

int main() {
    struct stat buf;
    fstat(0, &buf);
    p = (char *)mmap(0, buf.st_size, PROT_READ, MAP_SHARED, 0, 0);
    
	int N, Q;
	N = readInt(), Q = readInt();

	int sum[1000001]{};
	for (int val, i = 1; i <= N; ++i) sum[i] = sum[i - 1] ^ readInt();

	int ans = 0;
	while (Q--) {
        ans ^= sum[readInt() - 1];
        ans ^= sum[readInt()];
	}

	printf("%d", ans);

	return 0;
}