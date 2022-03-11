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
	
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	vector<int> d(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	vector<int> mid1(n * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mid1[i * n + j] = a[i] + b[j];
		}
	}

	vector<int> mid2(n * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mid2[i * n + j] = c[i] + d[j];
		}
	}

	ll ans = 0;
	sort(mid2.begin(), mid2.end());
	for (int i = 0; i < mid1.size(); i++) {
		int target = 0 - mid1[i];

		int val = upper_bound(mid2.begin(), mid2.end(), target) - lower_bound(mid2.begin(), mid2.end(), target);
		ans += val;
	}
	cout << ans;

	return 0;
}