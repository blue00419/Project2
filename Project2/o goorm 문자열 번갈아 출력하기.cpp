#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	getline(cin, str);

	int leng = str.length();

	int back = leng - 1;
	for (int i = 0; i < leng; i++) {
		if (i > back) {
			break;
		}
		else if (i == back) {
			cout << str[i] << endl;
			break;
		}
		cout << str[i] << str[back];
		back--;
	}
	return 0;
}