#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string str, str3;
static int maximum;
static bool ok;


void dfs2(int cnt, int n) {
	if (cnt == n) {
		int a = atoi(str.c_str());
		if (maximum < a)
			maximum = a;
		return;
	}
	int size = str.size();
	if (size == 1) {
		int a = atoi(str.c_str());
		if (maximum < a)
			maximum = a;
		return;
	}
	else {
		char temp = str[size - 1];
		str[size - 1] = str[size - 2];
		str[size - 2] = temp;
		dfs2(cnt + 1, n);
	}
}

void dfs(int cnt, int n) {
	if (str == str3) {
		ok = true;
		bool yes = false;
		for (int i = 0; i < str3.size() - 1; i++) {
			if (str3[i] == str3[i + 1])
				yes = true;
		}
		if (yes) {
			int a = atoi(str.c_str());
			if (maximum < a)
				maximum = a;
			return;
		}
		else {
			dfs2(cnt, n);
		}
		return;
	}
	if (cnt == n) {
		int a = atoi(str.c_str());
		if (maximum < a)
			maximum = a;
		return;
	}

	char temp;
	string str2 = str;
	for (int i = 0; i < str.size() - 1; i++) {
		for (int j = i + 1; j < str.size(); j++) {
			temp = str[i];
			str[i] = str[j];
			str[j] = temp;
			if (str != str2) {
				dfs(cnt + 1, n);
			}
			if (ok) {
				return;
			}
			temp = str[i];
			str[i] = str[j];
			str[j] = temp;
		}
	}
}

bool compare(const char& a, const char& b) {
	int aa = a - '0';
	int bb = b - '0';
	if (aa > bb)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int ii = 1; ii <= t; ii++) {
		int n;
		cin >> str >> n;
		maximum = 0;
		ok = false;
		str3 = str;
		sort(str3.begin(), str3.end(), compare);

		dfs(0, n);

		cout << "#" << ii << " " << maximum << endl;
	}

	return 0;
}