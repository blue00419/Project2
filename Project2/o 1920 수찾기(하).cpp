#include<iostream>
#include<map>
using namespace std;

int main() {
	map<int, int> a;

	int n, m;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		a[temp] = 1;
	}

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);

		if (a.count(temp)) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
	
	return 0;
}