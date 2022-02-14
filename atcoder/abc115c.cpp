#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int gap = v[k - 1] - v[0];
	int ans = gap;
	for (int i = k; i <  n; i++) {
		gap = v[i] - v[i - k + 1];
		ans = min(ans, gap);
	}
	cout << ans;
	return 0;
}