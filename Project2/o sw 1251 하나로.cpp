#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int, int > pi;

#define MAX 1000

vector<pi> v;
int n;
int p[MAX];

int find(int x) {
	if (x == p[x]) return x;
	int y = find(p[x]);
	x = y;
	return y;
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);

	p[x] = y;
}

long long calc() {
	priority_queue<pair<long long, pi>, vector<pair<long long, pi> >,
		greater<pair<long long, pi> > > q;

	long long x, y, sum;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			x = abs(v[i].first - v[j].first);
			y = abs(v[i].second - v[j].second);
			sum = (x * x) + (y * y);
			q.push({ sum, {i,j} });
		}
	}

	int count = 0;
	long long result = 0;
	while (!q.empty()) {
		sum = q.top().first;
		x = q.top().second.first;
		y = q.top().second.second;
		q.pop();

		if (find(x) != find(y)) {
			Union(x, y);
			count++;
			result += sum;
		}
		if (count == n - 1)
			break;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int ii = 1; ii <= t; ii++) {
		int a;

		vector<int> vx;

		cin >> n;

		v.clear();

		for (int i = 0; i < n; i++) {
			cin >> a;
			vx.push_back(a);
			p[i] = i;
		}
		for (int i = 0; i < n; i++) {
			cin >> a;
			v.push_back({ vx[i], a });
		}

		long long result = calc();

		double e;
		cin >> e;

		e = e * result;
		printf("#%d %.0f\n", ii, e);
	}

	return 0;
}