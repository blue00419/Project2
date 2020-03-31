#include<iostream>
#include<vector>

using namespace std;

#define MAX 4000000+1

int map[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map[0] = 1;
	map[1] = 1;
	for (int i = 2; i < MAX; i++) {
		if (map[i] == 0) {
			for (int j = i + i; j < MAX; j = j + i)
				map[j] = 1;
		}
	}

	vector<int> v;
	for (int i = 2; i < MAX; i++) {
		if (map[i] == 0)
			v.push_back(i);
	}

	int n;
	cin >> n;

	int size = v.size();
	int count = 0;
	int sum;
	for (int i = 0; i < size; i++) {
		if (v[i] > n)
			break;
		sum = 0;
		for (int j = i; j < size; j++) {
			sum += v[j];
			if (sum == n) {
				count++;
				break;
			}
			if (sum > n)
				break;
		}
	}
	cout << count << endl;

	return 0;
}