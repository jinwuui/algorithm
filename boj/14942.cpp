#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
#define C first
#define X second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;


vector<vector<pii>> adj(111111);
vector<int> v(111111);
vector<pii> dist;
vector<int> ans(111111);
vector<int> vis(111111);
int n;

bool isGood(int mid, int w) {
	return w > dist.back().first - dist[mid].first;
}

int bi(int low, int high, int w) {
	for (int i = 0; i < dist.size(); i++) {
		cout << "	" << dist[i].first << " " << dist[i].second << endl;
	}
	cout << sp << sp << w << endl;
	int ans = -1;

	while (low <= high) {
		cout << "		" << low << sp << high << endl;
		int mid = (low + high) / 2;
		if (!isGood(mid, w)) {
			low = mid + 1;
			ans = mid;
		}
		else {
			high = mid - 1;
		}
		for (int i = 0;)
	}
	cout << "	  fin " << low << sp << high << endl;
	return ans;
}

void dfs(int k) {
	if (dist.size())
		ans[k] = bi(0, dist.size(), v[k]);
	else ans[k] = -1;

	vis[k] = 1;
	cout << k << " " << ans[k] << endl;
	for (int i = 0; i < adj[k].size(); i++) {
		pii nx = adj[k][i];
		if (vis[nx.second]) continue;
		int newW = dist.size() ? dist.back().first + nx.first : nx.first;
		
		dist.push_back({newW, nx.second});
		dfs(nx.second);
		dist.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	for (int i = 0; i < n - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		adj[a].push_back({w, b});
		adj[b].push_back({w, a});
	}

	dfs(0);


	return 0;
}