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

	ll l0 = 2, l1 = 1;
	for (int i = 0; i < n - 1; i++) {
		ll tmp = l0 + l1;
		l0 = l1;
		l1 = tmp;
	}
	cout << l1;
	return 0;
}