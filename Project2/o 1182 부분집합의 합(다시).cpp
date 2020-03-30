#include<iostream>
#include<vector>

using namespace std;

#define MAX 20+1

vector<int> v;
bool visit[MAX];
static int counter = 0;

void dfs(int cnt, int n, int s) {
	for (int i = cnt; i < n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			dfs(i + 1, n, s);
			visit[i] = false;
		}
	}

	int sum=0;
	bool ok = false;
	for (int i = 0; i < n; i++) {
		if (visit[i] == true) {
			ok = true;
			sum += v[i];
		}
	}
	if (ok) {
		if (sum == s)
			counter++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n >> s;
	
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	dfs(0, n, s);

	cout << counter << '\n';
	return 0;
}