#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n, a;
	cin >> t;

	string comm;
	char temp;
	bool front, ok;
	for (int i = 0; i < t; i++) {
		deque<int> q;
		front = true;
		ok = false;

		cin >> comm;
		cin >> n;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			cin >> a;
			q.push_back(a);
			cin >> temp;
		}
		if (n == 0)
			cin >> temp;

		for (int j = 0; j < comm.length(); j++) {
			if (comm[j] == 'R') {
				front = !front;
			}
			else if (comm[j] == 'D') {
				if (q.empty()) {
					ok = true;
					break;
				}
				else {
					if (front)
						q.pop_front();
					else
						q.pop_back();
				}
			}
		}
		
		if (ok)
			cout << "error" << '\n';
		else {
			cout << "[";
			int size = q.size();
			for (int j = 0; j < size; j++) {
				if (front) {
					if (j != size - 1) {
						cout << q.front() << ",";
					}
					else
						cout << q.front();
					q.pop_front();
				}
				else {
					if (j != size - 1) {
						cout << q.back() << ",";
					}
					else
						cout << q.back();
					q.pop_back();
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}