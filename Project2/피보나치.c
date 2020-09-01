#include<stdio.h>

long long fibo[100];

long long fi(int n) {
	if (n == 1 || n == 2) {
		fibo[n] = 1;
	}
	if (fibo[n] != 0) {
		return fibo[n];
	}
	return fibo[n] = fi(n - 1) + fi(n - 2);
}

int main() {

	/*fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;

	for (int i = 3; i < 100; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	for (int i = 1; i < 100; i++) {
		printf("%lld\n", fibo[i]);
	}*/

	printf("%d\n", fi(10));

	return 0;

}