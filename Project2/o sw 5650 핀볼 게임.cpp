#include<iostream>
#include<cstring>

using namespace std;

int n;
int map[102][102];
int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
int hole[5][2][2];

int main() {
	int t;
	cin >> t;

	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		memset(hole, 0, sizeof(hole));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 6) {
					if (hole[map[i][j] - 6][0][0] == 0) {
						hole[map[i][j] - 6][0][0] = i;
						hole[map[i][j] - 6][0][1] = j;
					}
					else {
						hole[map[i][j] - 6][1][0] = i;
						hole[map[i][j] - 6][1][1] = j;
					}
				}
			}
		}

		int x, y, d;
		int sum, max=0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] == 0) {

					for (int k = 0; k < 4; k++) {
						x = i;
						y = j;
						d = k;
						sum = 0;

						while (1) {
							if (map[x + dir[d][0]][y + dir[d][1]] >= 6) {
								x += dir[d][0];
								y += dir[d][1];
								if (hole[map[x][y] - 6][0][0] == x
									&& hole[map[x][y] - 6][0][1] == y) {
									
									int temp = map[x][y];
									x = hole[temp - 6][1][0];
									y = hole[temp - 6][1][1];
								}
								else {
									int temp = map[x][y];
									x = hole[temp - 6][0][0];
									y = hole[temp - 6][0][1];
								}
							}

							if (x + dir[d][0] == 0 || x + dir[d][0] > n
								|| y + dir[d][1] == 0 || y + dir[d][1] > n) {

								x += dir[d][0];
								y += dir[d][1];
								sum++;
								d += 2;
								if (d >= 4) d -= 4;
								if (x == i && y == j) {
									break;
								}
							}

							if (map[x + dir[d][0]][y + dir[d][1]] == 0) {
								x += dir[d][0];
								y += dir[d][1];
								if (x == i && y == j) {
									break;
								}
							}
							else {
								if (map[x + dir[d][0]][y + dir[d][1]] == -1) {
									break;
								}
								else if (map[x + dir[d][0]][y + dir[d][1]] == 5) {

									x += dir[d][0];
									y += dir[d][1];
									sum++;
									d += 2;
									if (d >= 4) d -= 4;
								}
								else {
									if (d == 0) {
										if (map[x + dir[d][0]][y + dir[d][1]] == 1
											|| map[x + dir[d][0]][y + dir[d][1]] == 2) {

											x += dir[d][0];
											y += dir[d][1]; 
											d += 2;
											if (d >= 4) d -= 4;
										}
										else if (map[x + dir[d][0]][y + dir[d][1]] == 3){
											x += dir[d][0];
											y += dir[d][1];
											d++;
										}
										else if (map[x + dir[d][0]][y + dir[d][1]] == 4) {
											x += dir[d][0];
											y += dir[d][1];
											d = 3;
										}
									}
									else if (d == 1) {
										if (map[x + dir[d][0]][y + dir[d][1]] == 2
											|| map[x + dir[d][0]][y + dir[d][1]] == 3) {

											x += dir[d][0];
											y += dir[d][1]; 
											d += 2;
											if (d >= 4) d -= 4;
										}
										else if (map[x + dir[d][0]][y + dir[d][1]] == 4) {
											x += dir[d][0];
											y += dir[d][1];
											d++;
										}
										else if (map[x + dir[d][0]][y + dir[d][1]] == 1) {
											x += dir[d][0];
											y += dir[d][1];
											d--;
										}
									}
									else if (d == 2) {
										if (map[x + dir[d][0]][y + dir[d][1]] == 3
											|| map[x + dir[d][0]][y + dir[d][1]] == 4) {

											x += dir[d][0];
											y += dir[d][1]; 
											d += 2;
											if (d >= 4) d -= 4;
										}
										else if (map[x + dir[d][0]][y + dir[d][1]] == 1) {
											x += dir[d][0];
											y += dir[d][1];
											d++;
										}
										else if (map[x + dir[d][0]][y + dir[d][1]] == 2) {
											x += dir[d][0];
											y += dir[d][1];
											d--;
										}
									}
									else if (d == 3) {
										if (map[x + dir[d][0]][y + dir[d][1]] == 4
											|| map[x + dir[d][0]][y + dir[d][1]] == 1) {

											x += dir[d][0];
											y += dir[d][1]; 
											d += 2;
											if (d >= 4) d -= 4;
										}
										else if (map[x + dir[d][0]][y + dir[d][1]] == 2) {
											x += dir[d][0];
											y += dir[d][1];
											d = 0;
										}
										else if (map[x + dir[d][0]][y + dir[d][1]] == 3) {
											x += dir[d][0];
											y += dir[d][1];
											d--;
										}
									}
									sum++;
								}

								if (x == i && y == j) {
									break;
								}
							}
						}

						if (max < sum) {
							max = sum;
						}
					}
				}
			}
		}
		cout << "#" << ii << " " << max << endl;
	}


	return 0;
}