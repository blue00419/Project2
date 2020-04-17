#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int ii = 1; ii <= t; ii++) {
		int n;
		cin >> n;

		string str;
		cin >> str;

		vector<string> v;
		for (int i = 1; i <= str.length(); i++) {
			for (int j = 0; j < str.length() - i + 1; j++) {

				string a = "";
				for (int k = 0; k < i; k++) {
					a += str[j + k];
				}
				v.push_back(a);
			}
		}

		sort(v.begin(), v.end());

		v.erase(unique(v.begin(), v.end()), v.end());

		n--;
		if (n >= v.size()) {
			cout << "#" << ii << " none" << endl;
		}
		else {
			cout << "#" << ii << " " << v[n] << endl;
		}
	}
	return 0;
}