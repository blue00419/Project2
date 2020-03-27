#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<vector>

using namespace std;

typedef pair<int, pair<int, int> > pi;

#define MAX 100000+1

int n;
vector<pair<int, int> > mapx, mapy, mapz;
int check[MAX];
priority_queue<pi, vector<pi>, greater<pi> > q;

int find(int x) {
	if (x == check[x]) return x;
	int y = find(check[x]);
	check[x] = y;
	return y;
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);

	check[y] = x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int a, b, c;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> c;
		mapx.push_back({ a,i });
		mapy.push_back({ b,i });
		mapz.push_back({ c,i });
		check[i] = i;
	}

	sort(mapx.begin(), mapx.end());
	sort(mapy.begin(), mapy.end());
	sort(mapz.begin(), mapz.end());

	for (int i = 0; i < n-1; i++) {
		q.push({ abs(mapx[i].first - mapx[i + 1].first),
			{mapx[i].second, mapx[i + 1].second} });
		q.push({ abs(mapy[i].first - mapy[i + 1].first),
			{mapy[i].second, mapy[i + 1].second} });
		q.push({ abs(mapz[i].first - mapz[i + 1].first),
			{mapz[i].second, mapz[i + 1].second} });
	}

	int weight, start, end, sum = 0, soo=1;
	while (!q.empty()) {
		weight = q.top().first;
		start = q.top().second.first;
		end = q.top().second.second;
		q.pop();

		if (find(start) != find(end)) {
			Union(start, end);
			sum += weight;
			soo++;
		}

		if (soo == n)
			break;
	}

	cout << sum << '\n';

	return 0;
}