#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, num;
	string comm;
	stack<int> s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> comm;
		if (comm == "push") {
			cin >> num;
			s.push(num);
		}
		else if (comm == "pop") {
			if (s.empty())
				cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (comm == "size") {
			cout << s.size() << '\n';
		}
		else if (comm == "empty") {
			cout << s.empty() << '\n';
		}
		else if (comm == "top") {
			if (s.empty())
				cout << -1 << '\n';
			else
				cout << s.top() << '\n';
		}
	}

	return 0;
}