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
	bool operator <(const Dot &d) const {
		if (q * d.p != d.q * p) return q * d.p < d.q * p;
		if (y != d.y) return y < d.y;
		return x < d.x;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<Dot, int>> buf(n);
		for (int i = 0; i < n; i++) {
			int x, y; cin >> x >> y;
			buf[i] = {Dot(x, y), i};
		}
		sort(buf.begin(), buf.end());
		for (int i = 1; i < n; i++) {
			buf[i].first.p = buf[i].first.x - buf[0].first.x;
			buf[i].first.q = buf[i].first.y - buf[0].first.y;
		}
		sort(buf.begin() + 1, buf.end());

		for (int i = 0; i < n; i++) {
			cout << buf[i].second << sp;
		}
		cout << endl;
	}
	return 0;
}