#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;

		while (tmp % 2 == 0) {
			tmp /= 2;
			ans++;
		}
	}
	cout << ans;
	return 0;
}