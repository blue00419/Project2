#include<iostream>
#include<string>

using namespace std;

int au[1000] = { 0, };
int ad[1000] = { 0, };
int red[1000] = { 0, };
int reu[1000] = { 0, };
int z2[1000] = { 0, }; // au * reu
int z0[1000] = { 0, }; // ad * red
int z1[1000] = { 0, }; // ¼¯¾î ¼¯¾î
int b;
char temp;
string str;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> str >> b;

	int count = str.length()-1;
	int aucount = 0;
	int adcount = 0;
	int reucount = 0;
	int redcount = 0;
	bool ok = false;
	while (1) {
		if (count < 0) {
			break;
		}
		if (ok) {
			au[aucount] = str[count] - '0';
			reu[reucount] = str[count] - '0';
			aucount++;
			reucount++;
			count--;
		}
		else if (str[count] != '.') {
			ad[adcount] = str[count] - '0';
			red[redcount] = str[count] - '0';
			adcount++;
			redcount++;
			count--;
			continue;
		}
		else if(str[count] == '.'){
			ok = true;
			count--;
		}
	}
	if (aucount == 0) {
		for (int i = 0; i < adcount; i++) {
			au[i] = ad[i];
			ad[i] = 0;
			reu[i] = red[i];
			red[i] = 0;
		}
		aucount = adcount;
		adcount = 1;
		reucount = redcount;
		redcount = 1;
	}

	int tmp;
	int trash;

	for (int m = 0; m < b - 1; m++) {

		// z0
		// 3.141592 3
		int aend = adcount;
		int reend = redcount;
		int z0count = adcount + redcount;
		for (int i = 0; i < reend; i++) {
			trash = 0;
			for (int j = 0; j < aend; j++) {
				tmp = ad[j] * red[i] + trash + z0[i + j];
				trash = 0;
				if (tmp > 9) {
					trash = tmp / 10;
				}
				z0[i + j] = tmp % 10;
			}
			if (trash)
				z0[i + aend] = trash;
		}

		// 3.141592 3
		// z2
		int afront = aucount;
		int refront = reucount;
		int z2count = reucount;
		for (int i = 0; i < refront; i++) {
			trash = 0;
			for (int j = 0; j < afront; j++) {
				tmp = au[j] * reu[i] + trash + z2[i + j];
				trash = 0;
				if (tmp > 9) {
					trash = tmp / 10;
				}
				z2[i + j] = tmp % 10;
			}
			if (trash)
				z2[i + afront] = trash;
		}

		if (z2[z2count])
			z2count++;

		// z1
		// 3.141592 3
		int z1count = redcount;

		for (int i = 0; i < afront; i++) {
			trash = 0;
			for (int j = 0; j < reend; j++) {
				tmp = au[i] * red[j] + z1[j + i] + trash;
				trash = 0;
				if (tmp > 9) {
					trash = tmp / 10;
				}
				z1[j + i] = tmp % 10;
			}
			if (trash)
				z1[i + reend] += trash;
		}

		for (int i = 0; i < refront; i++) {
			trash = 0;
			for (int j = 0; j < aend; j++) {
				tmp = reu[i] * ad[j] + trash + z1[j + i + (reend - aend)];
				trash = 0;
				if (tmp > 9) {
					trash = tmp / 10;
				}
				z1[i + j + (reend-aend)] = tmp % 10;
			}
			if (trash) {
				z1[i + aend + (reend - aend)] += trash;
			}
		}


		// 3.141592 3
		if (z1[z1count]) {
			trash = 0;
			count = 0;
			tmp = z1[z1count] + z2[count];
			while (1) {
				z2[count] = tmp % 10;
				if (tmp > 9) {
					trash = tmp / 10;
					count++;
					tmp = z2[count] + trash;
				}
				else
					break;
			}
		}

		if (z2[z2count]) {
			z2count++;
		}

		for (int i = 0; i < redcount; i++) {
			red[i] = 0;
		}
		for (int i = 0; i < reucount; i++) {
			reu[i] = 0;
		}

		trash = 0;
		for (int i = 0; i < z0count; i++) {
			if (i < z0count - redcount)
				red[i] = z0[i];
			else {
				tmp = z0[i] + z1[i - (z0count - redcount)] + red[i] + trash;
				trash = 0;
				if (tmp > 9) {
					trash = tmp / 10;
				}
				red[i] = tmp % 10;
			}
		}

		if (trash) {
			count = 0;
			tmp = trash + z2[count];
			trash = 0;
			while (1) {
				z2[count] = tmp % 10;
				if (tmp > 9) {
					trash = tmp / 10;
					count++;
					tmp = z2[count] + trash;
				}
				else
					break;
			}
		}

		if (z2[z2count])
			z2count++;

		for (int i = 0; i < z2count; i++) {
			reu[i] = z2[i];
		}
		// 3.141592 3

		for (int i = 0; i < z0count + 2; i++) {
			z0[i] = 0;
		}
		for (int i = 0; i < z1count + 2; i++) {
			z1[i] = 0;
		}
		for (int i = 0; i < z2count + 2; i++) {
			z2[i] = 0;
		}
		redcount = z0count;
		reucount = z2count;
	}

	for (int i = reucount - 1; i >= 0; i--) {
		cout << reu[i];
	}
	cout << ".";
	for (int i = redcount - 1; i >= 0; i--) {
		cout << red[i];
	}

	return 0;
}