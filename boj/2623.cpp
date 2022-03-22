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

int n, m;
vector<vector<int>> buf(2000, vector<int>());
vector<int> cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	cnt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int len, prev;
		cin >> len >> prev;
		for (int j = 1; j < len; j++) {
			int tmp; cin >> tmp;
			buf[prev].push_back(tmp);
			cnt[tmp]++;
			prev = tmp;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!cnt[i])
			q.push(i);
	}
	
	int vcnt = 0;
	vector<int> ans;
	while (q.size()) {
		int cur = q.front(); q.pop();
		ans.push_back(cur);
		for (int i = 0; i < buf[cur].size(); i++) {
			int nx = buf[cur][i];
			cnt[nx]--;
			if (!cnt[nx]) q.push(nx);
		}
		vcnt++;
	}

	if (vcnt != n) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	
	return 0;
}