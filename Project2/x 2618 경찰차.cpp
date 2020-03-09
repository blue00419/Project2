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
	int x2, y2, x3, y3, a, b, c, d, e, f, g, h, aa, bb; 
	for (int i = 0; i < w; i++) {
		x = v[i].first;
		y = v[i].second;
		aa = (abs(x - one.first) + abs(y - one.second)), bb = (abs(x - two.first) + abs(y - two.second));

		if (w == 1) {
			if (aa >= bb) {
				dp[i] = bb;
				selectcar[i] = 2;
			}
			else {
				dp[i] = aa;
				selectcar[i] = 1;
			}
			break;
		}
		else if (w == 2) {
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
			// 1,2   2,1   1,1   2,2
			if (top == a) {
				dp[i] = (abs(x - one.first) + abs(y - one.second));
				dp[i + 1] = dp[i] + (abs(x2 - two.first) + abs(y2 - two.second));
				selectcar[i] = 1;
				selectcar[i + 1] = 2;
			}
			else if (top == b) {
				dp[i] = (abs(x - two.first) + abs(y - two.second));
				dp[i + 1] = dp[i] + (abs(x2 - one.first) + abs(y2 - one.second));
				selectcar[i] = 2;
				selectcar[i + 1] = 1;
			}
			else if (top == c) {
				dp[i] = (abs(x - one.first) + abs(y - one.second));
				dp[i + 1] = dp[i] + (abs(x2 - x) + abs(y2 - y));
				selectcar[i] = 1;
				selectcar[i + 1] = 1;
			}
			else {
				dp[i] = (abs(x - two.first) + abs(y - two.second));
				dp[i + 1] = dp[i] + (abs(x2 - x) + abs(y2 - y));
				selectcar[i] = 2;
				selectcar[i + 1] = 2;
			}
			break;
		}
		else {
			x2 = v[i + 1].first;
			y2 = v[i + 1].second;
			x3 = v[i + 2].first;
			y3 = v[i + 2].second;


			// 111 112 121 211 122 212 221 222
			a = (abs(x - one.first) + abs(y - one.second))
				+ (abs(x2 - x) + abs(y2 - y))
				+ (abs(x2 - x3) + abs(y2 - y3));

			b = (abs(x - one.first) + abs(y - one.second))
				+ (abs(x2 - x) + abs(y2 - y))
				+ (abs(two.first - x3) + abs(two.second - y3));

			c = (abs(x - one.first) + abs(y - one.second))
				+ (abs(x2 - two.first) + abs(y2 - two.second))
				+ (abs(x3 - x) + abs(y3 - y));

			d = (abs(x - two.first) + abs(y - two.second))
				+ (abs(x2 - one.first) + abs(y2 - one.second))
				+ (abs(x2 - x3) + abs(y2 - y3));

			e = (abs(x - one.first) + abs(y - one.second))
				+ (abs(x2 - two.first) + abs(y2 - two.second))
				+ (abs(x3 - x2) + abs(y3 - y2));

			f = (abs(x - two.first) + abs(y - two.second))
				+ (abs(x2 - one.first) + abs(y2 - one.second))
				+ (abs(x3 - x) + abs(y3 - y));

			g = (abs(x - two.first) + abs(y - two.second))
				+ (abs(x2 - x) + abs(y2 - y))
				+ (abs(one.first - x3) + abs(one.second - y3));

			h = (abs(x - two.first) + abs(y - two.second))
				+ (abs(x2 - x) + abs(y2 - y))
				+ (abs(x2 - x3) + abs(y2 - y3));


			q.push(a);
			q.push(b);
			q.push(c);
			q.push(d);
			q.push(e);
			q.push(f);
			q.push(g);
			q.push(h);
			int top = q.top();
			if (i == w - 3) {// 111 112 121 211 122 212 221 222
				if (top == a) {
					if (i == 0) {
						dp[i] = (abs(x - one.first) + abs(y - one.second));
					}
					else {
						dp[i] = dp[i-1] + (abs(x - one.first) + abs(y - one.second));
					}
					dp[i + 1] = dp[i] + (abs(x2 - x) + abs(y2 - y));
					dp[i + 2] = dp[i + 1] + (abs(x2 - x3) + abs(y2 - y3));
					selectcar[i] = 1;
					selectcar[i+1] = 1;
					selectcar[i+2] = 1;
				}
				if (top == b) {
					if (i == 0) {
						dp[i] = (abs(x - one.first) + abs(y - one.second));
					}
					else {
						dp[i] = dp[i-1] + (abs(x - one.first) + abs(y - one.second));
					}
					dp[i + 1] = dp[i] + (abs(x2 - x) + abs(y2 - y));
					dp[i + 2] = dp[i + 1] + (abs(two.first - x3) + abs(two.second - y3));
					selectcar[i] = 1;
					selectcar[i + 1] = 1;
					selectcar[i + 2] = 2;
				}
				if (top == c) {
					if (i == 0) {
						dp[i] = (abs(x - one.first) + abs(y - one.second));
					}
					else {
						dp[i] = dp[i - 1] + (abs(x - one.first) + abs(y - one.second));
					}
					dp[i + 1] = dp[i] + (abs(x2 - two.first) + abs(y2 - two.second));
					dp[i + 2] = dp[i + 1] + (abs(x3 - x) + abs(y3 - y));
					selectcar[i] = 1;
					selectcar[i + 1] = 2;
					selectcar[i + 2] = 1;
				}
				if (top == d) {
					if (i == 0) {
						dp[i] = (abs(x - two.first) + abs(y - two.second));
					}
					else {
						dp[i] = dp[i - 1] + (abs(x - two.first) + abs(y - two.second));
					}
					dp[i + 1] = dp[i] + (abs(x2 - one.first) + abs(y2 - one.second));
					dp[i + 2] = dp[i + 1] + (abs(x2 - x3) + abs(y2 - y3));
					selectcar[i] = 2;
					selectcar[i + 1] = 1;
					selectcar[i + 2] = 1;
				}
				if (top == e) {
					if (i == 0) {
						dp[i] = (abs(x - one.first) + abs(y - one.second));
					}
					else {
						dp[i] = dp[i - 1] + (abs(x - one.first) + abs(y - one.second));
					}
					dp[i + 1] = dp[i] + (abs(x2 - two.first) + abs(y2 - two.second));
					dp[i + 2] = dp[i + 1] + (abs(x3 - x2) + abs(y3 - y2));
					selectcar[i] = 1;
					selectcar[i + 1] = 2;
					selectcar[i + 2] = 2;
				}
				if (top == f) {
					if (i == 0) {
						dp[i] = (abs(x - two.first) + abs(y - two.second));
					}
					else {
						dp[i] = dp[i - 1] + (abs(x - two.first) + abs(y - two.second));
					}
					dp[i + 1] = dp[i] + (abs(x2 - one.first) + abs(y2 - one.second));
					dp[i + 2] = dp[i + 1] + (abs(x3 - x) + abs(y3 - y));
					selectcar[i] = 2;
					selectcar[i + 1] = 1;
					selectcar[i + 2] = 2;
				}
				if (top == g) {
					if (i == 0) {
						dp[i] = (abs(x - two.first) + abs(y - two.second));
					}
					else {
						dp[i] = dp[i - 1] + (abs(x - two.first) + abs(y - two.second));
					}
					dp[i + 1] = dp[i] + (abs(x2 - x) + abs(y2 - y));
					dp[i + 2] = dp[i + 1] + (abs(one.first - x3) + abs(one.second - y3));
					selectcar[i] = 2;
					selectcar[i + 1] = 2;
					selectcar[i + 2] = 1;
				}
				if (top == h) {
					if (i == 0) {
						dp[i] = (abs(x - two.first) + abs(y - two.second));
					}
					else {
						dp[i] = dp[i - 1] + (abs(x - two.first) + abs(y - two.second));
					}
					dp[i + 1] = dp[i] + (abs(x2 - x) + abs(y2 - y));
					dp[i + 2] = dp[i + 1] + (abs(x2 - x3) + abs(y2 - y3));
					selectcar[i] = 2;
					selectcar[i + 1] = 2;
					selectcar[i + 2] = 2;
				}
				break;
			}
			else {// 111 112 121 211 122 212 221 222
				if (top == a || top == b || top == c || top == e) {
					dp[i] = aa;
					one = { x,y };
					selectcar[i] = 1;
				}
				else {
					dp[i] = bb;
					two = { x,y };
					selectcar[i] = 2;
				}
			}
		}

		while (!q.empty()) {
			q.pop();
		}
	}
	
	cout << dp[w-1] << endl;
	for (int i = 0; i < w; i++) {
		cout << selectcar[i] << endl;
	}
	return 0;
}