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
		
		string a;
		for (int i = 0; i < str.size(); i++) {
			a = "";
			for (int j = i; j < str.size(); j++) {
				a += str[j];
			}
			v.push_back(a);
		}

		sort(v.begin(), v.end());

		n--;
		cout << "#" << ii << " " << v[n] << endl;
	}

	return 0;
}