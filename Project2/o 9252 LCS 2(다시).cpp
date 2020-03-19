#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define MAX 1000+1

string a, b;
int map[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	getline(cin, a);
	getline(cin, b);

	int asize = a.length(), bsize = b.length();

	int maxx = 0;
	int maxs[2];
	for (int i = 1; i < bsize + 1; i++) {
		for (int j = 1; j < asize + 1; j++) {
			map[i][j] = max(map[i - 1][j],max(map[i][j - 1],
				map[i - 1][j - 1] + (b[i - 1] == a[j - 1])));
			if (map[i][j] > maxx) {
				maxx = map[i][j];
				maxs[0] = i;
				maxs[1] = j;
			}
		}
	}
	if (map[bsize][asize] == 0) {
		cout << 0 << endl;
	}
	else {
		string result = "";
		result += b[maxs[0] - 1];

		bool ok = false;
		while (maxx > 1) {
			maxx--;
			for (int i = maxs[1] - 1; i >= 0; i--) {
				if (map[maxs[0] - 1][i] != maxx) {
					maxs[1] = i + 1;
					break;
				}
			}

			for (int i = maxs[0] - 1; i >= 0; i--) {
				if (map[i][maxs[1]] != maxx) {
					maxs[0] = i + 1;
					break;
				}
			}
			result += b[maxs[0] - 1];
		}

		cout << map[bsize][asize] << endl;

		int size = result.size();
		for (int i = size - 1; i >= 0; i--) {
			cout << result[i];
		}
	}

	return 0;
}