#include<iostream>
#include<stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int n;
	char temp, tmp;
	for (int ii = 1; ii <= t; ii++) {
		cin >> n;
		stack<char> s;
		int ok = 1;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			if (temp == ')') {
				tmp = s.top();
				if (tmp == '(') {
					s.pop();
				}
				else {
					ok = 0;
				}
			}
			else if (temp == ']') {
				tmp = s.top();
				if (tmp == '[') {
					s.pop();
				}
				else {
					ok = 0;
				}
			}
			else if (temp == '}') {
				tmp = s.top();
				if (tmp == '{') {
					s.pop();
				}
				else {
					ok = 0;
				}
			}
			else if (temp == '>') {
				tmp = s.top();
				if (tmp == '<') {
					s.pop();
				}
				else {
					ok = 0;
				}
			}
			else {
				s.push(temp);
			}
		}
		if (ok) {
			if (!s.empty())
				ok = 0;
		}
		cout << "#" << ii << " " << ok << endl;
		while (s.empty())
			s.pop();
	}

	return 0;
}