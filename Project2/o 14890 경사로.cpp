#include<iostream>
#include<cstring>

using namespace std;

#define MAX 100

int n, l;
int map[MAX][MAX];
bool visit[MAX][MAX];
int load[MAX][2];
int loadcount;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	bool ok;
	int count = 0;
	for (int i = 0; i < n; i++) {
		ok = true;
		for (int j = 0; j < n - 1; j++) {
			if (map[i][j] > map[i][j + 1]+ 1
				|| map[i][j] < map[i][j + 1] - 1) {
				ok = false;
				break;
			}
			if (map[i][j] == map[i][j + 1])
				continue;
			else if (map[i][j] + 1 == map[i][j + 1]) {
				if (visit[i][j] == 0) {
					int checkcount = 1;
					loadcount = 0;
					load[loadcount][0] = i;
					load[loadcount][1] = j;
					while (1) {
						if (checkcount == l) {
							break;
						}
						if (j - checkcount >= 0) {
							if (map[i][j - checkcount] == map[i][j]
								&& visit[i][j-checkcount] == 0) {
								loadcount++;
								load[loadcount][0] = i;
								load[loadcount][1] = j - checkcount;
								checkcount++;
							}
							else {
								ok = false;
								break;
							}
						}
						else {
							ok = false;
							break;
						}
					}
					if (ok) {
						for (int k = 0; k < loadcount + 1; k++) {
							visit[load[k][0]][load[k][1]] = 1;
						}
					}
				}
				else
					ok = false;
			}
			else if (map[i][j] - 1 == map[i][j + 1]) {
				if (visit[i][j + 1] == 0) {
					int checkcount = 1;
					loadcount = 0;
					load[loadcount][0] = i;
					load[loadcount][1] = j + 1;
					while (1) {
						if (checkcount == l) {
							break;
						}
						if (j + checkcount + 1 < n) {
							if (map[i][j + checkcount + 1] == map[i][j + 1]
								&& visit[i][j + checkcount + 1] == 0) {
								loadcount++;
								load[loadcount][0] = i;
								load[loadcount][1] = j + checkcount + 1;
								checkcount++;
							}
							else {
								ok = false;
								break;
							}
						}
						else {
							ok = false;
							break;
						}
					}
					if (ok) {
						for (int k = 0; k < loadcount + 1; k++) {
							visit[load[k][0]][load[k][1]] = 1;
						}
					}
				}
				else
					ok = false;
			}
			if (!ok)
				break;
		}
		if (ok) {
			count++;
		}
	}

	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < n; i++) {
		ok = true;
		for (int j = 0; j < n - 1; j++) {
			if (map[j][i] > map[j + 1][i] + 1
				|| map[j][i] < map[j + 1][i] -1) {
				ok = false;
				break;
			}
			if (map[j][i] == map[j + 1][i])
				continue;
			else if (map[j][i] + 1 == map[j + 1][i]) {
				if (visit[j][i] == 0) {
					int checkcount = 1;
					loadcount = 0;
					load[loadcount][0] = j;
					load[loadcount][1] = i;
					while (1) {
						if (checkcount == l) {
							break;
						}
						if (j - checkcount >= 0) {
							if (map[j - checkcount][i] == map[j][i]
								&& visit[j - checkcount][i] == 0) {
								loadcount++;
								load[loadcount][0] = j - checkcount;
								load[loadcount][1] = i;
								checkcount++;
							}
							else {
								ok = false;
								break;
							}
						}
						else {
							ok = false;
							break;
						}
					}
					if (ok) {
						for (int k = 0; k < loadcount + 1; k++) {
							visit[load[k][0]][load[k][1]] = 1;
						}
					}
				}
				else
					ok = false;
			}
			else if (map[j][i] - 1 == map[j + 1][i]) {
				if (visit[j + 1][i] == 0) {
					int checkcount = 1;
					loadcount = 0;
					load[loadcount][0] = j + 1;
					load[loadcount][1] = i;
					while (1) {
						if (checkcount == l) {
							break;
						}
						if (j + checkcount + 1 < n) {
							if (map[j + checkcount + 1][i] == map[j + 1][i]
								&& visit[j + checkcount + 1][i] == 0) {
								loadcount++;
								load[loadcount][0] = j + checkcount + 1;
								load[loadcount][1] = i;
								checkcount++;
							}
							else {
								ok = false;
								break;
							}
						}
						else {
							ok = false;
							break;
						}
					}
					if (ok) {
						for (int k = 0; k < loadcount + 1; k++) {
							visit[load[k][0]][load[k][1]] = 1;
						}
					}
				}
				else
					ok = false;				
			}
			if (!ok)
				break;
		}
		if (ok) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}