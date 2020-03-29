#include<iostream>
#include<algorithm>
using namespace std;

int a, b, c, d;
int map1[2], map2[2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c >> d;

	int na = b % a;

	if (c != 0 && c != a && d != 0 && d != b) {
		cout << -1 << '\n';
		return 0;
	}
	if (na != 0) {
		if (c % na != 0 || d % na != 0) {
			cout << -1 << '\n';
			return 0;
		}
	}

	int count1 = 0;
	int count2 = 0;
	bool end1 = false;
	bool end2 = false;
	while (1) {
		if (map1[0] == c && map1[1] == d) {
			cout << count1 << '\n';
			break;
		}
		if (map1[1] == b)
			map1[1] = 0;
		else if (map1[0] == 0)
			map1[0] = a;
		else if (map1[0] > 0) {
			if (b - map1[1] >= map1[0]) {
				map1[1] += map1[0];
				map1[0] = 0;
			}
			else {
				map1[0] -= (b - map1[1]);
				map1[1] += (b - map1[1]);
			}
		}
		count1++;

		if (map2[0] == c && map2[1] == d) {
			cout << count2 << '\n';
			break;
		}
		if (map2[0] == a)
			map2[0] = 0;
		else if (map2[1] == 0)
			map2[1] = b;
		else if (map2[1] > 0) {
			if (a - map2[0] >= map2[1]) {
				map2[0] += map2[1];
				map2[1] = 0;
			}
			else {
				map2[1] -= (a - map2[0]);
				map2[0] += (a - map2[0]);
			}	
		}
		count2++;
	}
	return 0;
}