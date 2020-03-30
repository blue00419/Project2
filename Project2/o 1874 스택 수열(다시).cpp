#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a;
	cin >> n;
	
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	vector<char> result;
	stack<int> s;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		s.push(i);
		result.push_back('+');
		while (1) {
			if (!s.empty()) {
				if (v[count] == s.top()) {
					count++;
					s.pop();
					result.push_back('-');
				}
				else
					break;
			}
			else
				break;
		}
	}

	if (count == n) {
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << '\n';
	}
	else
		cout << "NO" << '\n';

	return 0;
}