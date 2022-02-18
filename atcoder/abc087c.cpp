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
	vector<vector<int>> dp(2 + 1, vector<int>(n + 1));

	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dp[i][j];
			dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[2][n];

	return 0;
}