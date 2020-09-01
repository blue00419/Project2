#include<stdio.h>

char map[21];

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	int index = 0;
	int a;
	while (1) {
		a = m % n;
		m /= n;
		if (a < 10) {
			map[index] = a + '0';
		}
		else if (a == 10) {
			map[index] = 'A';
		}
		else if (a == 11) {
			map[index] = 'B';
		}
		else if (a == 12) {
			map[index] = 'C';
		}
		else if (a == 13) {
			map[index] = 'D';
		}
		else if (a == 14) {
			map[index] = 'E';
		}
		else if (a == 15) {
			map[index] = 'F';
		}
		index++;
		if (m == 0)break;
	}

	index--;
	for (int i = index; i >= 0; i--) {
		printf("%c", map[i]);
	}
	printf("\n");

	return 0;
}