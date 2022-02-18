#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, minv = 1e18;
	cin >> n;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			ll div = n / i;
			minv = min(minv, div + i - 2);
		}
	}
	cout << minv;

	return 0;
}