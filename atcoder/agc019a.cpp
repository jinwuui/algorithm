#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll q, h, s, d, n;
	cin >> q >> h >> s >> d >> n;
	q *= 4;
	h *= 2;

	ll minL = min(q, min(h, s));
	cout << min(n * minL, (n / 2 * d) + (n % 2) * minL);

	return 0;
}