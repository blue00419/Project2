#include<stdio.h>
#include<string.h>

int main() {

	char n[31];
	int b;
	scanf("%s %d", n, &b);

	int index = strlen(n) - 1;
	
	int result = 0;
	int c = 1;
	for (int i = index; i >= 0; i--) {
		int a = n[i];
		if (a >= 65) {
			a -= 55;
		}
		else {
			a -= 48;
		}
		result += c * a;
		c *= b;
	}
	printf("%d\n", result);

	return 0;
}