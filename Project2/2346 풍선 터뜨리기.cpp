#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	deque<int> q;
	for (int i = 1; i <= n; i++) {
		q.push_back(i);
	}

	vector<int> v;
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	while (!q.empty()) {
		int a = q.front();
		q.pop_front();
		printf("%d ", a);

		if (!q.empty()) {
			int b = v[a];
			if (b > 0) {
				b--;
				while (1) {
					if (b == 0) break;
					int tmp = q.front();
					q.pop_front();
					q.push_back(tmp);
					b--;
				}
			}
			else if (b < 0) {
				while (1) {
					if (b == 0)break;
					int tmp = q.back();
					q.pop_back();
					q.push_front(tmp);
					b++;
				}
			}
		}
	}

}