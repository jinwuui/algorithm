#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, a, b;
	cin >> n >> a >> b;

	if ((b - a) % 2 == 0) cout << (b - a) / 2;
	else
		cout << min((a - 1) + (b - (a - 1)) / 2 + ((b - (a - 1)) % 2 == 0) * 1, (n - b) + (a + (n - b)) / 2 + ((a + (n - b)) % 2 == 0) * 1);
	return 0;
}