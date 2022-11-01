#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int qsort(vector<int> &v, int left, int right) {
	int pivot = v[left];
	int i = left, j = right;

	while (i < j) {
		while (pivot < v[j]) {
			j--;
		}
		while (i < j && pivot >= v[i]) {
			i++;
		}
		int tmp = v[i];
		v[i] = v[j];
		v[j] = tmp;
	}
	v[left] = v[i];
	v[i] = pivot;

	return i;
}

void quick_sort(vector<int> &v, int left, int right) {
	if (left >= right) return;

	int pivot = qsort(v, left, right);

	quick_sort(v, left, pivot - 1);
	quick_sort(v, pivot + 1, right);
}

bool b_search(vector<int>& v, int left, int right, int m) {
	int mid = (left + right) / 2;
	if (v[mid] == m) return true;
	if (left == mid || right == mid) return false;

	if (v[mid] < m) {
		b_search(v, mid, right, m);
	}
	else {
		b_search(v, left, mid, m);
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v1, v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v1.push_back(a);
		v.push_back(a);
	}
	sort(v1.begin(), v1.end());
	cout << binary_search(v1.begin(), v1.end(), m) << endl;



	quick_sort(v, 0, n - 1);
	cout << b_search(v, 0, n - 1, m) << endl;
	
	return 0;
}