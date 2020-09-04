#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {

	while (1) {
		string str;
		getline(cin, str);
		if (str.length() == 1 && str[0] == '.') break;

		stack<char> s;

		bool ok = true;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				s.push(str[i]);
			}
			if (str[i] == ')') {
				if (!s.empty()) {
					if (s.top() == '(') {
						s.pop();
					}
					else {
						ok = false;
					}
				}
				else {
					ok = false;
				}
			}
			else if (str[i] == ']') {
				if (!s.empty()) {
					if (s.top() == '[') {
						s.pop();
					}
					else {
						ok = false;
					}
				}
				else {
					ok = false;
				}
			}
		}
		if (!s.empty()) {
			ok = false;
		}
		if (ok) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
}