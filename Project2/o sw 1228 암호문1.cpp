#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int n, a, b;
	int comm;
	char temp;
	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		vector<int> v;
		for (int i = 0; i < n; i++) {
			cin >> a;
			v.push_back(a);
		}
		cin >> comm;

		for (int i = 0; i < comm; i++) {
			cin >> temp;
			cin >> a;
			cin >> b;
			
			for (int j = 0; j < b; j++) {
				vector<int>::iterator iter = v.begin() + a;
				cin >> n;
				v.insert(iter, n);
				a++;
			}
		}

		cout << "#" << ii << " ";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
			if (i == 9)
				break;
		}
		cout << endl;
	}

	return 0;
}