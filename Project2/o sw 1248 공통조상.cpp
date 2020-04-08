#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define MAX 10000+1
vector<int> vv[MAX];
int map[MAX];

int bfs(int l, int r) {
	vector<int> lp, rp;
	queue<int> lq, rq;
	lq.push(l);

	while (!lq.empty()) {
		if (lq.front() == 0)
			break;
		lp.push_back(lq.front());
		lq.push(map[lq.front()]);
		lq.pop();
	}

	rq.push(r);
	while (!rq.empty()) {
		if (rq.front() == 0)
			break;
		rp.push_back(rq.front());
		rq.push(map[rq.front()]);
		rq.pop();
	}
	int result = 0;
	
	int lcount = lp.size() - 1;
	int rcount = rp.size() - 1;

	while (1) {
		if (lp[lcount] == rp[rcount]) {
			result = lp[lcount];
			lcount--;
			rcount--;
		}
		else {
			break;
		}
	}
	

	return result;
}

int bfs2(int start) {
	queue<int> q;
	q.push(start);

	int count = 0;
	while (!q.empty()) {
		count++;
		for (int i = 0; i < vv[q.front()].size(); i++) {
			q.push(vv[q.front()][i]);
		}
		q.pop();
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int ii = 1; ii <= t; ii++) {
		int n, e, l, r, a, b;
		cin >> n >> e >> l >> r;

		for (int i = 1; i < MAX; i++) {
			map[i] = 0;
			vv[i].clear();
		}

		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			map[b] = a;
			vv[a].push_back(b);
		}

		a = bfs(l,r);
		int result = bfs2(a);
		cout << "#" << ii << " " << a << " " << result << endl;
	}

	return 0;
}