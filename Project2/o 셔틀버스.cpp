#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct pi {
    int time;
    int count;
};

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> v;
    int size = timetable.size();

    for (int i = 0; i < size; i++) {
        int a = stoi(timetable[i].substr(0, 2));
        int b = stoi(timetable[i].substr(3, 2));
        a *= 60;
        a += b;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int time = 540;
    int index = 0;
    int result;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = index; j < size; j++) {
            if (v[j] <= time) {
                index++;
                count++;
                if (count == m) break;
            }
            else break;
        }
        if (i == n - 1) {
            if (count == m) {
                result = v[index - 1] - 1;
            }
            else {
                result = time;
            }
            break;
        }
        time += t;
    }
    int a = result / 60;
    int b = result % 60;
    if (a < 10) {
        answer += "0";
    }
    answer += to_string(a) + ":";

    if (b < 10) {
        answer += "0";
    }
    answer += to_string(b);
    return answer;
}