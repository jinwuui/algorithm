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
	ll ans = n;
	while (--n > 0) {
		ans = (ans * n) % 1000000007;
	}
	cout << ans;
	return 0;
}