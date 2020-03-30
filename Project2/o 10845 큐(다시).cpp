#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, num;
	cin >> n;
	string comm;
	deque<int> q;
	bool front = true;

	for (int i = 0; i < n; i++) {
		cin >> comm;

		if (comm == "push") {
			cin >> num;
			if (front)
				q.push_back(num);
			else
				q.push_front(num);
		}
		else if (comm == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				if (front) {
					cout << q.front() << '\n';
					q.pop_front();
				}
				else {
					cout << q.back() << '\n';
					q.pop_back();
				}
			}
		}
		else if (comm == "size") {
			cout << q.size() << '\n';
		}
		else if (comm == "empty") {
			cout << q.empty() << '\n';
		}
		else if (comm == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				if (front) {
					cout << q.front() << '\n';
				}
				else {
					cout << q.back() << '\n';
				}
			}
		}
		else if (comm == "back") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				if (front) {
					cout << q.back() << '\n';
				}
				else {
					cout << q.front() << '\n';
				}
			}
		}
	}

	return 0;
}