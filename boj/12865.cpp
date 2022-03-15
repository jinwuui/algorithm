#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
#define W first
#define V second
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<pii> v(n);
	vector<int> vis(111111);
	vector<vector<pii>> dp(n, vector<pii>());
	for (int i = 0; i < n; i++) {
		cin >> v[i].W >> v[i].V;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		pii cur = v[i];

		for (int j = 0; j < i; j++) {
			for (int ii = 0; ii < dp[j].size(); ii++) {
				if (dp[j][ii].W + cur.W <= k && vis[dp[j][ii].W + cur.W] < dp[j][ii].V + cur.V) {
					dp[i].push_back({dp[j][ii].W + cur.W, dp[j][ii].V + cur.V});
					vis[dp[j][ii].W + cur.W] = dp[j][ii].V + cur.V;
				}
			}
		}
		dp[i].push_back({cur.W, cur.V});
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < dp[i].size(); j++) {
			ans = max(ans, dp[i][j].V);
		}
	}
	cout << ans;

	return 0;
}