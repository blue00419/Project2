#include<iostream>
#include<vector>

using namespace std;

vector<int> map[5];
int k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char temp;
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> temp;
			map[i].push_back(temp - '0');
		}
	}

	cin >> k;
	int a, b;
	int start, end, gijun;
	int tmp;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		
		// 2¹øÀÌ¶û 6¹øÀÌ ¸Â´ê´Â°÷
		gijun = a;
		start = gijun - 1;
		end = gijun + 1;

		while (1) {
			if (start > 0) {
				if (map[start][2] != map[gijun][6]) {
					gijun = start;
					start = start - 1;
				}
				else
					break;
			}
			else
				break;
		}
		
		gijun = a;
		while (1) {
			if (end <= 4) {
				if (map[gijun][2] != map[end][6]) {
					gijun = end;
					end = end + 1;
				}
				else
					break;
			}
			else
				break;
		}

		start++;
		end--;
		
		int dir;
		if (b == 1) {
			dir = b;
			tmp = map[a][7];
			map[a].erase(map[a].end() - 1);
			map[a].insert(map[a].begin(), tmp);

			gijun = a;
			while (1) {
				if (start != gijun) {
					gijun--;
					if (dir == 1)
						dir = -1;
					else
						dir = 1;

					if (dir == 1) {
						tmp = map[gijun][7];
						map[gijun].erase(map[gijun].end() - 1);
						map[gijun].insert(map[gijun].begin(), tmp);
					}
					else {
						tmp = map[gijun][0];
						map[gijun].erase(map[gijun].begin());
						map[gijun].push_back(tmp);
					}
				}
				else
					break;
			}
			gijun = a;
			dir = b;
			while (1) {
				if (end != gijun) {
					gijun++;
					if (dir == 1)
						dir = -1;
					else
						dir = 1;

					if (dir == 1) {
						tmp = map[gijun][7];
						map[gijun].erase(map[gijun].end() - 1);
						map[gijun].insert(map[gijun].begin(), tmp);
					}
					else {
						tmp = map[gijun][0];
						map[gijun].erase(map[gijun].begin());
						map[gijun].push_back(tmp);
					}
				}
				else
					break;
			}
		}
		else if (b == -1) {
			dir = b;
			tmp = map[a][0];
			map[a].erase(map[a].begin());
			map[a].push_back(tmp);
			gijun = a;
			while (1) {
				if (start != gijun) {
					gijun--;
					if (dir == 1)
						dir = -1;
					else
						dir = 1;

					if (dir == 1) {
						tmp = map[gijun][7];
						map[gijun].erase(map[gijun].end() - 1);
						map[gijun].insert(map[gijun].begin(), tmp);
					}
					else {
						tmp = map[gijun][0];
						map[gijun].erase(map[gijun].begin());
						map[gijun].push_back(tmp);
					}
				}
				else
					break;
			}
			gijun = a;
			dir = b;
			while (1) {
				if (end != gijun) {
					gijun++;
					if (dir == 1)
						dir = -1;
					else
						dir = 1;

					if (dir == 1) {
						tmp = map[gijun][7];
						map[gijun].erase(map[gijun].end() - 1);
						map[gijun].insert(map[gijun].begin(), tmp);
					}
					else {
						tmp = map[gijun][0];
						map[gijun].erase(map[gijun].begin());
						map[gijun].push_back(tmp);
					}
				}
				else
					break;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= 4; i++) {
		if (i == 1) {
			if (map[i][0] == 1)
				sum += 1;
		}
		else if (i == 2) {
			if (map[i][0] == 1)
				sum += 2;
		}
		else if (i == 3) {
			if (map[i][0] == 1)
				sum += 4;
		}
		else if (i == 4) {
			if (map[i][0] == 1)
				sum += 8;
		}
	}

	cout << sum << '\n';

	return 0;
}