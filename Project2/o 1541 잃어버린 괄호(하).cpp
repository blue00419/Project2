#include<iostream>
#include<string>

using namespace std;


int main() {
	string str;
	cin >> str;

	int a = 0;
	int index = 0;
	int result = 0;
	while (1) {
		if (index == str.length()) {
			int c = 0;
			int d = 1;
			for (int i = index - 1; i >= a; i--) {
				c += d * (str[i] - '0');
				d *= 10;
			}
			result += c;
			cout << result << endl;
			return 0;
		}
		if (str[index] == '-') {
			int c = 0;
			int d = 1;
			for (int i = index - 1; i >= a; i--) {
				c += d * (str[i] - '0');
				d *= 10;
			}
			result += c;
			a = index + 1;
			break;
		}
		if (str[index] == '+') {
			int c = 0;
			int d = 1;
			for (int i = index - 1; i >= a; i--) {
				c += d * (str[i] - '0');
				d *= 10;
			}
			result += c;
			a = index + 1;
		}

		index++;
	}
	index++;
	while (1) {
		if (index == str.length()) {
			int c = 0;
			int d = 1;
			for (int i = index - 1; i >= a; i--) {
				c += d * (str[i] - '0');
				d *= 10;
			}
			result -= c;
			break;
		}
		if (str[index] == '+' || str[index] == '-') {
			int c = 0;
			int d = 1;
			for (int i = index - 1; i >= a; i--) {
				c += d * (str[i] - '0');
				d *= 10;
			}
			result -= c;
			a = index + 1;
		}
		index++;
	}

	cout << result << endl;
}