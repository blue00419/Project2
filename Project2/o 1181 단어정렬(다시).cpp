#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(string& a, string& b) {
	if (a.length() < b.length())
		return true;
	if (a.length() == b.length())
		return a < b;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string> v;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), compare);

	v.erase(unique(v.begin(), v.end()), v.end());
	
	vector<string>::iterator iter = v.begin();

	for (iter; iter != v.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}