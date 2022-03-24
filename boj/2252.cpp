#include <bits/stdc++.h>
#define R first
#define C second
#define W first
#define ND second
#define endl '\n'
#define sp ' '
#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, start, n) for (int i = start; i < (n); i++)
#define all(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};
const int MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(33333, vector<int>());
	vector<int> ind(n), ans;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[--a].push_back(--b);
		ind[b]++;
	}
	
	queue<int> q;
	for (int i = 0; i < n; i++)
		if (ind[i] == 0)
			q.push(i);

	while (q.size()) {
		int cur = q.front(); q.pop();
		ans.push_back(cur);
		for (int i = 0; i < adj[cur].size(); i++) {
			int nx = adj[cur][i];
			if (--ind[nx] == 0) q.push(nx);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] + 1 << sp;
	}
	return 0;
}