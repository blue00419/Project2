#include<stdio.h>
#include<stdbool.h>

int n;
long long k;
char map[51];
static long long number = 0;

void dfs(int cnt) {
	if (cnt == n) {

		int left = 0;
		bool ok = true;
		for (int i = 0; i < n; i++) {
			
			if (map[i] == '(') {
				left++;
			}
			else {
				if (left > 0) {
					left--;
				}
				else {
					ok = false;
				}
			}
		}
		
		if (ok == true && left == 0)
			return;
		
		number++;
		
		if (number == k + 1) {
			for (int i = 0; i < n; i++) {
				printf("%c", map[i]);
			}
			printf("\n");
			exit(0);
		}
		
		return;
	}

	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			map[cnt] = '(';
			dfs(cnt + 1);
		}
		else {
			map[cnt] = ')';
			dfs(cnt + 1);
		}
	}
}

int main() {

	scanf("%d %lld", &n, &k);

	dfs(0);

	return 0;
}