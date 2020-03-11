#include<iostream>
#include<stack>

using namespace std;

int n;

void hanoi(stack<int> a, stack<int> b, stack<int> c) {

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	stack<int> a, b, c;

	cin >> n;
	for (int i = n; i > 0; i--) {
		a.push(n);
	}

	hanoi(a, b, c);

	return 0;
}