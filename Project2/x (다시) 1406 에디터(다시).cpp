#include<iostream>
#include<string>
#include<list>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	list<char> l(str.begin(), str.end());
	list<char>::iterator iter = l.end();

	int n;
	cin >> n;

	char comm;
	for (int i = 0; i < n; i++) {
		cin >> comm;
		
		if (comm == 'L') {
			if (iter != l.begin()) {
				iter--;
			}
		}
		else if (comm == 'D') {
			if (iter != l.end()) {
				iter++;
			}
		}
		else if (comm == 'B') {
			if (iter != l.begin()) {
				iter--;
				iter = l.erase(iter);
			}
		}
		else if (comm == 'P') {
			cin >> comm;
			l.insert(iter, comm);
		}
	}
	
	int size = l.size();
	for (int i = 0; i < size; i++) {
		cout << l.front();
		l.pop_front();
	}

	return 0; 
}