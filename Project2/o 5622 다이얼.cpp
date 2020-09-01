#include<iostream>

using namespace std;

int main() {
	char str[20];
	fgets(str, 20, stdin);

	int arr[]{ 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,
		8,8,8,8,9,9,9,10,10,10,10 };
	int index = 0;
	int result = 0;
	while (1) {
		if (str[index] == '\n') break;

		result += arr[str[index]- 65];

		index++;
	}
	cout << result << endl;
	return 0;
}