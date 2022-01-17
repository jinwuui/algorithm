#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n + 1);
	v[0] = v[n] = 1e9;

	for (int i = 1; i < n; i++) {
		cin >> v[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += min(v[i], v[i + 1]);
	}
	cout << ans;
	return 0;
}