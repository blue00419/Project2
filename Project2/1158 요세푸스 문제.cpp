#include<iostream>
#include<queue>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	printf("<");
	int index = 1;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		if (index == k) {
			printf("%d", a);
			if (!q.empty()) {
				printf(", ");
			}
			index = 1;
		}
		else {
			q.push(a);
			index++;
		}
	}
	printf(">");
	return 0;
}