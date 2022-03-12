#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
#define GAP first
#define SELL second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

int n1, n2;
int sum1, sum2;
vector<int> v1(20);
vector<int> v2(20);
vector<pii> ans1;
vector<pii> ans2;

void solve(int idx, int n, int gap, int sell, vector<pii> &ans, vector<int> &v) {
	if (idx == n) {
		// cout << gap << sp << sell << endl;
		ans.push_back({gap, sell});
		return;
	}

	// 잭이 집을 가짐
	solve(idx + 1, n, gap - v[idx], sell - v[idx], ans, v);

	// 질이 집을 가짐
	solve(idx + 1, n, gap + v[idx], sell - v[idx], ans, v);

	// 집을 팜
	solve(idx + 1, n, gap, sell, ans, v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (1) {
		int n;
		cin >> n;

		if (!n) break;

		n1 = n / 2;
		n2 = n / 2 + (n % 2);

		v1.clear(), v2.clear();
		ans1.clear(), ans2.clear();
		sum1 = 0, sum2 = 0;
		for (int i = 0; i < n1; i++) {
			cin >> v1[i];
			sum1 += v1[i];
		}
		for (int i = 0; i < n2; i++) {
			cin >> v2[i];
			sum2 += v2[i];
		}

		solve(0, n1, 0, sum1, ans1, v1);
		solve(0, n2, 0, sum2, ans2, v2);

		sort(ans2.begin(), ans2.end());
		// for (int i = 0; i < ans2.size(); i++) {
		// 	cout << ans2[i].GAP << sp << ans2[i].SELL << endl;
		// }

		int ans = 1e9;
		for (int i = 0; i < ans1.size(); i++) {
			int idx = lower_bound(ans2.begin(), ans2.end(), make_pair(-ans1[i].GAP, 0)) - ans2.begin();

			if (idx >= ans2.size()) continue;
			if (ans1[i].GAP + ans2[idx].GAP != 0) continue;

			ans = min(ans, ans1[i].SELL + ans2[idx].SELL);
			if (ans == 0) break;
		}

		cout << ans << endl;
	}
	
	return 0;
}