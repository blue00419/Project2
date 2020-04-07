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

			if (temp == 'I') {
				cin >> a;
				cin >> b;

				for (int j = 0; j < b; j++) {
					vector<int>::iterator iter = v.begin() + a;
					cin >> n;
					v.insert(iter, n);
					a++;
				}
			}
			else if (temp == 'D') {
				cin >> a;
				cin >> b;

				vector<int>::iterator iter = v.begin() + a;
				v.erase(iter, iter + b);
			}
			else if (temp == 'A') {
				cin >> a;

				for (int i = 0; i < a; i++) {
					cin >> b;
					v.push_back(b);
				}
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