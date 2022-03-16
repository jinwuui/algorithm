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

int v, e;
vector<int> buf[11111];
vector<int> rev[11111];
vector<int> vis(11111);
vector<vector<int>> ans(11111, vector<int>());
stack<int> stk;

void dfs(int s) {

	for (int i = 0; i < buf[s].size(); i++) {
		int cur = buf[s][i];
		rev[cur].push_back(s);
		if (vis[cur]) continue;
		vis[cur] = 1;

		dfs(cur);
	}

	stk.push(s);
}

void dfs2(int s, vector<int> &ans) {
	ans.push_back(s);

	for (int i = 0; i < rev[s].size(); i++) {
		int cur = rev[s][i];
		if (vis[cur]) continue;

		vis[cur] = 1;
		dfs2(cur, ans);
	}
}

bool comp(vector<int> &v1, vector<int> &v2) {
	if (v1.empty()) return false;
	if (v2.empty()) return true;

	return v1[0] < v2[0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		buf[a].push_back(b);
	}
	
	for (int i = 1; i <= v; i++) {
		if (vis[i]) continue;

		vis[i] = 1;
		dfs(i);
	}

	fill(vis.begin(), vis.end(), 0);
	int cnt = 0;
	while (stk.size()) {
		int s = stk.top();
		stk.pop();

		if (vis[s]) continue;

		vis[s] = 1;
		dfs2(s, ans[s]);
		cnt++;
	}

	for (int i = 1; i <= v; i++) {
		if (ans[i].empty()) continue;
		sort(ans[i].begin(), ans[i].end());
	}

	sort(ans.begin(), ans.end(), comp);

	cout << cnt << endl;
	for (int i = 0; i < v; i++) {
		if (ans[i].empty()) break;
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << sp;
		}
		cout << -1 << endl;
	}

	return 0;
}