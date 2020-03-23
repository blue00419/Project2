#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

typedef pair<int, int> pi;
int n;
const int INF = (1 << 30);

int sqr(int x) { return x * x; }
double dist(pi a, pi b) { 
	return (double)(sqr(a.first - b.first) + sqr(a.second - b.second)); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<pi> v(n);
	set<pi> s;

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());
	s.insert(pi(v[0].second, v[0].first));
	s.insert(pi(v[1].second, v[1].first));

	double mmin = dist(v[0], v[1]);
	int last = 0;
	for (int i = 2; i < n; i++) {
		while (last < i) {
			int d = v[i].first - v[last].first;
			if (sqr(d) <= mmin) break;
			else s.erase(pi(v[last].second, v[last].first)), last++;
		}
		double limit = sqrt(mmin);
		auto end = s.upper_bound(pi(v[i].second + limit, INF));
		for (auto it = s.lower_bound(pi(v[i].second - limit, -INF)); it != end; ++it)
			mmin = min(mmin, dist(pi(it->second, it->first), v[i]));
		s.insert(pi(v[i].second, v[i].first));
	}
	printf("%lf\n", mmin);

	return 0;
}