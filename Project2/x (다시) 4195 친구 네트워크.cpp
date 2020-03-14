#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

map<string, string> maps;
map<string, int> counter;


string find(string a) {
	if (a == maps[a]) return a;

	string b = find(maps[a]);
	maps[a] = b;
	return b;
}

void Union(string a, string b) {

	a = find(a);
	b = find(b);

	maps[a] = b;
	counter[a] += counter[b];
	counter[b] = counter[a];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, f;
	cin >> n;

	string a, b;
	for (int i = 0; i < n; i++) {
		cin >> f;
		maps.clear();
		counter.clear();

		for (int j = 0; j < f; j++) {
			cin >> a >> b;

			if (maps.count(a) == 0) {
				maps[a] = a;
				counter[a] = 1;
			}
			if (maps.count(b) == 0) {
				maps[b] = b;
				counter[b] = 1;
			}

			Union(a, b);
			
			printf("%d\n", counter[maps[a]]);
		}
	}

	return 0;
}