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

int n, t, sqrtn;
vector<ll> v;
vector<ll> cnt(1111111);

struct Unit {
	int s, e, n;
	ll sum;

	Unit() {}
	Unit(int ss, int ee, int nn) {
		s = ss;
		e = ee;
		n = nn;
		sum = 0;
	}

	bool operator <(const Unit &u) const {
		if (s / sqrtn != u.s / sqrtn) return s / sqrtn < u.s / sqrtn;
		return e < u.e;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t;
	sqrtn = sqrt(n);
	v.resize(n);
	for (int i = 0; i < n; i++) {
		ll tmp; cin >> tmp;
		v[i] = tmp;
	}

	Unit q[t];
	for (int i = 0; i < t; i++) {
		int s, e;
		cin >> s >> e;
		q[i] = Unit(--s, --e, i);
	}

	sort(q, q + t);

	int s = q[0].s, e = q[0].e;
	vector<ll> result(t);
	for (int i = s; i <= e; i++) {
		int cur = v[i];
		q[0].sum -= cnt[cur] * cnt[cur] * cur;
		cnt[cur]++;
		q[0].sum += cnt[cur] * cnt[cur] * cur;
	}
	result[q[0].n] = q[0].sum;

	for (int i = 1; i < t; i++) {
		while (q[i].s < s) {
			s--;
			int cur = v[s];
			q[i].sum -= cnt[cur] * cnt[cur] * cur;
			cnt[cur]++;
			q[i].sum += cnt[cur] * cnt[cur] * cur;
		}

		while (q[i].s > s) {
			int cur = v[s];
			q[i].sum -= cnt[cur] * cnt[cur] * cur;
			cnt[cur]--;
			q[i].sum += cnt[cur] * cnt[cur] * cur;
			s++;
		}

		while (q[i].e > e) {
			e++;
			int cur = v[e];
			q[i].sum -= cnt[cur] * cnt[cur] * cur;
			cnt[cur]++;
			q[i].sum += cnt[cur] * cnt[cur] * cur;
		}

		while (q[i].e < e) {
			int cur = v[e];
			q[i].sum -= cnt[cur] * cnt[cur] * cur;
			cnt[cur]--;
			q[i].sum += cnt[cur] * cnt[cur] * cur;
			e--;
		}

		q[i].sum += q[i - 1].sum;
		result[q[i].n] = q[i].sum;
	}

	for (int i = 0; i < t; i++) {
		cout << result[i] << endl;
	}

	return 0;
}