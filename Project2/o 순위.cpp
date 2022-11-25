#include <string>
#include <vector>

using namespace std;

bool map[101][101] = { 0, };

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int size = results.size();
    for (int i = 0; i < size; i++) {
        int a = results[i][0];
        int b = results[i][1];
        map[a][b] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (map[j][i] && map[i][k]) {
                    map[j][k] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (map[i][j] || map[j][i]) {
                count++;
            }
        }
        if (count == n - 1) {
            answer++;
        }
    }

    return answer;
}