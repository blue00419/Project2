#include<iostream>
#include<vector>
#include<stdlib.h>
#include<queue>

#define MAX 1000

using namespace std;

int n, w;

vector<pair<int, int> > v;

int dp[MAX + 1], selectcar[MAX];
pair<int, int > one = { 1,1 }, two;
priority_queue<int, vector<int>, greater<int> > q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> w;
	two = { n, n }; 
	int x, y;
	for (int i = 0; i < w; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}
	// ±×³× dp
	int x2, y2, a, b, c, d; // 1,2   2,1   1,1   2,2
	for (int i = 0; i < w; i++) {
		if (i == w - 1) {
			break;
		}
		else {
			x = v[i].first;
			y = v[i].second;
			x2 = v[i + 1].first;
			y2 = v[i + 1].second;
			a = (abs(x - one.first) + abs(y - one.second))
				+ (abs(x2 - two.first) + abs(y2 - two.second));
			b = (abs(x2 - one.first) + abs(y2 - one.second))
				+ (abs(x - two.first) + abs(y - two.second));
			c = (abs(x - one.first) + abs(y - one.second))
				+ (abs(x2 - x) + abs(y2 - y));
			d = (abs(x2 - x) + abs(y2 - y))
				+ (abs(x - two.first) + abs(y - two.second));

			q.push(a);
			q.push(b);
			q.push(c);
			q.push(d);
			int top = q.top();
			if (i == 0) {
				if (top == a) {
					dp[i] = (abs(x - one.first) + abs(y - one.second));
					one = { x,y };
					selectcar[i] = 1;
				}
				else if (top == b) {
					dp[i] = (abs(x - two.first) + abs(y - two.second));
					two = { x,y };
					selectcar[i] = 2;
				}
				else if (top == c) {
					dp[i] = (abs(x - one.first) + abs(y - one.second));
					one = { x,y };
					selectcar[i] = 1;
				}
				else {
					dp[i] = (abs(x - two.first) + abs(y - two.second));
					two = { x,y };
					selectcar[i] = 2;
				}
			}
			else {
				if (i == w - 2) { // 1,2   2,1   1,1   2,2
					dp[i+1] = dp[i - 1] + top;
					if (top == a) {
						selectcar[i] = 1;
						selectcar[i + 1] = 2;
					}
					else if (top == b) {
						selectcar[i] = 2;
						selectcar[i + 1] = 1;
					}
					else if (top == c) {
						selectcar[i] = 1;
						selectcar[i + 1] = 1;
					}
					else {
						selectcar[i] = 2;
						selectcar[i + 1] = 2;
					}
				}
				else {
					if (top == a) {
						dp[i] = dp[i - 1] + (abs(x - one.first) + abs(y - one.second));
						one = { x,y };
						selectcar[i] = 1;
					}
					else if (top == b) {
						dp[i] = dp[i - 1] + (abs(x - two.first) + abs(y - two.second));
						two = { x,y };
						selectcar[i] = 2;
					}
					else if (top == c) {
						dp[i] = dp[i - 1] + (abs(x - one.first) + abs(y - one.second));
						one = { x,y };
						selectcar[i] = 1;
					}
					else {
						dp[i] = dp[i - 1] + (abs(x - two.first) + abs(y - two.second));
						two = { x,y };
						selectcar[i] = 2;
					}
				}
			}
		}
	}
	
	cout << dp[w-1] << endl;
	for (int i = 0; i < w; i++) {
		cout << selectcar[i] << endl;
	}
	return 0;
}