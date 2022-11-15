#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 누적합을 사용
int solution(vector<vector<int>> board, vector<vector<int>> skill) {

    int n = board.size() + 1;
    int m = board[0].size() + 1;
    int** map = new int* [n];
    for (int i = 0; i < n; i++) {
        map[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j] = 0;
        }
    }

    for (int i = 0; i < skill.size(); i++) {
        int type = skill[i][0];
        int x1 = skill[i][1];
        int y1 = skill[i][2];
        int x2 = skill[i][3];
        int y2 = skill[i][4];
        int degree = skill[i][5];

        if (type == 1) {
            degree *= (-1);
        }

        map[x1][y1] += degree;
        map[x2 + 1][y2 + 1] += degree;
        degree *= (-1);
        map[x1][y2 + 1] += degree;
        map[x2 + 1][y1] += degree;
    }
    n--;
    m--;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            map[i][j] += map[i][j - 1];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            map[j][i] += map[j - 1][i];
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] += map[i][j];
            if (board[i][j] > 0) {
                answer++;
            }
        }
    }
    return answer;
}