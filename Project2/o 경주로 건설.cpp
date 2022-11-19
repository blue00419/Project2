#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct pi {
    int x;
    int y;
    int cost;
    int dir;
};

struct cmp {
    bool operator()(pi a, pi b) {
        return a.cost > b.cost;
    }
};

int map[25][25];
int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int solution(vector<vector<int>> board) {

    int size = board.size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            map[i][j] = 1000000;
        }
    }

    priority_queue<pi, vector<pi>, cmp> q;
    int answer = 1000000;
    q.push({ 0,0,0, -1 });

    int x, y, cost, d;
    while (!q.empty()) {
        x = q.top().x;
        y = q.top().y;
        cost = q.top().cost;
        d = q.top().dir;
        q.pop();
        if (cost > answer) {
            break;
        }
        if (x == size - 1 && y == size - 1) {
            if (answer > cost) {
                answer = cost;
            }
        }

        for (int i = 0; i < 4; i++) {
            int mx = x + dir[i][0];
            int my = y + dir[i][1];

            if (mx >= 0 && mx < size && my >= 0 && my < size) {
                if (board[mx][my] == 0) {
                    int mcost = cost;
                    if (d == i) {
                        mcost++;
                    }
                    else {
                        mcost += 6;
                    }
                    int a = mcost - map[mx][my];
                    if (a < 5) {
                        map[mx][my] = mcost;
                        q.push({ mx,my,mcost,i });
                    }
                }
            }
        }
    }
    answer -= 5;
    answer *= 100;


    return answer;
}