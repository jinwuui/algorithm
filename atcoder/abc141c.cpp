#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, q;
	cin >> n >> k >> q;

	vector<int> a(n);
	for (int i = 0; i < q; i++) {
		int tmp; cin >> tmp;

		a[--tmp]++;
	}

	for (int i = 0; i < n; i++) {
		if (k - q + a[i] > 0) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}