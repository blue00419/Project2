#include<iostream>
#include<queue>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	int count = 0;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;

		int index = 0;
		int size = q.size();
		while (1) {
			int b = q.front();
			q.pop();

			if (b == a) {
				break;
			}
			else {
				q.push(b);
				index++;
			}
		}
		if (index > size - index) {
			index = size - index;
		}
		count += index;
	}

	printf("%d\n", count);

	return 0;
}