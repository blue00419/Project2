#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int result = 0;

	int a = n;
	while (1) {
		a -= 5;
		if (a < 0) break;
		result++;
	}

	a = n;
	while (1) {
		a -= 25;
		if (a < 0) break;
		result++;
	}
	a = n;
	while (1) {
		a -= 125;
		if (a < 0) break;
		result++;
	}

	cout << result << endl;
}