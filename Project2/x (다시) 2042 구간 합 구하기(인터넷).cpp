#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

#define MAX 1000000+1

int n, m, k;

ll sum(vector<ll> &tree, int i) {
	ll ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(vector<ll>& tree, int i, ll diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	vector<ll> tree(n + 1), map(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> map[i];
		update(tree, i, map[i]);
	}

	m += k;

	while (m--) {
		int num;
		cin >> num;

		if (num == 1) {
			int b;
			ll c;
			cin >> b >> c;

			ll diff = c - map[b];
			map[b] = c;

			update(tree, b, diff);
		}
		else {
			int b, c;
			cin >> b >> c;
			cout << sum(tree, c) - sum(tree, b - 1) << '\n';
		}
	}

	return 0;
}