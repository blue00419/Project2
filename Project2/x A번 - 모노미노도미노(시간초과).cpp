#include<iostream>

using namespace std;

int map[11][11];
int n;
int score = 0;

void right_line(int right) {
	int x, y;
	right--;
	for (int i = right; i >= 4; i--) {
		for (int j = 0; j < 4; j++) {
			if (map[j][i] == 1) {
				map[j][i] = 0;
				x = j;
				y = i;
				while (1) {
					y++;
					if (y == 10 || map[x][y] != 0) {
						y--;
						map[x][y] = 1;
						break;
					}
				}
			}
			else if (map[j][i] == 2) {
				map[j][i] = 0;
				map[j][i - 1] = 0;
				x = j;
				y = i;
				while (1) {
					y++;
					if (y == 10 || map[x][y] != 0) {
						y--;
						map[x][y] = 2;
						y--;
						map[x][y] = 2;
						break;
					}
				}
			}
			else if (map[j][i] == 3) {
				x = j;
				y = i;
				map[j][i] = 0;
				map[j + 1][i] = 0;
				while (1) {
					y++;
					if (map[x][y] == 0 && map[x + 1][y] == 0) {
						if(y!=10) continue;
					}
					y--;
					map[x][y] = 3;
					map[x + 1][y] = 3;
					break;
				}
			}
		}
	}
}

void bottom_line(int bottom) {
	int x, y;
	bottom--;
	for (int i = bottom; i >= 4; i--) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j] == 1) {
				map[i][j] = 0;
				x = i;
				y = j;
				while (1) {
					x++;
					if (x == 10 || map[x][y] != 0) {
						x--;
						map[x][y] = 1;
						break;
					}
				}
			}
			else if (map[i][j] == 2) {
				x = i;
				y = j;
				map[i][j] = 0;
				map[i][j + 1] = 0;
				while (1) {
					x++;
					if (map[x][y] == 0 && map[x][y + 1] == 0) {
						if(x!= 10) continue;
					}
					x--;
					map[x][y] = 2;
					map[x][y + 1] = 2;
					break;
				}
			}
			else if (map[i][j] == 3) {
				map[i][j] = 0;
				map[i - 1][j] = 0;
				x = i;
				y = j;
				while (1) {
					x++;
					if (x == 10 || map[x][y] != 0) {
						x--;
						map[x][y] = 3;
						x--;
						map[x][y] = 3;
						break;
					}
				}
			}
		}
	}
}

bool right_score(int right, int a) {
	bool ok, line = false;
	if (a == 0) {
		a = 4;
	}
	else if (a == 2) {
		a = 2;
	}
	else {
		a = 1;
	}
	for (int i = right; i > right-a; i--) {
		ok = true;
		for (int j = 0; j < 4; j++) {
			if (map[j][i] == 0) ok = false;
		}

		if (ok) {
			line = true;
			score++;
			for (int j = 0; j < 4; j++) {
				if (map[j][i] == 2) {
					int x, y;
					x = j;
					y = i;
					int zz = 0;
					while (1) {
						y--;
						if (map[x][y] == 2) {
							zz++;
						}
						else {
							break;
						}
					}
					if (zz % 2 == 0) {
						map[j][i + 1] = 1;
					}
					else {
						map[j][i - 1] = 1;
					}
				}
				map[j][i] = 0;
			}
		}
	}
	return line;
}

bool bottom_score(int bottom, int a) {
	bool ok, line = false;
	if (a == 0) {
		a = 4;
	}
	else if (a == 3) {
		a = 2;
	}
	else {
		a = 1;
	}
	for (int i = bottom; i > bottom - a; i--) {
		ok = true;
		for (int j = 0; j < 4; j++) {
			if (map[i][j] == 0) ok = false;
		}

		if (ok) {
			line = true;
			score++;
			for (int j = 0; j < 4; j++) {
				if (map[i][j] == 3) {
					int x, y;
					x = i;
					y = j;
					int zz = 0;
					while (1) {
						x--;
						if (map[x][y] == 3) {
							zz++;
						}
						else {
							break;
						}
					}
					if (zz % 2 == 0) {
						map[i + 1][j] = 1;
					}
					else {
						map[i - 1][j] = 1;
					}
				}
				map[i][j] = 0;
			}
		}
	}
	return line;
}

int main() {

	cin >> n;

	int a, b, c, x ,y;
	int right=0, bottom=0;
	for (int ii = 0; ii < n; ii++) {
		cin >> a >> b >> c;

		if (a == 1) {
			// 오른쪽
			x = b;
			y = c;
			while (1) {
				y++;
				if (y == 10 || map[x][y] != 0) {
					y--;
					right = y;
					map[x][y] = 1;
					break;
				}
			}

			// 아래
			y = c;
			while (1) {
				x++;
				if (x == 10 || map[x][y] != 0) {
					x--;
					bottom = x;
					map[x][y] = 1;
					break;
				}
			}
		}
		else if (a == 2) {
			// 오른쪽
			x = b;
			y = c;
			while (1) {
				y++;
				if (y == 10 || map[x][y] != 0) {
					y--;
					right = y;
					map[x][y] = 2;
					y--;
					map[x][y] = 2;
					break;
				}
			}

			// 아래
			y = c;
			while (1) {
				x++; 
				if (map[x][y] == 0 && map[x][y + 1] == 0) {
					continue;
				}
				x--;
				bottom = x;
				map[x][y] = 2;
				map[x][y + 1] = 2;
				break;
			}
		}
		else if (a == 3) {
			// 오른쪽
			x = b;
			y = c;
			while (1) {
				y++;
				if (map[x][y] == 0 && map[x+1][y] == 0) {
					continue;
				}
				y--;
				right = y;
				map[x][y] = 3;
				map[x+1][y] = 3;
				break;
			}

			// 아래
			y = c;
			while (1) {
				x++;
				if (x == 10 || map[x][y] != 0) {
					x--;
					bottom = x;
					map[x][y] = 3;
					x--;
					map[x][y] = 3;
					break;
				}
			}
		}

		int aa = a;
		// 오른쪽
		while (1) {
			// 점수 획득
			bool line = right_score(right, a);

			// 라인 당기기
			if (line) {
				right_line(right);
			}

			// 연한 칸 확인
			int z = 0;
			bool ok;
			for (int i = 5; i >=4; i--) {
				ok = false;
				for (int j = 0; j < 4; j++) {
					if (map[j][i] != 0) {
						ok = true;
						break;
					}
				}
				if (!ok) break;
				if (ok) z++;
			}

			if (!line && z == 0) break;

			// 있으면 없애고 당기기
			if (z != 0) {
				for (int i = 9; i > 9 - z; i--) {
					for (int j = 0; j < 4; j++) {
						if (map[j][i] == 2) {
							int x, y;
							x = j;
							y = i;
							int zz = 0;
							while (1) {
								y--;
								if (map[x][y] == 2) {
									zz++;
								}
								else {
									break;
								}
							}
							if (zz % 2 == 0) {
								map[j][i + 1] = 1;
							}
							else {
								map[j][i - 1] = 1;
							}
						}
						map[j][i] = 0;
					}
				}
				right_line(10-z);
			}
			a = 0;
			right = 9;
		}

		a = aa;
		// 아래쪽
		while (1) {
			// 점수 획득
			bool line = bottom_score(bottom, a);

			// 라인 당기기
			if (line) {
				bottom_line(bottom);
			}

			// 연한 칸 확인
			int z = 0;
			bool ok;
			for (int i = 4; i < 6; i++) {
				ok = false;
				for (int j = 0; j < 4; j++) {
					if (map[i][j] != 0) {
						ok = true;
						break;
					}
				}
				if (ok) z++;
			}

			if (!line && z == 0) break;

			// 있으면 없애고 당기기
			if (z != 0) {
				for (int i = 9; i > 9 - z; i--) {
					for (int j = 0; j < 4; j++) {
						if (map[i][j] == 3) {
							int x, y;
							x = i;
							y = j;
							int zz = 0;
							while (1) {
								x--;
								if (map[x][y] == 3) {
									zz++;
								}
								else {
									break;
								}
							}
							if (zz % 2 == 0) {
								map[i + 1][j] = 1;
							}
							else {
								map[i - 1][j] = 1;
							}
						}
						map[i][j] = 0;
					}
				}
				bottom_line(10-z);
			}
			a = 0;
			bottom = 9;
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] != 0) sum++;
		}
	}

	cout << score << endl << sum << endl;

	return 0;
}