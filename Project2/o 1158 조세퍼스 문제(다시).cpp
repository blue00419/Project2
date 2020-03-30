#include<iostream>

using namespace std;

#define MAX 5000+1

int map[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;

	cin >> n >> k;
	cout << "<";

	int count = 0;
	int kcount;
	for(int i=0; i<n; i++){
		kcount = 0;
		while (1) {
			count++;
			if (count > n) {
				count = 1;
			}
			if (map[count] == 0) {
				kcount++;
			}
			if (kcount == k)
				break;
		}
		if (i != n - 1)
			cout << count << ", ";
		else
			cout << count << ">";
		map[count] = 1;
	}
	


	return 0;
}