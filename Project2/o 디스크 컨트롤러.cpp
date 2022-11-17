#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct pi {
    int t;
    int s;
    pi(int tt, int ss) : t(tt), s(ss) {}

    bool operator<(const pi p) const {
        return this->t > p.t;
    }
};

bool cmp(vector<int> a, vector<int> b) {
    if (a[0] < b[0]) {
        return true;
    }
    return false;
}

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), cmp);

    int index = 0;
    int time = 0;
    int time2 = 0;
    priority_queue<pi> q;
    int answer = 0;
    int start = 0;
    while (1) {
        if (jobs.size() != index) {
            if (time == jobs[index][0]) {
                q.push({ jobs[index][1], jobs[index][0] });
                index++;
                continue;
            }
        }
        if (time2 == 0) {
            if (start != -1) {
                answer += (time - start);
                start = -1;
            }
            if (!q.empty()) {
                time2 = q.top().t;
                start = q.top().s;
                q.pop();
            }
            else {
                if (jobs.size() == index) {
                    break;
                }
            }
        }
        time++;
        time2--;
        if (time2 < 0) {
            time2 = 0;
        }
    }
    answer /= jobs.size();
    return answer;
}