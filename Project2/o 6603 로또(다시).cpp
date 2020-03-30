#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define MAX 49+1

vector<int> v;
bool visit[MAX];

void dfs(int start, int cnt, int k) {

	if (cnt == 6) {
		for (int i = 0; i < k; i++) {
			if (visit[i] == true)
				cout << v[i] << " ";
		}
		cout << '\n';
	}


	for (int i = start; i < k; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			dfs(i + 1, cnt + 1, k);
			visit[i] = false;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k, a;
	while (1) {
		cin >> k;
		if (k == 0)
			break;

		v.clear();
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < k; i++) {
			cin >> a;
			v.push_back(a);
		}

		dfs(0, 0, k);
		cout << endl;
	}

	return 0;
}