#include<iostream>
#include<cmath>

using namespace std;

#define MAX 20+1

int n, map[MAX][MAX];
int steam[10], lteam[10];
bool visit[MAX];
static int mincount = 40000;

void dfs(int start, int cnt) {
    if (cnt == n/2) {
        int sscore = 0, lscore = 0, count = 0;

        for (int i = 1; i <= n; i++) {
            if (visit[i] == 0) {
                lteam[count] = i;
                count++;
            }
        }
        for (int i = 0; i < cnt; i++) {
            for (int j = i + 1; j < cnt; j++) {
                sscore += map[steam[i]][steam[j]];
                lscore += map[lteam[i]][lteam[j]];
            }
        }
        if (mincount > abs(sscore - lscore))
            mincount = abs(sscore - lscore);
    }

    for (int i = start; i <= n; i++) {
        if (visit[i] == 0) {
            visit[i] = 1;
            steam[cnt] = i;
            dfs(i + 1, cnt+1);
            visit[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];

            if (i > j) {
                map[i][j] += map[j][i];
                map[j][i] = map[i][j];
            }
        }
    }

    dfs(1, 0);

    cout << mincount << '\n';;

    return 0;
}
