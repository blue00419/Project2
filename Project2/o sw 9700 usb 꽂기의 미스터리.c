#include<stdio.h>

int main() {

	int t;
	scanf("%d", &t);

	for (int ii = 1; ii <= t; ii++) {
		double a, b;
		scanf("%lf %lf", &a, &b);

		double s1, s2;

		s1 = (1 - a) * b;
		s2 = a * (1 - b) * b;

		if (s2 > s1) {
			printf("#%d YES\n", ii);
		}
		else {
			printf("#%d NO\n", ii);
		}

	}

	return 0;
}