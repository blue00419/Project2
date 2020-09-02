#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int up[4001];
int down[4001];

int main() {
	int n;
	cin >> n;

	vector<int> v;

	int temp;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		sum += temp;
		v.push_back(temp);

		if (temp >= 0) {
			up[temp]++;
		}
		else {
			down[abs(temp)]++;
		}
	}

	sort(v.begin(), v.end());

	int a = 1;
	vector<int> v2;

	for (int i = 0; i <= 4000; i++) {
		if (a == up[i]) {
			v2.push_back(i);
		}
		else if (a < up[i]) {
			v2.clear();
			a = up[i];
			v2.push_back(i);
		}
	}
	for (int i = 0; i <= 4000; i++) {
		if (a == down[i]) {
			v2.push_back(i*(-1));
		}
		else if (a < down[i]) {
			v2.clear();
			a = down[i];
			v2.push_back(i*(-1));
		}
	}

	sort(v2.begin(), v2.end());

	cout << round(sum / n) << endl;
	cout << v[(n - 1) / 2] << endl;
	if (v2.size() == 1) {
		cout << v2[0] << endl;
	}
	else {
		cout << v2[1] << endl;
	}
	cout << v[n - 1] - v[0] << endl;

	return 0;
}