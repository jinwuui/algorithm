
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
vector<vector<int>> v(555, vector<int>(555)), dp(555, vector<int>(555, -1));

int dfs(pii cur) {
	dp[cur.R][cur.C] = 0;
	for (int i = 0; i < 4; i++) {
		int nr = cur.R + dr[i];
		int nc = cur.C + dc[i];

		if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
		if (v[nr][nc] <= v[cur.R][cur.C]) continue;

		if (dp[nr][nc] != -1) dp[cur.R][cur.C] += dp[nr][nc];
		else if (nr == 0 && nc == 0) dp[cur.R][cur.C] += 1;
		else dp[cur.R][cur.C] += dfs({nr, nc});
	}
	return dp[cur.R][cur.C];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> v[i][j];

	cout << dfs({n - 1, m - 1});

	return 0;
}