#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, k, temp;
vector<int> v;

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}