#include<iostream>
#include<queue>
#include<string>

using namespace std;

#define MAX 100

int main() {

	int n;
	cin >> n;

	queue<int> q, qt[10];
	int max = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push(a);
		if (max < a) {
			max = a;
		}
	}

	int index = 0;
	while (1) {
		if (max == 0) break;
		max /= 10;
		index++;
	}

	for (int i = 0; i < index; i++) {
		int a;
		while (!q.empty()) {
			a = q.front();
			q.pop();
			string str = to_string(a);

			switch(str[str.length() - 1 - i]) {
				case '0':
					qt[0].push(a);
					break;
				case '1':
					qt[1].push(a);
					break;
				case '2':
					qt[2].push(a);
					break;
				case '3':
					qt[3].push(a);
					break;
				case '4':
					qt[4].push(a);
					break;
				case '5':
					qt[5].push(a);
					break;
				case '6':
					qt[6].push(a);
					break;
				case '7':
					qt[7].push(a);
					break;
				case '8':
					qt[8].push(a);
					break;
				case '9':
					qt[9].push(a);
					break;
			}
		}
		for (int j = 0; j < 10; j++) {
			while (!qt[j].empty()) {
				int a = qt[j].front();
				qt[j].pop();
				q.push(a);
			}
		}
	}
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}