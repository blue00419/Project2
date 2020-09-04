#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v1;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		v1.push_back(a);
	}

	vector<int> v;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}

	int result = 0;
	for (int i = 0; i < m; i++) {
		int a = v1[i];

		int front = 0;
		int back = 0;
		bool f = true;
		for (int j = 0; j < v.size(); j++) {
			if (f && v[j] != a) {
				front++;
			}
			else if (v[j] == a) {
				f = false;
			}
			else if (!f) {
				back++;
			}
		}
		if (front <= back) {
			for (int j = 0; j < front; j++) {
				v.push_back(v[j]);
			}

			v.erase(v.begin(), v.begin() + front + 1);
			result += front;
		}
		else {
			for (int j = n - 1; j > n - 1 - back; j--) {
				v.insert(v.begin(), v[v.size() - 1]);
				v.erase(v.end() - 1);
			}
			v.erase(v.end() - 1);
			result += (back + 1);
		}
	}
	cout << result << endl;
}