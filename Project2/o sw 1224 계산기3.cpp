#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int n;

	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		stack<string> s;
		stack<int> s2;
		char temp;
		string str, tmp;
		int sum;
		int a = -1, b;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			str = "";
			str += temp;
			if (temp == ')') {
				while (1) {
					tmp = s.top();
					s.pop();
					if (tmp == "(") {
						s2.push(a);
						a = -1;
						break;
					}
					else {
						if (tmp != "*" && tmp != "+") {
							if (a == -1) {
								a = atoi(tmp.c_str());
							}
							else {
								if (temp == '*') {
									a = a * atoi(tmp.c_str());
									temp = ')';
								}
							}
						}
						else if (tmp == "*") {
							temp = '*';
						}
						else if (tmp == "+") {
							s2.push(a);
							a = -1;
						}
					}
				}
				sum = 0;
				while (!s2.empty()) {
					sum += s2.top();
					s2.pop();
				}
				s.push(to_string(sum));
			}
			else {
				s.push(str);
			}
		}

		sum = 0;
		for (int i = 0; i < s.size(); i++) {
			sum += atoi(s.top().c_str());
			s.pop();
		}

		cout << "#" << ii << " " << sum << endl;
	}

	return 0;
}