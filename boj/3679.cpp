#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '

using namespace std;
using ll = long long;
struct Dot {
	ll x, y, p, q;
	Dot() {}
	Dot(int nx, int ny) {
		x = nx, y = ny, p = 0, q = 0;
	}
};

vector<pair<Dot, int>> buf;
bool comp(pair<Dot, int> &a, pair<Dot, int> &b) {
	Dot d1 = a.first, d2 = b.first;
	if (d1.y != d2.y) return d1.y < d2.y;
	return d1.x < d2.x;
}

ll ccw(Dot &a, Dot &b, Dot &c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool comp2(pair<Dot, int> &a, pair<Dot, int> &b) {
	Dot d = buf[0].first, d1 = a.first, d2 = b.first;
	ll ret = ccw(d, d1, d2);
	if (ret != 0) return ret > 0;
	return hypot(1.0*d1.x - d.x, 1.0*d1.y - d.y) < hypot(1.0*d2.x - d.x, 1.0*d2.y - d.y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		buf.resize(n);
		for (int i = 0; i < n; i++) {
			int x, y; cin >> x >> y;
			buf[i] = {Dot(x, y), i};
		}
		sort(buf.begin(), buf.end(), comp);
		for (int i = 1; i < n; i++) {
			buf[i].first.p = buf[i].first.x - buf[0].first.x;
			buf[i].first.q = buf[i].first.y - buf[0].first.y;
		}
		sort(buf.begin() + 1, buf.end(), comp2);

		int idx = n - 1;
		while (ccw(buf[0].first, buf[idx].first, buf[idx - 1].first) == 0) idx--;
		reverse(buf.begin() + idx, buf.end());
		for (int i = 0; i < n; i++) {
			cout << buf[i].second << sp;
		}
		cout << endl;
	}
	return 0;
}