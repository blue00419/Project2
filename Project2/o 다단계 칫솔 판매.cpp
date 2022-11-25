#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int costmap[10000];

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, int> me;
    map<string, string> parent;
    int mycost = 0;

    int size = enroll.size();
    for (int i = 0; i < size; i++) {
        costmap[i] = 0;
        me[enroll[i]] = i;
        parent[enroll[i]] = referral[i];
    }

    int size2 = seller.size();
    for (int i = 0; i < size2; i++) {
        int cost = amount[i] * 100;
        string start = seller[i];

        while (1) {
            if (start.compare("-") == 0) {
                mycost += cost;
                break;
            }
            int div = cost / 10;
            if (div == 0) {
                costmap[me[start]] += cost;
                break;
            }
            cost -= div;
            costmap[me[start]] += cost;
            start = parent[start];
            cost = div;
        }
    }

    for (int i = 0; i < size; i++) {
        answer.push_back(costmap[i]);
    }


    return answer;
}