#include <bits/stdc++.h>
#define MX first
#define INFO second
#define I first
#define CNT second
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

int n, m, k, sgsize = 1;
priority_queue<ll> pq[111111];
pair<ll, pii> sg[555555];

void debug() {
	int cnt = 1;
	for (int i = 1; i <= 7; i++) {
		cout << "(" << sg[i].MX << ", " << sg[i].INFO.I << ", " << sg[i].INFO.CNT << ")" << sp;
		if (i == pow(2, cnt) - 1) {
			cout << endl;
			cnt++;
		}
	}
	cout << endl;
}

void debug2() {
	for (int i = 1; i <= n; i++) {
		if (pq[i].size())
			cout << pq[i].top() << sp;
		else
			cout << "-" << sp;
	}
	cout << endl;
}

void insert(int idx, ll val) {
	pq[idx].push(val);
	int i = idx + sgsize - 1;
	sg[i] = {max(sg[i].MX, val), {idx, sg[i].INFO.CNT + 1}};
	while (i > 1) {
		int prev = i;
		i /= 2;
		sg[i].INFO.CNT++;
		if (sg[i].MX < sg[prev].MX) {
			sg[i].MX = sg[prev].MX;
			sg[i].INFO.I = sg[prev].INFO.I;
		}
	}
}

void remove(int t, int l, int r, ll h) {
	while (sg[1].first > h - t * k) {
		int idx = sg[1].INFO.I;
		int cnt = 0;
		while (pq[idx].size() && pq[idx].top() > h - t * k) {
			pq[idx].pop();
			cnt++;
		}

		int i = idx + sgsize - 1;
		sg[i] = {pq[idx].size() ? pq[idx].top() : -1e18, {idx, sg[i].INFO.CNT - cnt}};
		while (i > 1) {
			int prev = i;
			i /= 2;
			sg[i].INFO.CNT -= cnt;
			if (sg[i * 2].MX < sg[i * 2 + 1].MX) {
				sg[i].MX = sg[i * 2 + 1].MX;
				sg[i].INFO.I = sg[i * 2 + 1].INFO.I;
			} else {
				sg[i].MX = sg[i * 2].MX;
				sg[i].INFO.I = sg[i * 2].INFO.I;
			}
		}
	}
}

pair<ll, int> findMax(int l, int r, int cur, int curl, int curr) {
	if (r < curl || l > curr) return {-1e18, 0};
	if (l <= curl && curr <= r) return sg[cur].INFO.CNT;
	int mid = (curl + curr) / 2;
	return max(findMax(l, r, cur * 2, curl, mid), findMax(l, r, cur * 2 + 1, mid + 1, curr));
}

int findSum(int l, int r, int cur, int curl, int curr) {
	if (r < curl || l > curr) return 0;
	if (l <= curl && curr <= r) return sg[cur].INFO.CNT;
	int mid = (curl + curr) / 2;
	return findSum(l, r, cur * 2, curl, mid) + findSum(l, r, cur * 2 + 1, mid + 1, curr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	while (sgsize < n) sgsize *= 2;

	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 1) {
			ll t, x, h;
			cin >> t >> x >> h;
			insert(x, h - t * k);
		} else  if (tmp == 2) {
			ll t, l, r, h;
			cin >> t >> l >> r >> h;
			remove(l, r, 1, 1, n);
		} else {
			ll t, l, r;
			cin >> t >> l >> r;
			cout << findSum(l, r, 1, 1, n) << endl; 
		}
	}
	
	return 0;
}