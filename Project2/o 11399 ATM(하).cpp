#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int sum = 0, result = 0;

	for (int i = 0; i < n; i++) {
		sum += v[i];
		result += sum;
	}

	cout << result << endl;
	return 0;

}
