#include<iostream>

using namespace std;

int n;

void hanoi(int n, int from, int by, int to) {
	if (n == 1)
		printf("%d %d\n", from, to);
	else {
		hanoi(n - 1, from, to, by);
		printf("%d %d\n", from, to);
		hanoi(n - 1, by, from, to);
	}
}

void hanoinum(int x) {
	int num = 1;
	while (--x) {
		num = num * 2 + 1;
	}
	printf("%d\n", num);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	hanoinum(n);

	hanoi(n, 1,2,3);

	return 0;
}