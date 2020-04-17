#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int ii = 1; ii <= t; ii++) {
		int n;
		cin >> n;

		int a, b;
		vector<pair<int, int> > v, result;

		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
		}

		result.push_back({ v[0].first ,v[0].second });
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (v[j].second == result[0].first) {
					result.insert(result.begin(), { v[j].first,v[j].second });
					break;
				}
				if(v[j].first == result[i-1].second){
					result.push_back({ v[j].first,v[j].second });
					break;
				}
			}
		}

		cout << "#" << ii;
		for (int i = 0; i < result.size(); i++) {
			cout << " " << result[i].first << " " << result[i].second;
		}
		cout << endl;
	}


	return 0;
}