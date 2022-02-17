#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pii> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first;
		v[i].second = i - 1;
	}
	sort(v.begin(), v.end());

	vector<int> dp(n + 1);
	vector<vector<int>> tdp(n + 1, vector<int>());
	tdp[1].push_back(v[1].second);
	tdp[2].push_back(v[1].second);
	tdp[2].push_back(v[2].second);
	int maxv = -1e9;
	int sum = 0;
	for (int i = 4; i <= n; i++) {
		int gap = v[i].first - v[i - 3].first;

		if (i % 4) {
			dp[i] = min(dp[i - 1], dp[i - 4] + gap);
			
			if (dp[i] == dp[i - 1]) {
				for (int j = 0; j < tdp[i - 1].size(); j++) {
					tdp[i].push_back(tdp[i - 1][j]);
				}
				tdp[i].push_back(v[i].second);
			} else {
				for (int j = 0; j < tdp[i - 4].size(); j++) {
					tdp[i].push_back(tdp[i - 4][j]);
				}
			}
		} else {
			dp[i] = dp[i - 4] + gap;
		}
	}

	cout << dp[n] << endl;
	if (n % 4)
		for (int i = 0; i < tdp[n].size(); i++)
			cout << tdp[n][i] << endl;
	
	return 0;
}