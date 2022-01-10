#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int tmp; cin >> tmp;
			tmp--;
			a[tmp]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (a[i] == n) ans++;
	}
	cout << ans;

	return 0;
}