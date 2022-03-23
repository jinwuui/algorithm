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

bool isOk(vector<int> &v) {
	for (int i = 1; i < v.size(); i++) {
		if (v[i - 1] > v[i]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	queue<vector<int>> q;
	set<vector<int>> st;
	q.push(v);
	st.insert(v);

	int cnt = 0;
	while (true) {
		int len = q.size();
		if (len == 0) {
			cout << -1;
			return 0;
		}
		bool isGood = false;
		for (int i = 0; i < len; i++) {
			vector<int> cur = q.front(); q.pop();
			if (isOk(cur)) {
				isGood = true;
				break;
			}
			for (int j = 0; j <= n - k; j++) {
				vector<int> tmp(cur);
				reverse(tmp.begin() + j, tmp.begin() + j + k);
				if (st.find(tmp) != st.end()) continue;
				q.push(tmp);
				st.insert(tmp);
			}
		}
		if (!isGood) cnt++;
		else break;
	}

	cout << cnt;
	
	return 0;
}