#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int t, m;
string n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int k = 0; k < t; k++) {
		cin >> m;

		if (m == 1) {
			unsigned long long a[64] = { 0, };
			int b[8], count = 0, temp;
			char x;
			for (int i = 0; i < 8; i++) {
				cin >> b[i];
				if (i != 7) {
					cin >> x;
				}
			}
			for (int i = 7; i >= 0; i--) {
				temp = b[i];
				for (int j = 0; j < 8; j++) {
					if (temp % 2 == 0) {
						a[count] = 0;
					}
					else {
						a[count] = 1;
					}
					temp = temp / 2;
					count++;
				}
			}
			unsigned long long result = 0;
			for (int i = 0; i < 64; i++) {
				result += a[i] * (unsigned long long)pow(2, i);
			}
			cout << result << '\n';
		}
		else {
			unsigned long long a[64] = { 0, }, temp;
			cin >> temp;
			for (int i = 63; i >=0; i--) {
				if (temp % 2 == 0) {
					a[i] = 0;
				}
				else {
					a[i] = 1;
				}
				temp = temp / 2;
			}
			unsigned long long b[8] = { 0, }, bcount=0, powcount=7;
			temp = 0;
			for (int i = 0; i < 64; i++) {
				b[bcount] += a[i] * pow(2, powcount);
				powcount--;
				if ((i + 1) % 8 == 0) {
					bcount++;
					powcount = 7;
				}
			}
			for (int i = 0; i < 8; i++) {
				cout << b[i];
				if (i != 7) {
					cout << ".";
				}
			}
			cout << '\n';
		}
	}


	return 0;
}