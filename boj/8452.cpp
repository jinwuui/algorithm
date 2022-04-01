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

int n, m, q;
vector<vector<int>> adj(1111, vector<int>());
vector<int> vis(1111, -1);

void bfs(int s) {
	queue<int> q;
	q.push(s);
	while (q.size()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < adj[cur].size(); i++) {
			int nx = adj[cur][i];

			if (vis[nx] != -1 && vis[nx] <= vis[cur] + 1) continue;

			vis[nx] = vis[cur] + 1;
			q.push(nx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;

	pii edge[m + 1];
	vector<int> noedge(m + 1);
	for (int i = 1; i <= m; i++)
		cin >> edge[i].first >> edge[i].second;

	vector<pair<char, int>> qry(q);
	for (int i = 0; i < q; i++) {
		cin >> qry[i].first >> qry[i].second;
		if (qry[i].first == 'U') noedge[qry[i].second] = 1;
	}

	for (int i = 1; i <= m; i++) {
		if (noedge[i]) continue;
		adj[edge[i].first].push_back(edge[i].second);
	}

	vis[1] = 0;
	bfs(1);

	vector<int> ans;
	for (int i = qry.size() - 1; i >= 0; i--) {
		char c = qry[i].first;
		int num = qry[i].second;

		if (c == 'E') {
			ans.push_back(vis[num]);
		} else {
			int s = edge[num].first, e = edge[num].second;
			adj[s].push_back(e);
			if (vis[s] != -1) {
				if (vis[s] + 1 < vis[e] || vis[e] == -1) {
					vis[e] = vis[s] + 1;
					bfs(e);
				}
			}
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	
	return 0;
}