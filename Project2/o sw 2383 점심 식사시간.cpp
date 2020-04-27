#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

#define MAX 10+1

int n;
int map[MAX][MAX];
int person[MAX][2], reperson[MAX][2], stair[2][2], pcount;
bool visit[MAX];
static int alltime;

void dfs(int cnt) {
	if (cnt == pcount) {
		queue<pair<int, int> > fq, sq;

		for (int i = 1; i < MAX; i++) {
			for (int j = 0; j < 2; j++) {
				person[i][j] = reperson[i][j];
			}
		}

		bool end[MAX] = { 0, }, arrive[MAX] = { 0, }, ready[MAX] = { 0, };
		int time = 0, endcount=0, size;
		int a, b;
		while (1) {

			size = fq.size();
			for (int j = 0; j < size; j++) {
				a = fq.front().first;
				b = fq.front().second;
				fq.pop();
				a--;
				if (a == 0) {
					endcount++;
					end[b] = 1;
				}
				else {
					fq.push({ a,b });
				}
			}

			size = sq.size();
			for (int j = 0; j < size; j++) {
				a = sq.front().first;
				b = sq.front().second;
				sq.pop();
				a--;
				if (a == 0) {
					endcount++;
					end[b] = 1;
				}
				else {
					sq.push({ a,b });
				}
			}

			if (endcount == pcount - 1) {
				break;
			}
	
			for (int i = 1; i <pcount; i++) {
				if (end[i] == 0) {
					if (arrive[i] == 0) { // 계단도착 전(도착하고 계단수 + 1로 queue넣기)
						if (visit[i] == 0) { // 1번계단
							if (person[i][0] > stair[0][0]) {
								person[i][0]--;
							}
							else if (person[i][0] < stair[0][0]) {
								person[i][0]++;
							}
							else if (person[i][0] == stair[0][0]) {
								if (person[i][1] > stair[0][1]) {
									person[i][1]--;
								}
								else if (person[i][1] < stair[0][1]) {
									person[i][1]++;
								}
								else if (person[i][1] == stair[0][1]) {
									if (fq.size() < 3) {
										if (ready[i] == 0) {
											fq.push({ map[stair[0][0]][stair[0][1]] + 1, i });
											arrive[i] = 1;
										}
										else {
											fq.push({ map[stair[0][0]][stair[0][1]], i });
											arrive[i] = 1;
										}
									}
									else {
										ready[i] = 1;
									}
								}
							}
						}
						else { // 2번계단
							if (person[i][0] > stair[1][0]) {
								person[i][0]--;
							}
							else if (person[i][0] < stair[1][0]) {
								person[i][0]++;
							}
							else if (person[i][0] == stair[1][0]) {
								if (person[i][1] > stair[1][1]) {
									person[i][1]--;
								}
								else if (person[i][1] < stair[1][1]) {
									person[i][1]++;
								}
								else if (person[i][1] == stair[1][1]) {
									if (sq.size() < 3) {
										if (ready[i] == 0) {
											sq.push({ map[stair[1][0]][stair[1][1]] + 1, i });
											arrive[i] = 1;
										}
										else {
											sq.push({ map[stair[1][0]][stair[1][1]], i });
											arrive[i] = 1;
										}
									}
									else {
										ready[i] = 1;
									}
								}
							}
						}
					}
				}
			}

			time++;
		}

		if (alltime > time) {
			alltime = time;
		}
		
		return;
	}

	visit[cnt] = 1;
	dfs(cnt + 1);
	visit[cnt] = 0;
	dfs(cnt + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		memset(person, 0, sizeof(person));
		memset(reperson, 0, sizeof(reperson));
		memset(stair, 0, sizeof(stair));
		memset(visit, 0, sizeof(visit));
		pcount = 1;
		alltime = 0x3f3f3f3f;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					person[pcount][0] = i;
					person[pcount][1] = j;
					reperson[pcount][0] = i;
					reperson[pcount][1] = j;

					pcount++;
				}
				else if (map[i][j] > 1) {
					if (stair[0][0] == 0) {
						stair[0][0] = i;
						stair[0][1] = j;
					}
					else {
						stair[1][0] = i;
						stair[1][1] = j;
					}
				}
			}
		}

		dfs(1);
		cout << "#" << ii << " " << alltime << endl;

	}

	return 0;
}