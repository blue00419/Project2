#include<stdio.h>
#include<string.h>

char a[1001], b[1001];
int map[1001][1001];

int maxx(int c, int d) {
	if (c < d) {
		return d;
	}
	return c;
}

int main() {

	scanf("%s", a);
	scanf("%s", b);

	int asize = strlen(a), bsize = strlen(b);
	for (int i = 1; i <= bsize; i++) {
		for (int j = 1; j <= asize; j++) {
			map[i][j] = maxx(map[i - 1][j - 1] + (b[i - 1] == a[j - 1]),
				maxx(map[i - 1][j], map[i][j - 1]));
		}
	}

	printf("%d\n", map[bsize][asize]);

	return 0;
}