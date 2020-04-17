#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAX 500+1

double map[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int ii = 1; ii <= t; ii++) {
		double n;
		cin >> n;

		string str1, str2;
		cin >> str1 >> str2;

		memset(map, 0, sizeof(map));

		for (int i = 1; i <= str2.length(); i++) {
			for (int j = 1; j <= str1.length(); j++) {
				map[i][j] = max(map[i - 1][j], max(map[i][j - 1],
						map[i - 1][j - 1] + (str2[i - 1] == str1[j - 1])));
			}
		}

		double result = map[str2.length()][str1.length()] / n * 100.0;
		printf("#%d %.2f\n", ii, result);
	}

	return 0;
}