#include <iostream>
#include <string>

using namespace std;

bool dp[2500][2500] = { 0, };

int solution(string s)
{
    int size = s.length();
    for (int i = 0; i < size; i++) {
        dp[i][i] = 1;
    }
    for (int i = 0; i < size - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
        }
    }

    int answer = 1;
    for (int i = 3; i <= size; i++) {
        for (int start = 0; start <= size - i; start++) {
            int end = i + start - 1;
            if (s[start] == s[end] && dp[start + 1][end - 1]) {
                dp[start][end] = 1;

                if (answer < i) {
                    answer = i;
                }
            }
        }
    }

    return answer;
}