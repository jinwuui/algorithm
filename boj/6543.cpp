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
vector<vector<int>> eg(111111, vector<int>());
vector<vector<int>> ge(111111, vector<int>());
stack<int> stk;

void dfs(int s) {
	for (int i = 0; i < eg[s].size(); i++) {
		int cur = eg[s][i];
		ge[cur].push_back(s);
		
		if (vis[cur]) continue;

		vis[cur] = 1;
		dfs(s);
	}

	stk.push(s);
}

int first;
bool isOk;
void dfs2(int s) {
	for (int i = 0; i < ge[s].size(); i++) {
		int cur = ge[s][i];

		if (first == cur) isOk = true;
		if (vis[cur]) continue;

		vis[cur] = 1;
		dfs2(s);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	while (1) {
		cin >> n;
		if (n == 0) break;
		cin >> m;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;

			eg[a].push_back(b);
		}

		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;

			vis[i] = 1;
			dfs(i);
		}
		
		vector<int> ans(n + 1);
		iota(ans.begin(), ans.end(), 0);
		// for (int i = 0; i < ans.size(); i++) {
		// 	cout << ans[i] << sp;
		// }
		// cout << endl;
		while (stk.size()) {
			fill(vis.begin(), vis.end(), 0);
			int s = stk.top();
			cout << "s " << s << endl;
			stk.pop();

			if (vis[s]) continue;

			first = s;
			isOk = false;
			vis[s] = 1;
			dfs2(s);

			if (isOk == false) {
				ans[s] = 0;
			}
		}

		sort(ans.begin(), ans.end());
		for (int i = 1; i <= n; i++) {
			if (ans[i]) cout << i << sp;
		}
		cout << endl;
	}
	return 0;
}