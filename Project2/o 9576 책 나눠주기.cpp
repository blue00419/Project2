#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 1001

int t, n, m, temp1, temp2, counter;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (!(a.second == b.second))
		return a.second < b.second;
	if(a.second == b.second)
		return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> n >> m;
		vector<pair<int, int>> v;
		bool check[MAX] = { 0, };

		for (int i = 0; i < m; i++) {
			cin >> temp1 >> temp2;
			v.push_back({ temp1,temp2 });
		}
		sort(v.begin(), v.end(), cmp);

		counter = 0;
		for (int i = 0; i < m; i++) {
			for (int j = v[i].first; j <= v[i].second; j++) {
				if (check[j] == 0) {
					check[j] = 1;
					counter++;
					break;
				}
			}
		}
		cout << counter << '\n';
	}

	return 0;
}