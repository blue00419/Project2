#include<stdio.h>
#include<string.h>
#include<wchar.h>

int map[1002][1002];

int main() {
	char a[3003], b[3003];
	fgets(a, sizeof(a), stdin);
	fgets(b, sizeof(b), stdin);
	
	int asize = strlen(a), bsize = strlen(b);
	for (int i = 1; i <= bsize/3; i++) {
		for (int j = 1; j <= asize/3; j++) {
			int temp = map[i - 1][j];
			if (map[i][j - 1] > temp) {
				temp = map[i][j - 1];
			}
			int aindex = (j - 1) * 3;
			int bindex = (i - 1) * 3;
			int ok = 0;
			if (a[aindex] == b[bindex] && a[aindex+1] == b[bindex+1]
				&& a[aindex + 2] == b[bindex + 2]) {
				ok = 1;
			}
			if (map[i - 1][j - 1] + ok > temp) {
				temp = map[i - 1][j - 1] + ok;
			}
			map[i][j] = temp;
		}
	}

	printf("%d\n", map[bsize/3][asize/3]);

	return 0;
}