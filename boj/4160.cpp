#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
#define C first
#define X second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

int n;
map<ll, pll> mp1;

void output(ll m) {
	for (int i = n - 1; i >= 0; i--) {
		int mask;
		if (m & (1 << i)) mask = 2;
		else mask = 1;
		cout << mask << sp;
	}
}

void debug(ll m) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		int mask;
		if (m & (1 << i)) mask = 2;
		else mask = 1;
		cout << mask << sp;
	}
}

void solve1(ll mask, int cnt, vector<ll> &ta, vector<ll> &tb, vector<ll> &ans) {
	if (cnt == n / 2) {
		ll gap = 0;
		for (int i = 0; i < cnt; i++) {
			if (mask & (1 << i)) {
				gap += tb[i];
			}
			else  {
				gap -= ta[i];
			}
		}

		ans.push_back(gap);
		if (mp1[gap].second == 0 || mp1[gap].first > mask)
			mp1[gap] = {mask, 1};

		return;
	}

	solve1(mask, cnt + 1, ta, tb, ans);

	mask = mask | (1 << cnt);
	solve1(mask, cnt + 1, ta, tb, ans);
}

void solve2(ll mask, ll cnt, vector<ll> &ta, vector<ll> &tb, vector<pll> &ans) {
	if (cnt == n / 2) {
		ll gap = 0;
		for (int i = 0; i < cnt; i++) {
			if (mask & (1 << i))
				gap += tb[i];
			else 
				gap -= ta[i];
		}

		ans.push_back({gap, mask});
		return;
	}

	solve2(mask, cnt + 1, ta, tb, ans);

	mask = mask | (1 << cnt);
	solve2(mask, cnt + 1, ta, tb, ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;

	vector<ll> ta1(n / 2);
	vector<ll> tb1(n / 2);
	vector<ll> ta2(n / 2);
	vector<ll> tb2(n / 2);
	for (int i = 0; i < n / 2; i++)
		cin >> ta1[i];
	for (int i = 0; i < n / 2; i++)
		cin >> ta2[i];

	for (int i = 0; i < n / 2; i++)
		cin >> tb1[i];
	for (int i = 0; i < n / 2; i++)
		cin >> tb2[i];

	vector<ll> ans1;
	vector<pll> ans2;
	solve1(0, 0, ta1, tb1, ans1);
	solve2(0, 0, ta2, tb2, ans2);

	cout << "- - - - -- " << endl;
	sort(ans1.begin(), ans1.end());
	for (int i = 0; i < ans1.size(); i++) {
		cout << ans1[i] << ":   ";
		debug(mp1[ans1[i]].first);
		cout << endl;
	}
	cout << "- - - - -- " << endl;

	pair<ll, ll> result;
	result.first = numeric_limits<long long int>::max();
	cout << result.first << endl;
	for (int i = 0; i < ans2.size(); i++) {
		int idx = lower_bound(ans1.begin(), ans1.end(), -ans2[i].first) - ans1.begin();

		if (idx >= ans1.size()) continue;

		cout << "ans2 : " << ans2[i].first << " vs " << "ans1 : " << ans1[idx] << endl;

		ll gap = abs(ans2[i].first + ans1[idx]);
		ll mask = mp1[ans1[idx]].first << (n / 2) | ans2[i].second;

		cout << "gap " << gap << endl;
		output(mask);
		cout << endl;
 
		if (gap == 0) {
			output(mask);
			cout << endl;
			return 0;
		} else {
			if (idx > 0 && gap > abs(ans2[i].first + ans1[idx - 1])) {
				cout << "	gap : " << gap << endl;
				output(mask); cout << endl;
				idx--;
				gap = abs(ans2[i].first + ans1[idx]);
				mask = mp1[ans1[idx]].first << (n / 2) | ans2[i].second;
			}

			if (result.first > gap) {
				// cout << "	gap: " << 
				result = {gap, mask};
			} else if (result.first == gap && result.second > mask) {
				cout << "	";
				output(result.second);
				cout << " vs ";
				output(mask);
				cout << endl;
				result.second = mask;
			}
		}
	}

	output(result.second);

	return 0;
}