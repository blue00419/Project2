#include <string>
#include <vector>
#include <iostream>

using namespace std;

int map[1000000][2] = { 0, };

int solution(vector<int> a) {
    int size = a.size();
    map[0][0] = a[0];
    for (int i = 1; i < size; i++) {
        if (map[i - 1][0] > a[i]) {
            map[i][0] = a[i];
        }
        else {
            map[i][0] = map[i - 1][0];
        }
    }

    map[size - 1][1] = a[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        if (map[i + 1][1] > a[i]) {
            map[i][1] = a[i];
        }
        else {
            map[i][1] = map[i + 1][1];
        }
    }

    int answer = 0;
    for (int i = 0; i < size; i++) {
        if (map[i][0] >= a[i] || map[i][1] >= a[i]) {
            answer++;
        }
    }

    return answer;
}