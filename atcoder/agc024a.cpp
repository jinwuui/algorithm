// unsolved

#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	ll a, b, c, k;
	cin >> a >> b >> c >> k;

	for (long i = 0; i < k; i++) {

		ll ta = b + c, tb = a + c, tc = a + b;
		a = ta, b = tb, c = tc;
	}
	cout << a - b;

	return 0;
}