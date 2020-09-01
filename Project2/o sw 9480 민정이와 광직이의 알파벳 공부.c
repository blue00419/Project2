#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int map[26];
char word[15][100];
static int counter = 0;
bool visit[15];
int n;

void dfs(int cnt) {
	for (int i = 0; i < strlen(word[cnt]); i++) {
		int a = word[cnt][i];
		map[a - 97]--;
		if (map[a - 97] == 0) return;
	}
	
	counter++;
	int remap[26];
	for (int i = 0; i < 26; i++) {
		remap[i] = map[i];
	}
	for (int i = cnt+1; i < n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			dfs(i);
			visit[i] = 0;
			for (int j = 0; j < 26; j++) {
				map[j] = remap[j];
			}
		}
	}
}

int main() {

	int t;
	scanf("%d", &t);

	for (int ii = 1; ii <= t; ii++) {

		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		counter = 0;

		scanf("%d", &n);


		for (int i = 0; i < n; i++) {
			scanf("%s", word[i]);
			for (int j = 0; j < strlen(word[i]); j++) {
				int a = word[i][j];
				map[a - 97]++;
			}
		}
		// a 97
		int a = 0;
		for (int i = 0; i < 26; i++) {
			if (map[i] != 0) {
				a++;
			}
		}
		if (a != 26) {
			printf("#%d 0\n", ii);
		}
		else {

			int remap[26];
			for (int i = 0; i < 26; i++) {
				remap[i] = map[i];
			}

			counter++;
			for (int i = 0; i < n; i++) {
				visit[i] = 1;
				dfs(i);
				visit[i] = 0;
				for (int j = 0; j < 26; j++) {
					map[j] = remap[j];
				}
			}
			printf("#%d %d\n", ii, counter);
		}
	}

}