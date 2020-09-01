#include <iostream>

using namespace std;

int map[10];

int main() {

	int t;
	cin >> t;

	int a;
	int index = 0;
	for (int ii = 1; ii <= t; ii++) {
		cin >> a;

		if (a == 0) {
			int temp;
			cin >> temp;
			if (index == 10) {
				cout << "overflow" << endl;
				continue;
			}
			map[index] = temp;
			index++;
		}
		else if (a == 1) {
			if (index == 0) {
				cout << "underflow" << endl;
				continue;
			}
			index--;
			map[index] = 0;
		}
		else {
			break;
		}
	}

	for (int i = 0; i < index; i++) {
		cout << map[i] << " ";
		if (i == index - 1) {
			cout << endl;
		}
	}


	return 0;
}