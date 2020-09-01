#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int a, b;
	cin >> a >> b;
	vector<int> v;

	int temp;
	for (int i = 0; i < a + b; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}