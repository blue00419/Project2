#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, a;
vector<int> nmap, mmap;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		nmap.push_back(a);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		mmap.push_back(a);
	}

	sort(nmap.begin(), nmap.end());

	for (int i = 0; i < n; i++) {
		cout << binary_search(nmap.begin(), nmap.end(), mmap[i])
			<< '\n';
	}

	return 0;
}