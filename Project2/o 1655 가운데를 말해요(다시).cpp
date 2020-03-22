#include<iostream>
#include<queue>

using namespace std;

int n;
priority_queue<int> bq; // ¹Ø¿¡ ³ð
priority_queue<int, vector<int>, greater<int> > fq; // À§¿¡ ³ð

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int temp;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> temp;

		if (i%2==0) {
			bq.push(temp);
		}
		else {
			fq.push(temp);
		}

		if (i > 0) {
			if (fq.top() < bq.top()) {
				a = fq.top();
				b = bq.top();
				fq.pop();
				bq.pop();
				fq.push(b);
				bq.push(a);
			}
		}
		cout << bq.top() << '\n';
	}

	return 0;
}