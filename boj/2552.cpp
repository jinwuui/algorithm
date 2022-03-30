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

int n, k;
vector<pii> buf, mnot;
vector<int> lnot , rnot, lm, rm;

void debug(int m, int len) {
	for (int i = len - 1; i >= 0; i--) {
		if (m & (1 << i)) cout << 1 << sp;
		else cout << 0 << sp;
	}
}

void solve(int mask, int cnt, int len, vector<int> &v, vector<int> &m) {
	if (cnt == len) {
		debug(mask, len);
		for (int i = 0; i < v.size(); i++) {
			if ((v[i] & mask) == v[i]) {
				cout << "	not use" << endl;
				return;
			}
		}
		cout << "	use" << endl;
		m.push_back(mask);
		return;
	}

	solve(mask, cnt + 1, len, v, m);
	mask |= (1 << (len - cnt - 1));
	solve(mask, cnt + 1, len, v, m);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	buf.resize(n);
	for (int i = n - 1; i >= 0; i--) {
		int tmp; cin >> tmp;
		buf[i] = {tmp, i};
		cout << tmp << ", " << i << endl;
	}
	cin >> k;
	sort(buf.begin(), buf.end());
	cout << "--d-fs-df-s" << endl;

	// pii cur = buf[0];
	for (int i = 0; i < n - 1; i++) {
		pii cur = buf[i];
		for (int j = i + 1; j < n; j++) {
			pii comp = buf[j];
			if (cur.second < comp.second) {
				cout << cur.first << "," << cur.second << "    " << comp.first << "," << comp.second << endl;
				int lval = max(cur.second, comp.second), rval = min(cur.second, comp.second), half = n - n / 2;
			
				if (lval >= half && rval >= half) { // lnot
					lnot.push_back((1 << (lval - half)) | (1 << (rval - half)));
				} else if (lval < half && rval < half) { // rnot
					rnot.push_back((1 << lval) | (1 << rval));
				} else { // mnot
					mnot.push_back({1 << lval, 1 << rval});
				}
			} else
				cur = comp;
		}
		// pii comp = buf[i];
		
	}

	cout << "l mask " << lnot.size() << endl;
	for (int i = 0; i < lnot.size(); i++) {
		debug(lnot[i], n / 2);
	}
	cout << endl;
	cout << "r mask " << rnot.size() << endl;
	for (int i = 0; i < rnot.size(); i++) {
		debug(rnot[i], n - n / 2);
	}
	cout << "- - - -- \n";
		cout << "m mask " << mnot.size() << endl;
	for (int i = 0; i < mnot.size(); i++) {
		cout << mnot[i].first << sp << mnot[i].second << endl;
		int mask = mnot[i].first + mnot[i].second;
		debug(mask, n);
		// debug(mnot[i].first, n / 2);
		// debug(mnot[i].second, n - n / 2);
	}
	cout << "- - - -- \n";
	solve(0, 0, n / 2, lnot, lm);
	// cout << " &^%*&^%*^%$%(&*^()*&^6" << endl;
	solve(0, 0, n - n / 2, rnot, rm);

	int ans = 0;
	for (int i = 0; i < lm.size(); i++) {
		int cnt = rm.size();
		cout << "cnt " << cnt << endl;
		for (int j = 0; j < mnot.size(); j++) {
			if ((mnot[j].first & lm[i]) == mnot[j].first) {
				// cout << "checkmate" << endl;
				int s = mnot[j].second, e = 0, idx = 0;
				while (!(s & e)) {
					e |= (1 << idx++);
				}

				cnt -= (upper_bound(rm.begin(), rm.end(), e) - lower_bound(rm.begin(), rm.end(), s));
				// cout << "cnt " << cnt << endl;
			}
		}
		if (ans + cnt >= k) {
			int llen, rlen;
			llen = n / 2;
			rlen = n - llen;
			for (int ii = 0; ii < rm.size(); ii++) {
				int mask = (lm[i] << (n - n / 2)) | rm[ii];
				cout << " testteset ";
				debug(lm[i], n / 2);
				cout << endl;
				cout << " testteset2 ";
				debug(mask, n);
				cout << endl;
				// cout << "mask " << mask << " lm[i] " << lm[i] << " rm[ii] " << rm[ii] <<  endl;
				// debug(lm[i], n / 2);
				// debug(rm[ii], n - n / 2);
				// cout << endl;
				bool isOk = true;
				for (int jj = 0; jj < mnot.size(); jj++) {
					int cant = mnot[jj].first | mnot[jj].second;
					cout << "cant -==-=-=-";
					debug(cant, n);
					cout << endl;
					if ((mask & cant) == cant) {
						isOk = false;
						break;
					}
				}
				if (isOk) {
					ans++;
					debug(mask, n);
					cout << endl;
					if (ans == k) {
						cout << "mask " << mask << endl;
						return 0;
					}
				}
			}
		} else ans += cnt;
		// cout << "ans " << ans << endl;

	}

	cout << -1;
	// cout << ans;
	return 0;
}
/*
7
2 1 3 5 6 4 7
6

*/