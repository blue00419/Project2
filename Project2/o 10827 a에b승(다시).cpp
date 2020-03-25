#include<iostream>
#include<cstring>

using namespace std;

int ff[300], fb[1000], sf[300], sb[1000];
int z2[300], z0[1000], z1[2][300000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a;
	int b;

	cin >> a >> b;

	int c = 0;
	while (1) {
		if (c == a.length()) {
			break;
		}
		if (a[c] == '.') {
			break;
		}
		c++;
	}
	for (int i = 0; i < c; i++) {
		ff[c - 1 - i] = a[i] - '0';
		sf[c - 1 - i] = a[i] - '0';
	}

	for (int i = c + 1; i < a.length(); i++) {
		fb[a.length() - 1 - i] = a[i] - '0';
		sb[a.length() - 1 - i] = a[i] - '0';
	}
	// i==0인게 .에 붙은애들

	// z2
	int size = a.length();
	int ffsize = c, fbsize = size - (c + 1);
	int sfsize = c, sbsize = size - (c + 1);
	int temp = 0;
	int count;
	int nffsize = 1;

	for (int m = 1; m < b; m++) {
		for (int i = 0; i < sfsize; i++) {
			for (int j = 0; j < ffsize; j++) {
				temp = (ff[j] * sf[i]) + z2[i + j];
				if (temp > 9) {
					z2[i + j + 1] += temp / 10;
				}
				z2[i + j] = temp % 10;
			}
		}

		for (int i = sfsize + ffsize; i >= 0; i--) {
			if (z2[i] != 0) {
				nffsize = i + 1;
				break;
			}
		}


		//z0
		for (int i = 0; i < sbsize; i++) {
			for (int j = 0; j < fbsize; j++) {
				temp = (fb[j] * sb[i]) + z0[i + j];
				if (temp > 9) {
					z0[i + j + 1] += temp / 10;
				}
				z0[i + j] = temp % 10;
			}
		}


		//z1
		//z1[0]
		for (int i = 0; i < sbsize; i++) {
			for (int j = 0; j < ffsize; j++) {
				temp = (ff[j] * sb[i]) + z1[0][i + j];
				if (temp > 9) {
					z1[0][i + j + 1] += temp / 10;
				}
				z1[0][i + j] = temp % 10;
			}
		}

		for (int i = 0; i < sbsize; i++) {
			temp = z1[0][i] + z0[i + fbsize];
			z1[0][i] = 0;
			if (temp > 9) {
				z0[i + fbsize + 1] += temp / 10;
			}
			z0[i + fbsize] = temp % 10;
		}

		if (z0[sbsize + fbsize] != 0) {
			count = 0;
			temp = z0[sbsize + fbsize];
			z0[sbsize + fbsize] = 0;
			while (1) {
				temp = temp + z2[count];
				z2[count] = temp % 10;
				if (temp > 9) {
					temp = temp / 10;
					count++;
				}
				else
					break;
			}
		}

		for (int i = sfsize + ffsize; i >= 0; i--) {
			if (z2[i] != 0) {
				nffsize = i + 1;
				break;
			}
		}

		for (int i = 0; i < nffsize; i++) {
			temp = z2[i] + z1[0][i + sbsize];
			z1[0][i + sbsize] = 0;
			if (temp > 9) {
				z2[i + 1] += temp / 10;
			}
			z2[i] = temp % 10;
		}

		for (int i = sfsize + ffsize; i >= 0; i--) {
			if (z2[i] != 0) {
				nffsize = i + 1;
				break;
			}
		}


		//z1[1]
		for (int i = 0; i < fbsize; i++) {
			for (int j = 0; j < sfsize; j++) {
				temp = (sf[j] * fb[i]) + z1[1][i + j];
				if (temp > 9) {
					z1[1][i + j + 1] += temp / 10;
				}
				z1[1][i + j] = temp % 10;
			}
		}

		for (int i = 0; i < fbsize; i++) {
			temp = z1[1][i] + z0[i + sbsize];
			z1[1][i] = 0;
			if (temp > 9) {
				z0[i + sbsize + 1] += temp / 10;
			}
			z0[i + sbsize] = temp % 10;
		}

		if (z0[sbsize + fbsize] != 0) {
			count = 0;
			temp = z0[sbsize + fbsize];
			z0[sbsize + fbsize] = 0;
			while (1) {
				temp = temp + z2[count];
				z2[count] = temp % 10;
				if (temp > 9) {
					temp = temp / 10;
					count++;
				}
				else
					break;
			}
		}

		for (int i = sfsize + ffsize; i >= 0; i--) {
			if (z2[i] != 0) {
				nffsize = i + 1;
				break;
			}
		}

		for (int i = 0; i < nffsize; i++) {
			temp = z2[i] + z1[1][i + fbsize];
			z1[1][i + fbsize] = 0;
			if (temp > 9) {
				z2[i + 1] += temp / 10;
			}
			z2[i] = temp % 10;
		}

		for (int i = sfsize + ffsize; i >= 0; i--) {
			if (z2[i] != 0) {
				nffsize = i + 1;
				break;
			}
		}

		for (int i = 0; i < nffsize; i++) {
			ff[i] = z2[i];
			z2[i] = 0;
		}

		for (int i = 0; i < sbsize + fbsize; i++) {
			fb[i] = z0[i];
			z0[i] = 0;
		}

		ffsize = nffsize;
		fbsize = fbsize + sbsize;
	}

	for (int i = ffsize-1; i >=0; i--) {
		cout << ff[i];
	}

	cout << '.';
	for (int i = fbsize-1; i >=0; i--) {
		cout << fb[i];
	}
	cout << '\n';

	return 0;
}