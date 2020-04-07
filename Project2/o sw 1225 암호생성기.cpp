#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int n, a, temp;

	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		queue<int> q;
		for (int i = 0; i < 8; i++) {
			cin >> a;
			q.push(a);
		}

		int count = 1;
		while (1) {
			temp = q.front();
			q.pop();
			temp -= count;
			if (temp < 0) {
				temp = 0;
			}
			q.push(temp);
			if (temp == 0) {
				break;
			}
			count++;
			if (count == 6)
				count = 1;
		}

		cout << "#" << ii << " ";
		int size = q.size();
		for (int i = 0; i < size; i++) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}

	return 0;
}