#include<iostream>
#include<stack>

using namespace std;

int main() {
	int k;
	cin >> k;

	long long result = 0;
	stack<int> s;

	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		if (a == 0) {
			s.pop();
		}
		else {
			s.push(a);
		}
	}

	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	cout << result << endl;
}