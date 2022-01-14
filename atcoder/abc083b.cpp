#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = i;

		int sum = 0;
		while (tmp) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if (a <= sum && sum <= b) {
			ans += i;
		}
	}
	cout << ans;
	return 0;
}