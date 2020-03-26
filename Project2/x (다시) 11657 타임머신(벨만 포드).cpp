#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

typedef pair<int, int> pi;

#define MAX 500+1

int n, m;
int map[MAX];
vector<pi> v[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
	}

	memset(map, 0x3f3f3f3f, sizeof(map));

	map[1] = 0;
	
	// ���� ���� �˰����� ���۳�带 �����ϰ� 
	// n-1����ŭ�� �������� ����� �������� ���� �˻��ؼ� ���� ������Ʈ���ش�
	// ���������� �ѹ��� �˻縦 �����ϴµ� �̶� ������Ʈ�� �߻��ϸ�
	// ���� ����Ŭ�� �����ϴ°��� �ȴ�.
	bool cycle = false;
	for (int i = 1; i <= n; i++) { // n-1�� ����Ʋ + ���� ����Ŭ üũ 1��
		for (int j = 1; j <= n; j++) { // j�� ��忡�� ����ϴ�
			for (int k = 0; k < v[j].size(); k++) { // ������
				if (map[j] != 0x3f3f3f3f) {
					if (map[v[j][k].first] > map[j] + v[j][k].second) {
						map[v[j][k].first] = map[j] + v[j][k].second;
						if (i == n) cycle = true;
					}
				}
			}
		}
	}

	if (cycle) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (map[i] == 0x3f3f3f3f)
				cout << -1 << '\n';
			else
				cout << map[i] << '\n';
		}
	}

	return 0;
}