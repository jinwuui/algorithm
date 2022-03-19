#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	sqrtn = sqrt(n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> cnt(n + 10);
	int s = 0, e = 1;
	ll ans = 0;
	cnt[v[0]]++, cnt[v[1]]++;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int ns = i, ne = j;
			while (ns < s) s--, cnt[v[s]]++;
			while (ns > s) cnt[v[s]]--, s++;
			while (ne < e) cnt[v[e]]--, e--;
			while (ne > e) e++, cnt[v[e]]++;

			if (cnt[v[s]] == 1 && cnt[v[e]] == 1) ans++;
		}
	}
	
	cout << ans;
	return 0;
}