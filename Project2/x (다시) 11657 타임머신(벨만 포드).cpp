#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

typedef pair<int, int> pi;

#define MAX 500+1

int n, m;
int map[MAX];
vector<pi> v[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
	}

	memset(map, 0x3f3f3f3f, sizeof(map));

	map[1] = 0;
	
	// 벨만 포드 알고리즘은 시작노드를 제외하고 
	// n-1개만큼의 정점에서 연결된 엣지들을 전부 검사해서 값을 업데이트해준다
	// 마지막으로 한번더 검사를 진행하는데 이때 업데이트가 발생하면
	// 음수 사이클이 존재하는것이 된다.
	bool cycle = false;
	for (int i = 1; i <= n; i++) { // n-1번 사이틀 + 음수 사이클 체크 1번
		for (int j = 1; j <= n; j++) { // j번 노드에서 출발하는
			for (int k = 0; k < v[j].size(); k++) { // 엣지들
				if (map[j] != 0x3f3f3f3f) {
					if (map[v[j][k].first] > map[j] + v[j][k].second) {
						map[v[j][k].first] = map[j] + v[j][k].second;
						if (i == n) cycle = true;
					}
				}
			}
		}
	}

	if (cycle) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (map[i] == 0x3f3f3f3f)
				cout << -1 << '\n';
			else
				cout << map[i] << '\n';
		}
	}

	return 0;
}