#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define MAX 1000+1

string a, b;
int map[MAX][MAX] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	getline(cin, a);
	getline(cin, b);

	for (int i = 1; i <= b.length(); i++) {
		for (int j = 1; j <=a.length(); j++) {
			map[i][j] = max(max(map[i][j - 1], map[i - 1][j]),
				map[i - 1][j - 1] + (b[i-1] == a[j-1]));
		}
	}
	cout << map[b.length()][a.length()] << endl;

	return 0;
}