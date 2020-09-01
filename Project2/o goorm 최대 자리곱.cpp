#include <iostream>

using namespace std;

int map[10];

int main() {

	int n;
	cin >> n;

	int index = 0;
	while (1) {
		if (n == 0)break;
		map[index] = n % 10;
		n /= 10;
		index++;
	}

	int result = 1;
	for (int i = 0; i < index; i++) {
		result *= map[i];
	}

	int index2 = 0;

	while (1) {

		index2++;
		if (index2 >= index) break;
		while (1) {
			if (map[index2] == 0) {
				map[index2 - 1] = 9;
				index2++;
			}
			else {
				break;
			}
		}
		if (map[index2] != 1) {
			map[index2]--;
		}
		map[index2 - 1] = 9;

		int sum = 1;
		for (int i = 0; i < index; i++) {
			if (i == index - 1) {
				if (map[i] != 0) {
					sum *= map[i];
				}
			}
			else {
				sum *= map[i];
			}
		}
		if (result < sum) {
			result = sum;
		}
	}
	cout << result << endl;
	return 0;
}