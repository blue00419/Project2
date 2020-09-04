#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	deque<int> d;
	int temp;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		if (str == "push") {
			cin >> temp;
			d.push_back(temp);
		}
		if (str == "pop") {
			if (!d.empty()) {
				printf("%d\n", d.front());
				d.pop_front();
			}
			else {
				printf("-1\n");
			}
		}
		if (str == "size") {
			printf("%d\n", d.size());
		}
		if (str == "empty") {
			printf("%d\n", d.empty());
		}
		if (str == "front") {
			if (!d.empty()) {
				printf("%d\n", d.front());
			}
			else {
				printf("-1\n");
			}
		}
		if (str == "back") {
			if (!d.empty()) {
				printf("%d\n", d.back());
			}
			else {
				printf("-1\n");
			}
		}
	}
}