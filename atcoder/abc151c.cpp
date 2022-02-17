#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, ac = 0, wa = 0;
	cin >> n >> m;

	vector<int> v(n + 1);
	for (int i = 0; i < m; i++) {
		int p; string s;
		cin >> p >> s;

		if (s == "AC") {
			if (v[p] > 0) continue;

			wa += -v[p];
			v[p] = 1;
			ac++;
		} else {
			if (v[p] > 0) continue;

			v[p]--;
		}
	}
	cout << ac << sp << wa;

	return 0;
}