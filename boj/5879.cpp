#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
#define MILK first
#define MASK second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

int n;
int n1, n2;
vector<int> v1(20);
vector<int> v2(20);
vector<pii> ans1;
vector<pii> ans2;
int vis[1111111];

void solve(int mask, int idx, int len, int milk, vector<int> &v, vector<pii> &ans) {
	if (idx == len) {
		ans.push_back({milk, mask});
		return;
	}

	int nMask = mask | (1 << idx);
	solve(nMask, idx + 1, len, milk + v[len - idx - 1], v, ans);
	solve(mask, idx + 1, len, milk, v, ans);
	solve(nMask, idx + 1, len, milk - v[len - idx - 1], v, ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	n1 = n / 2;
	n2 = n - n1;
	
	for (int i = 0; i < n1; i++)
		cin >> v1[i];
	for (int i = 0; i < n2; i++)
		cin >> v2[i];

	solve(0, 0, n1, 0, v1, ans1);
	solve(0, 0, n2, 0, v2, ans2);

	int ans1len = ans1.size() / 2 + 1;
	sort(ans2.begin(), ans2.end());
    
	ll ret = 0;
	for (int i = 0; i < ans1len; i++) {
		int s = lower_bound(ans2.begin(), ans2.end(), make_pair(-ans1[i].MILK, 0)) - ans2.begin();
		int e = upper_bound(ans2.begin(), ans2.end(), make_pair(-ans1[i].MILK, (int)1e9)) - ans2.begin();

		for (; s < e; s++) {
			int tmp = (ans1[i].MASK << n2) + ans2[s].MASK;
			if (vis[tmp]) continue;

			vis[tmp]++;
			ret++;
		}
	}

	cout << ret - 1;

	return 0;
}
