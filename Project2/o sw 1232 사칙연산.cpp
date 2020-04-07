#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define MAX 1000

string map[MAX];
vector<int> v[MAX];

double dfs(int cnt) {
	if (map[cnt] != "0") {
		string b = map[cnt];
		if (b != "+" && b != "-" && b != "*" && b != "/") {
			return atof(b.c_str());
		}
		double a = dfs(v[cnt][0]);
		double c = dfs(v[cnt][1]);

		if (b == "+") {
			return a + c;
		}
		if (b == "-") {
			return a - c;
		}
		if (b == "*") {
			return a * c;
		}
		if (b == "/") {
			return a / c;
		}
	}
	else {
		return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int n;

	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		for (int i = 0; i < MAX; i++) {
			map[i] = "0";
			v[i].clear();
		}
		

		string temp;
		int num, a, b;
		for (int i = 0; i < n; i++) {
			cin >> num >> temp;
			if (temp == "-" || temp == "+"
				|| temp == "*" || temp == "/") {
				cin >> a >> b;
				v[num].push_back(a);
				v[num].push_back(b);
			}
			map[num] = temp;
		}

		int result = (int)dfs(1);
		cout << "#" << ii << " " << result << endl;
	}

	return 0;
}