#include<iostream>
#include<queue>
#include<vector>
#include<tuple>

using namespace std;

typedef pair<int, int> pi;
typedef tuple<int, int, int, int> tp;

#define MAX 800+1

int n, e;
int map[MAX];
vector<pi> v[MAX];
priority_queue<tp, vector<tp>, greater<tp> > q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> e;
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	cin >> a >> b;

	q.push({ map[1], 1, 0, 0 }); // 가중치, 위치, 두개의 서로 다른 정점 번호

	int size, weight, start, first, second;
	while (!q.empty()) {
		weight = get<0>(q.top());
		start = get<1>(q.top());
		first = get<2>(q.top());
		second = get<3>(q.top());
		q.pop();

		size = v[start].size();

		for (int i = 0; i < size; i++) {
			if(map[v[start][i].first] == 0 || 
				map[start] + v[start][i].second < map[v[start][i].first])
		}
	}



	return 0;
}