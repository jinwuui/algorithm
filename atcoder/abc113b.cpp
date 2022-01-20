#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, t, a;
	cin >> n >> t >> a;

	vector<pair<double, int>> v(n);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		v[i] = {abs((double)(a - (t - tmp * 0.006))), i};
	}
	sort(v.begin(), v.end());

	cout << v[0].second + 1;
	

	return 0;
}