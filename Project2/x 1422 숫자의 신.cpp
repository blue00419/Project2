#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define MAX 1000

int k, n;
vector<string> map;

bool compare(const string& a, const string& b) {

	int am[10] = { 0, };
	int acount = a.length();
	for (int i = 0; i < acount; i++) {
		am[i] = a[i] - '0';
	}

	int bm[10] = { 0, };
	int bcount = b.length();
	for (int i = 0; i < bcount; i++) {
		bm[i] = b[i] - '0';
	}

	int count = 0;
	while (1) {
		if (acount < count + 1) {
			return true;
		}
		if (bcount < count + 1) {
			return false;
		}
		if (am[count] > bm[count]) {
			return true;
		}
		if (am[count] < bm[count]) {
			return false;
		}
		count++;
	}
}

/*
bool compare(const string& a, const string& b) {
	if (atoi((a + b).c_str()) < atoi((b + a).c_str())) {
		return false;
	}
	return true;
}
*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;

	string temp;
	int max = 0;
	string maxx;
	for (int i = 0; i < k; i++) {
		cin >> temp;
		map.push_back(temp);
		if (temp.length() > max) {
			max = temp.length();
			maxx = temp;
		}
		if (temp.length() == max) {
			if (atoi(temp.c_str()) > atoi(maxx.c_str())) {
				maxx = temp;
			}
		}
	}
	sort(map.begin(), map.end(), compare);
	
	bool ok = true;
	string result = "";
	for (int i = 0; i < k; i++) {
		result += map[i];

		if (map[i] == maxx && ok) {
			ok = false;
			for (int j = 0; j < n - k; j++) {
				result += map[i];
			}
		}
	}

	cout << result << '\n';
	return 0;
}