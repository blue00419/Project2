#include <string>
#include <vector>

using namespace std;

int map[100001] = { 0, };

int solution(int n, vector<int> money) {
    int answer = 0;

    map[0] = 1;
    int size = money.size();
    for (int i = 0; i < size; i++) {
        for (int j = 1; j <= n; j++) {
            if (j < money[i]) continue;
            int a = j - money[i];
            map[j] = map[j] + map[a];
        }
    }
    answer = map[n];

    return answer;
}