#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n), cnt(n), ans(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<vector<int>> adj(2000);
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			--a, --b;
			adj[a].push_back(b);
			cnt[b]++;
		}
		int w;
		cin >> w;
		--w;

		queue<int> q;
		for (int i = 0; i < n; i++)
			if (cnt[i] == 0) {
				q.push(i);
				ans[i] = v[i];
			}

		while (q.size()) {
			int cur = q.front(); q.pop();

			for (int i = 0; i < adj[cur].size(); i++) {
				int nx = adj[cur][i];
				ans[nx] = max(ans[nx], ans[cur] + v[nx]);
				if (--cnt[nx] == 0) {
					q.push(nx);
				}
			}
		}

		cout << ans[w] << endl;
	}
	
	return 0;
}