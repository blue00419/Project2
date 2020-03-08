#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int k, n, temp, length=-1, strlens;
vector<string> map;
string str, lengthmax;
int al[10], bl[10], acount, bcount, alength, blength;
int leng, na, az, bz;

bool compare(const string& a, const string& b) {
	if (a == b) {
		return false;
	}
	else {
		acount = 0;
		bcount = 0;
		alength = a.length();
		blength = b.length();
		for (int i = 0; i < 10; i++) {
			if (i < alength) {
				al[i] = 0;
			}
			else {
				al[i] = -1;
			}
			if (i < blength) {
				bl[i] = 0;
			}
			else {
				bl[i] = -1;
			}
		}

		na = 1000000000;
		az = atoi(a.c_str());
		for (int i = 0; i < 10; i++) {
			if (az / na != 0) {
				al[acount] = az / na;
				acount++;
			}
			az = az % na;
			na = na / 10;
		}

		na = 1000000000;
		bz = atoi(b.c_str());
		for (int i = 0; i < 10; i++) {
			if (bz / na != 0) {
				bl[bcount] = bz / na;
				bcount++;
			}
			bz = bz % na;
			na = na / 10;
		}

		leng = 0;
		while (1) {
			if (bl[leng] == -1) {
				return true;
			}
			if (al[leng] == -1) {
				return false;
			}
			if (al[leng] > bl[leng]) {
				return false;
			}
			if (al[leng] < bl[leng]) {
				return true;
			}
			leng++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> str;
		map.push_back(str);
		strlens = str.length();

		if (length == strlens) {
			if (map[i] > lengthmax) {
				lengthmax = str;
			}
		}

		if (length < strlens) {
			lengthmax = str;
			length = strlens;
		}
	}
	sort(map.begin(), map.end(), compare);

	temp = n - k;
	string result = "";
	for (int i = 0; i < k; i++) {
		result += map[k - 1 - i];
		if (map[k - 1 - i] == lengthmax) {
			for (int j = 0; j < temp; j++) {
				result += lengthmax;
			}
		}
	}

	cout << result << endl;

	return 0;
}

/*
3 3
2
3
7

2 3
75
75123


3 5
75
75123
750

4 5
75
75123
751
750

*/