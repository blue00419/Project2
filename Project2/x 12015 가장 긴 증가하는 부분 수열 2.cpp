#include <cstdio>
#include <vector>
#include<algorithm>

using namespace std;

int main() {

    int N, temp, cnt = 0;
    vector <int> v;

    v.push_back(0);

    scanf_s("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf_s("%d", &temp);
        if (temp > v.back()) { v.push_back(temp); cnt++; }
        else {
            vector<int>::iterator low = lower_bound(v.begin(), v.end(), temp);
            *low = temp;
        }
        for (int j = 0; j < v.size(); j++) {
            printf("%d\n", v[j]);
        }
    }

    printf("%d\n", cnt);

    return 0;
}
