#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	map<string, int> mp;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		mp[s]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		mp[s]--;
	}
	int ans = 0;
	for (auto p : mp) {
		ans = max(ans, p.second);
	}
	cout << ans;

	return 0;
}