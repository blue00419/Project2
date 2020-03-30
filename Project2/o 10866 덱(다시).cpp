#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, num;
	string comm;
	deque<int> q;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> comm;

		if (comm == "push_front") {
			cin >> num;
			q.push_front(num);
		}
		else if(comm == "push_back") {
			cin >> num;
			q.push_back(num);
		}
		else if (comm == "pop_front") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
				q.pop_front();
			}
		}
		else if (comm == "pop_back") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.back() << '\n';
				q.pop_back();
			}
		}
		else if (comm == "size") {
			cout << q.size() << '\n';
		}
		else if (comm == "empty") {
			cout << q.empty() << '\n';
		}
		else if (comm == "front") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else
				cout << q.front() << '\n';
		}
		else if (comm == "back") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else
				cout << q.back() << '\n';
		}
	}

	return 0;
}