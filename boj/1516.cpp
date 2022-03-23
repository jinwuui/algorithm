#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n), cnt(n);
	vector<vector<int>> adj(555, vector<int>());
	for (int i = 0; i < n; i++) {
		cin >> v[i];

		while (1) {
			int prev; cin >> prev;
			if (prev == -1) break;
			adj[--prev].push_back(i);
			cnt[i]++;
		}
	}
	queue<int> q;
	vector<int> ret(n);
	for (int i = 0; i < n; i++)
		if (cnt[i] == 0) {
			ret[i] = v[i];
			q.push(i);
		}

	while (q.size()) {
		int cur = q.front(); q.pop();
		
		for (int i = 0; i < adj[cur].size(); i++) {
			int nx = adj[cur][i];
			ret[nx] = max(ret[nx], ret[cur] + v[nx]);
			if (--cnt[nx] == 0) q.push(nx);
		}
	}
	for (int i = 0; i < n; i++)
		cout << ret[i] << endl;
	return 0;
}