#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    int** map = new int* [n];
    for (int i = 0; i < n; i++) {
        map[i] = new int[2];
    }
    for (int i = 0; i < n; i++) {
        map[i][0] = i - 1;
        map[i][1] = i + 1;
    }

    string answer(n, 'O');
    stack<int> s;
    for (int i = 0; i < cmd.size(); i++) {
        char tmp = cmd[i][0];

        if (tmp == 'U') {
            string b = cmd[i].substr(2);
            int a = stoi(b);

            for (int i = 0; i < a; i++) {
                k = map[k][0];
            }
        }
        else if (tmp == 'D') {
            string b = cmd[i].substr(2);
            int a = stoi(b);

            for (int i = 0; i < a; i++) {
                k = map[k][1];
            }
        }
        else if (tmp == 'C') {
            s.push(k);
            int left = map[k][0];
            int right = map[k][1];

            if (left != -1) {
                map[left][1] = right;
            }
            if (right != n) {
                map[right][0] = left;
            }

            answer[k] = 'X';

            if (right == n) {
                k = left;
            }
            else {
                k = right;
            }
        }
        else if (tmp == 'Z') {
            int a = s.top();
            s.pop();
            int left = map[a][0];
            int right = map[a][1];

            if (left != -1) {
                map[left][1] = a;
            }
            if (right != n) {
                map[right][0] = a;
            }
            answer[a] = 'O';
        }
    }

    return answer;
}