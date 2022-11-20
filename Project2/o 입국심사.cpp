#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long max = 0;
    int size = times.size();
    for (int i = 0; i < size; i++) {
        if (times[i] > max) {
            max = times[i];
        }
    }
    max *= n;
    long long min = 0;
    long long answer = max;
    while (min <= max) {
        long long mid = (min + max) / 2;
        long long count = 0;
        for (int i = 0; i < size; i++) {
            count += (mid / times[i]);
        }
        if (count >= n) {
            if (answer > mid) {
                answer = mid;
            }
            max = mid - 1;
        }
        else {
            min = mid + 1;
        }
    }
    return answer;
}