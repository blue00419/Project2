#include<iostream>

using namespace std;

int fi[91][40];

int main() {

	fi[1][0] = 1;

	for (int i = 2; i <= 90; i++) {
		for (int j = 0; j < 39; j++) {
			int a = fi[i - 2][j] + fi[i - 1][j] + fi[i][j];
			if (a >= 10) {
				a -= 10;
				fi[i][j + 1]++;
			}
			fi[i][j] = a;
		}
	}

	int n;
	cin >> n;

	int a;
	for (int j = 39; j >= 0; j--) {
		if (fi[n][j] != 0) {
			a = j;
			break;
		}
	}

	for (int i = a; i >=0; i--) {
		cout << fi[n][i];
	}
	cout << endl;

	return 0;
}