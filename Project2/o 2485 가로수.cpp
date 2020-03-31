#include<iostream>
#include<vector>

using namespace std;

int gcd(int a, int b) {
	int c;

	if (a < b) {
		c = a;
		a = b;
		b = c;
	}

	while (b > 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v;

	int temp;
	int a=0, b=0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
		if (i == 2) {
			a = v[i - 1] - v[i - 2];
			b = v[i] - v[i - 1];
			a = gcd(a, b);
		}
		if (i > 2) {
			b = v[i] - v[i - 1];
			a = gcd(a, b);
		}
	}
	
	int count = 0;
	int vcount = 0;
	for (int i = v[0]; i < v[n - 1]; i = i + a) {
		if (i == v[vcount]) {
			vcount++;
		}
		else {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}