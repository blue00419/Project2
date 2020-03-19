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

	for (int i = 1; i < bsize + 1; i++) {
		for (int j = 1; j < asize + 1; j++) {
			map[i][j] = max(map[i - 1][j - 1] + (b[i-1] == a[j-1]),
				max(map[i - 1][j], map[i][j - 1]));
		}
	}
	cout << map[bsize][asize] << '\n';

	return 0;
}