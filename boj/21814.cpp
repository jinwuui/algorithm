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

int sqrtn;

struct Mos {
	int s, e;

	Mos() {}
	Mos(int s1, int e1) {
		s = s1, e = e1;
	}

	bool operator <(const Mos &m) const {
		if (s / sqrtn != m.s / sqrtn) return s / sqrtn < m.s / sqrtn;
		return e < m.e;
	}
};

void debug(vector<int> &cnt) {
	for (int i = 0; i < cnt.size(); i++) {
		cout << cnt[i] << sp;
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	sqrtn = sqrt(n);
	vector<int> vis(n + 1, -1);
	vector<Mos> qry;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];

		if (vis[v[i]] != -1) {
			qry.push_back(Mos(vis[v[i]] + 1, i - 1));
		}
		vis[v[i]] = i;
	}
	for (int i = 0; i <= n; i++) {
		if (vis[i] == -1) continue;

		qry.push_back(Mos(vis[i] + 1, n - 1));
	}

	sort(qry.begin(), qry.end());

	vector<int> cnt(n + 1);
	int s = qry[0].s, e = qry[0].e;
	ll tcnt = 0, ans = 0;
	for (int i = s; i <= e; i++) {
		cnt[v[i]]++;
		if (cnt[v[i]] == 1) tcnt++;
	}
	ans += tcnt;
	// cout << s << sp << e << sp << tcnt << endl;
	// debug(cnt);
	for (int i = 1; i < qry.size(); i++) {
		
		while (qry[i].s < s) { s--; cnt[v[s]]++; if (cnt[v[s]] == 1) tcnt++; }
		while (qry[i].s > s) { cnt[v[s]]--; if (cnt[v[s]] == 0) tcnt--; s++; }
		while (qry[i].e < e) { cnt[v[e]]--; if (cnt[v[e]] == 0) tcnt--; e--; }
		while (qry[i].e > e) { e++; cnt[v[e]]++; if (cnt[v[e]] == 1) tcnt++; }
		// cout << s << sp << e << sp << tcnt << endl;
		// debug(cnt);
		ans += tcnt;
	}
	cout << ans;
	return 0;
}