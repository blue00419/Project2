#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct pi {
    int end;
    int cost;
};

struct cmp {
    bool operator()(pi a, pi b) {
        return a.cost > b.cost;
    }
};

int map[3][201];
vector<pi> v[201];

void bfs(int n, int start, vector<vector<int>> f, int index) {
    bool visit[201] = { 0, };
    priority_queue<pi, vector<pi>, cmp> q;
    q.push({ start, 0 });
    while (!q.empty()) {
        start = q.top().end;
        int cost = q.top().cost;
        q.pop();
        visit[start] = 1;

        for (int i = 0; i < v[start].size(); i++) {
            int end = v[start][i].end;
            int cost2 = v[start][i].cost;
            if (visit[end] == 0) {
                if (map[index][end] > cost + cost2) {
                    map[index][end] = cost + cost2;
                    q.push({ end, cost + cost2 });
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    for (int i = 1; i <= n; i++) {
        map[0][i] = map[1][i] = map[2][i] = 20000001;
    }
    map[0][s] = 0;
    map[1][a] = 0;
    map[2][b] = 0;

    for (int i = 0; i < fares.size(); i++) {
        int x = fares[i][0];
        int y = fares[i][1];
        int z = fares[i][2];
        v[x].push_back({ y, z });
        v[y].push_back({ x, z });
    }

    bfs(n, s, fares, 0);
    bfs(n, a, fares, 1);
    bfs(n, b, fares, 2);

    int answer = 20000002;

    for (int i = 1; i <= n; i++) {
        answer = min(answer, map[0][i] + map[1][i] + map[2][i]);
    }

    return answer;
}