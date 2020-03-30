#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a;
	int b[101] = { 0, };

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		b[temp]++;
	}

	sort(a.begin(), a.end());

	int count = 0, sum=0;
	for (int i = 100; i >= 0; i--) {
		if (b[i] != 0) {
			for (int j = 0; j < b[i]; j++) {
				sum += i * a[count];
				count++;
			}
		}
	}
	cout << sum << '\n';

	return 0;
}