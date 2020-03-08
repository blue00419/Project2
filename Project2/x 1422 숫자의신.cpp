#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int k, n, temp, length=-1, strlens;
vector<string> map;
string str, lengthmax;

bool compare(const string& a, const string& b) {

	int na = 1000000000;
	int al[10] = { 0, }, acount = 0;
	int az = atoi(a.c_str());
	for (int i = 0; i < 10; i++) {
		if (az / na != 0) {
			al[acount] = az / na;
			acount++;
		}
		az = az % na;
		na = na / 10;
	}
	
	na = 1000000000;
	int bl[10] = { 0, }, bcount = 0;
	int bz = atoi(b.c_str());
	for (int i = 0; i < 10; i++) {
		if (bz / na != 0) {
			bl[bcount] = bz / na;
			bcount++;
		}
		bz = bz % na;
		na = na / 10;
	}

	int leng = 0;
	while (1) {
		if (al[leng] > bl[leng]) {
			if (bl[leng] == 0) {
				return a < b;
			}
			return a > b;
		}
		if (al[leng] < bl[leng]) {
			if (al[leng] == 0) {
				return a < b;
			}
			return false;
		}
		leng++;
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
		result += map[i];
		if (map[i] == lengthmax) {
			for (int j = 0; j < temp; j++) {
				result += lengthmax;
			}
		}
	}

	cout << result << endl;

	return 0;
}