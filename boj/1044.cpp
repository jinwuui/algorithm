#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
#define GAP first
#define MASK second
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, unsigned long long>;

int n;
vector<vector<pll>> v(40, vector<pll>());
vector<pll> ans2; // first = gap, second = mask

void output(ull m) {
	for (int i = n - 1; i >= 0; i--) {
		int mask;
		if (m & (1ULL << i)) mask = 2;
		else mask = 1;
		cout << mask << sp;
	}
}

void solve1(int cnt, ull mask, vector<ll> &ta, vector<ll> &tb) {
	if (cnt == n / 2) {
		ll gap = 0;
		int a = 0;
		for (int i = cnt - 1; i >= 0; i--) {
			if (mask & (1ULL << i))
				gap += tb[cnt - 1 - i];
			else
				gap -= ta[cnt - 1 - i], a++;
		}

		v[a].push_back({gap, mask});
		return;
	}

	solve1(cnt + 1, mask, ta, tb);

	mask |= (1 << cnt);
	solve1(cnt + 1, mask, ta, tb);
}

void solve2(int cnt, ull mask, vector<ll> &ta, vector<ll> &tb) {
	if (cnt == n / 2) {
		ll gap = 0;
		for (int i = cnt - 1; i >= 0; i--) {
			if (mask & (1ULL << i))
				gap += tb[cnt - 1 - i];
			else
				gap -= ta[cnt - 1 - i];
		}

		ans2.push_back({gap, mask});
		return;
	}

	solve2(cnt + 1, mask, ta, tb);

	mask |= (1 << cnt);
	solve2(cnt + 1, mask, ta, tb);
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

	solve1(0, 0, ta1, tb1);
	solve2(0, 0, ta2, tb2);

	for (int i = 0; i < 40; i++) {
		sort(v[i].begin(), v[i].end());
	}

	pll result = {numeric_limits<long long int>::max(), 0};
	for (int i = 0; i < ans2.size(); i++) {
		int b = 0;
		for (int j = 0; j < n / 2; j++)
			if (ans2[i].MASK & (1ULL << j)) b++;
	
		vector<pll> &ans1 = v[b];

		int idx = lower_bound(ans1.begin(), ans1.end(), make_pair(-ans2[i].GAP, (ull)0)) - ans1.begin();
		if (idx >= ans1.size()) idx--;

		ll gap = abs(ans1[idx].GAP + ans2[i].GAP);
		ull mask = (ans1[idx].MASK << (n / 2)) + ans2[i].MASK;
		
		if (idx > 0) {
			ll nGap = abs(ans1[idx - 1].GAP + ans2[i].GAP);
			if (gap >= nGap) {
				idx = lower_bound(ans1.begin(), ans1.end(), make_pair(ans1[idx - 1].GAP, (ull)0)) - ans1.begin();
				if (gap > nGap) mask = (ans1[idx].MASK << (n / 2)) + ans2[i].MASK;
				else mask = min(mask, (ans1[idx].MASK << (n / 2)) + ans2[i].MASK);
				gap = nGap;
			}
		}

		if (result.GAP > gap) {
			result = {gap, mask};
		} else if (result.GAP == gap && result.MASK > mask) {
			result.second = mask;
		}
	}

	output(result.MASK);

	return 0;
}