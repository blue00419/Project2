#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b, v;
	cin >> a >> b >> v;
	cout << (((v - a) % (a - b) == 0) ? ((v - a) / (a - b) + 1) : ((v - a) / (a - b) + 2)) << '\n';
	return 0;
}