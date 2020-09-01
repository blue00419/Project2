#include<iostream>

using namespace std;

#define MAX 1000010
char str[MAX];

int main() {
	fgets(str, MAX, stdin);
	
	if (str[0] == '\n'
		|| (str[0] == ' ' && str[1] == ' ')
		|| (str[0] == ' ' && str[1] == '\n')) {
		cout << "0" << endl;
		return 0;
	}
	int count = 1;
	int index = 0;
	while (1) {
		if (str[index] == '\n') {
			break;
		}
		if (str[index] == ' ') {
			count++;
		}
		index++;
	}
	if (str[0] == ' ') {
		count--;
	}
	if (str[index - 1] == ' ') {
		count--;
	}
	cout << count << endl;
	return 0;
}