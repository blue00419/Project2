#include<iostream>
#include<vector>
// ³¢¿ö¸ÂÃß±â·Î Ç¯...
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	cout << fixed;
	cout.precision(24);

	for (int ii = 1; ii <= t; ii++) {
		int n;
		cin >> n;

		vector<double> vx, vw;
		vector<double> result;

		double a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			vx.push_back(a);
		}
		for (int i = 0; i < n; i++) {
			cin >> a;
			vw.push_back(a);
		}

		double fsum, bsum;
		double left, right, mid;
		int x;
		double p = 0.00000000000928171817154;

		for (int i = 0; i < n - 1; i++) {
			left = vx[i];
			right = vx[i + 1];
			while (1) {
				mid = (left + right) / 2;

				fsum = 0;
				bsum = 0;
				x = i;
				while (1) {
					if (x < 0)
						break;
					fsum += (vw[x] / ((mid - vx[x]) * (mid - vx[x])));
					x--;
				}
				x = i + 1;
				while (1) {
					if (x >= n)
						break;
					bsum += (vw[x] / ((mid - vx[x]) * (mid - vx[x])));
					x++;
				}
				if (fsum == bsum || left == right) {
					result.push_back(mid);
					break;
				}
				if (left + p > mid) {
					result.push_back(left + 0.000000000002);
					break;
				}
				if (fsum > bsum) {
					left = mid;
				}
				else if (fsum < bsum) {
					right = mid;
				}
			}
			result.push_back(mid);
		}

		cout << "#" << ii << " ";
		for (int i = 0; i < result.size(); i++) {
			printf("%.10f ", result[i]);
		}
		cout << endl;
	}

	return 0;
}