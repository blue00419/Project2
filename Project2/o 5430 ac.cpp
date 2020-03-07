#include<iostream>
#include<string>
#include<deque>

using namespace std;

string p;
int t, n, a;
deque<int> dq;
bool front;
char temp;

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> p;
		cin >> n;
		
		if (n != 0) {
			cin >> temp;
			for (int j = 0; j < n; j++) {
				cin >> a;
				dq.push_back(a);
				cin >> temp;
			}
		}
		else {
			cin >> temp >> temp;
		}

		bool zz = false;
		front = true;
		for (int j = 0; j < p.length(); j++) {
			if (p[j] == 'R') {
				front = !front;
			}
			else {
				if (dq.empty()) {
					cout << "error" << endl;
					zz = true;
					break;
				}
				else {
					if (front) {
						dq.pop_front();
					}
					else {
						dq.pop_back();
					}
				}
			}
		}
		if (zz) {
			continue;
		}
		cout << "[";
		if (!dq.empty()) {
			if (front) {
				while (!dq.empty()) {
					n = dq.front();
					cout << n;
					dq.pop_front();

					if (!dq.empty()) {
						cout << ",";
					}
				}
			}
			else {
				while (!dq.empty()) {
					n = dq.back();
					cout << n;
					dq.pop_back();

					if (!dq.empty()) {
						cout << ",";
					}
				}
			}
		}
		cout << "]" << endl;
	}

	return 0;
}