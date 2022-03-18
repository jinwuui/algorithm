#include <bits/stdc++.h>
#define ATM first
#define RES second
#define endl '\n'
#define sp ' '

using namespace std;
using pii = pair<int, int>;

vector<vector<int>> rev(500100);
vector<vector<int>> v(500100);
vector<pii> nd(500100);
vector<int> vis(500100);
stack<int> stk;

void scc(int s) {
	for (int i = 0; i < v[s].size(); i++) {
		int cur = v[s][i];
		rev[cur].push_back(s);
		if (vis[cur]) continue;
		vis[cur] = 1;
		scc(cur);
	}
	stk.push(s);
}

void scc2(int s, vector<int> &group, int idx, vector<int> &grplist) {
	group[s] = idx;
	grplist.push_back(s);

	for (int i = 0; i < rev[s].size(); i++) {
		int cur = rev[s][i];
		if (vis[cur]) continue;
		vis[cur] = 1;
		scc2(cur, group, idx, grplist);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, start, p;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[--a].push_back(--b);
	}
	for (int i = 0; i < n; i++) {
		cin >> nd[i].ATM;
	}
	cin >> start >> p;
	--start;
	for (int i = 0; i < p; i++) {
		int tmp; cin >> tmp;
		nd[--tmp].RES = 1;
	}

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;

		vis[i] = 1;
		scc(i);
	}

	fill(vis.begin(), vis.end(), 0);

	vector<int> group(n + 1, -1);
	vector<vector<int>> grplist(n + 1, vector<int>());
	int idx = 0;
	while (stk.size()) {
		int s = stk.top(); stk.pop();
		if (vis[s]) continue;

		vis[s] = 1;
		scc2(s, group, idx, grplist[idx]);
		idx++;
	}

	vector<vector<int>> gv(idx + 1);
	vector<pii> gnd(idx + 1);
	for (int i = 0; i < idx; i++) {
		for (int j = 0; j < grplist[i].size(); j++) {
			int node = grplist[i][j];
			gnd[i].ATM += nd[node].ATM;
			gnd[i].RES += nd[node].RES;
			for (int k = 0; k < v[node].size(); k++) {
				int cur = v[node][k];
				if (group[cur] == i) continue;

				gv[i].push_back(group[cur]);
			}
		}
	}

	start = group[start];
	int ans[idx];
	fill(ans, ans + idx, -1e9);

	ans[start] = gnd[start].ATM;
	priority_queue<pii, vector<pii>, less<pii>> pq;
	pq.push({gnd[start].ATM, start});
	int cnt = 1;
	while (pq.size() && cnt < idx) {
		pii cur = pq.top(); pq.pop();
		if (cur.ATM < ans[cur.second]) continue;

		for (int i = 0; i < gv[cur.second].size(); i++) {
			int next = gv[cur.second][i];
			int atm = gnd[next].ATM;
			if (ans[next] < ans[cur.second] + atm) {
				cnt++;
				ans[next] = ans[cur.second] + atm;
				pq.push({ans[next], next});
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < idx; i++) {
		if (gnd[i].RES) ret = max(ret, ans[i]);
	}
	cout << ret;
	return 0;
}