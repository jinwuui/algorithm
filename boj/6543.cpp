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

int n, m;
vector<int> vis(5555);

void dfs(int s, vector<vector<int>> &edge, vector<vector<int>> &rev, stack<int> &stk) {
	for (int i = 0; i < edge[s].size(); i++) {
		int cur = edge[s][i];
		rev[cur].push_back(s);
		
		if (vis[cur]) continue;

		vis[cur] = 1;
		dfs(cur, edge, rev, stk);
	}

	stk.push(s);
}

void dfs2(int boss, int s, vector<vector<int>> &rev, vector<int> &ans) {
	for (int i = 0; i < rev[s].size(); i++) {
		int cur = rev[s][i];

		if (vis[cur] == boss) ans[cur]++;
		if (vis[cur]) continue;

		vis[cur] = boss;
		ans[cur]++;
		dfs2(boss, cur, rev, ans);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	while (1) {
		cin >> n;
		if (n == 0) break;
		fill(vis.begin(), vis.end(), 0);
		cin >> m;

		vector<vector<int>> edge(n + 1, vector<int>());
		vector<vector<int>> rev(n + 1, vector<int>());
		stack<int> stk;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;

			edge[a].push_back(b);
		}

		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;

			vis[i] = 1;
			dfs(i, edge, rev, stk);
		}
		
		fill(vis.begin(), vis.end(), 0);
		vector<int> ans(n + 1, 0);
		while (stk.size()) {
			int s = stk.top(); stk.pop();

			if (vis[s]) continue;

			vis[s] = s;
			dfs2(s, s, rev, ans);
		}

		set<int> fail;
		for (int i = 1; i <= n; i++) {
			if (ans[i] != edge[i].size()) fail.insert(vis[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (fail.find(vis[i]) == fail.end()) cout << i << sp;
		}
		cout << endl;
	}
	return 0;
}