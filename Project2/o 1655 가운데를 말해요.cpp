#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, temp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int> max; // √÷¥Î»¸
	priority_queue<int> min; // √÷º“»¸

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;

		if (i % 2 == 0) { // »¶ºˆ∞≥
			min.push(temp);
		}
		else {
			max.push(temp);
		}

		if (!max.empty() && !min.empty()) {
			if (min.top() > max.top()) {
				int a = max.top();
				int b = min.top();
				max.pop();
				min.pop();
				max.push(b);
				min.push(a);
			}
		}
		cout << min.top() << endl;
	}

	return 0;
}
