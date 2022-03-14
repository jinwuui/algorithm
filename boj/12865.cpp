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

	pii buf[n];
	for (int i = 0; i < n; i++) {
		cin >> buf[i].W >> buf[i].V;
	}
	sort(buf, buf + n);

	vector<int> dp(100100);
	for (int i = 0; i < n; i++)
		for (int j = 0; j + buf[i].W <= k; j++)
			dp[j + buf[i].W] = max(dp[j + buf[i].W], dp[j] + buf[i].V);

	cout << *max_element(dp.begin(), dp.end());

	return 0;
}