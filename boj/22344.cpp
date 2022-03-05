#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
#define C first
#define X second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	vector<pll> vis(n + 1); // first = C = 상수, second = X = x의 계수
	vector<vector<pii>> v(n + 1);
	vector<ll> ans(n + 1);
	pll ansX;

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;

		v[a].push_back({b, w});
		v[b].push_back({a, w});
	}

	queue<int> q;
	q.push(1);
	vis[1] = {0, 1};
	ans[1] = 0;

	while (q.size()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int nd = v[cur][i].first;
			int w = v[cur][i].second;

			if (vis[nd].C || vis[nd].X) {
				ll newX = vis[cur].X + vis[nd].X;
				ll newC = vis[cur].C + vis[nd].C;
				if (newX == 0) {
					if (newC != w) {
						cout << "No"; return 0;
					}
				} else {
					if ((w - newC) % newX) {
						cout << "No"; return 0;
					} else {
						ll tmp = (w - newC) / newX;
						if (ansX.second && ansX.first != tmp) {
							cout << "No"; return 0;
						} else {
							ansX = {tmp, 1};
						}
					}
				}
				continue;
			}

			vis[nd] = {w - vis[cur].C, -vis[cur].X};
			ans[nd] = (w - vis[cur].C) / vis[cur].X;
			q.push(nd);
		}
	}

	cout << "Yes" << endl;
	if (!ansX.second) {	
		sort(ans.begin() + 1, ans.end());
		ansX.first = ans[ans.size() / 2];
	}

	for (int i = 1; i <= n; i++) {
		cout << vis[i].C + vis[i].X * ansX.first << sp;
	}

	return 0;
}