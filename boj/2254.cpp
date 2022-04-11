#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '

using namespace std;
using ll = long long;
struct dot {
	ll x, y, p, q;
	dot() {}
	dot(ll nx, ll ny) {
		x = nx, y = ny, p = 0, q = 0;
	}

	bool operator < (const dot &d) const {
		if (q * d.p != d.q * p) return q * d.p < d.q * p;
		if (y != d.y) return y < d.y;
		return x < d.x;
	}
};

int n, cnt = 0;
dot prison;

ll ccw(dot &s, dot &e, dot &nx) {
	return (e.x - s.x) * (nx.y - s.y) - (e.y - s.y) * (nx.x - s.x);
}

bool isOk(vector<dot> &v, vector<int> &hull) {
	hull.push_back(hull[0]);
	for (int i = 0; i < hull.size() - 1; i++) {
		int s = hull[i], e = hull[i + 1];
		if (ccw(v[s], v[e], prison) <= 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> prison.x >> prison.y;

	vector<dot> buf(n);
	vector<int> vis(n);
	for (int i = 0; i < n; i++) {
		cin >> buf[i].x >> buf[i].y;
	}

	while (true) {
		vector<dot> v;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) v.push_back(buf[i]);
		}

		sort(v.begin(), v.end());
		for (int i = 1; i < n; i++) {
			v[i].p = v[i].x - v[0].x;
			v[i].q = v[i].y - v[0].y;
		}
		sort(v.begin() + 1, v.end());

		stack<int> stk;
		stk.push(0);
		stk.push(1);
		
		for (int nx = 2; nx < n; nx++) {
			while (stk.size() > 1) {
				int e = stk.top();
				stk.pop();
				int s = stk.top();

				if (ccw(v[s], v[e], v[nx]) > 0) {
					stk.push(e);
					break;
				}
			}
			stk.push(nx);
		}

		vector<int> hull;
		while (stk.size()) {
			hull.push_back(stk.top());
			vis[stk.top()] = 1;
			stk.pop();
		}
		reverse(hull.begin(), hull.end());
		// for (int i = 0; i < hull.size(); i++) cout << hull[i] << sp;
		// cout << endl;
		if (isOk(v, hull)) cnt++;
		else break;
	}
	cout << cnt;
	return 0;
}