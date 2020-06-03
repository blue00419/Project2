#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main() {
	int t;

	cin >> t;

	int n, k, a;
	char temp;
	for (int ii = 1; ii <= t; ii++) {
		cin >> n >> k;
		a = n / 4;

		string str;
		cin.ignore();
		getline(cin, str);

		
		priority_queue<int> q;
		int index = 0,cur;
		while (1) {
			if (index == a) break;

			int s, e, b, soo, sum;
			s = index;
			e = index + a;

			for (int i = 0; i < 4; i++) {

				b = 0;
				sum = 0;
				for (int j = s; j < e; j++) {
					cur = j;
					if (cur >= n) {
						cur -= n;
					}
					soo = str[cur];
					
					if (soo < 60) {
						soo -= 48;
					}
					else {
						soo -= 55;
					}
					for (int k = 0; k < a - b - 1; k++) {
						soo *= 16;
					}
					sum += soo;
					b++;
				}
				q.push(sum);

				s = e;
				e = e + a;
			}

			index++;
		}

		int pre = 0;
		index = 0;
		while (!q.empty()) {
			if (pre != q.top()) {
				pre = q.top();
				index++;

				if (index == k) {
					break;
				}
			}
			q.pop();
		}
		cout << "#" << ii << " " << pre << endl;
	}


	return 0;
}