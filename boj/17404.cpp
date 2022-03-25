#include <bits/stdc++.h>
#define R first
#define C second
#define W first
#define ND second
#define endl '\n'
#define sp ' '
#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, start, n) for (int i = start; i < (n); i++)
#define all(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};
const int MOD = 1000000007;

struct RGB {
	int n1, n2, n3;
	RGB() {}
	RGB(int nn1, int nn2, int nn3) {
		n1 = nn1, n2 = nn2, n3 = nn3;
	}
};
int main() {
	int n;
	cin >> n;
	vector<vector<RGB>> v(n, vector<RGB>(3));
	int t1, t2, t3;
	cin >> t1 >> t2 >> t3;
	v[0][0] = RGB(t1, 1e9, 1e9);
	v[0][1] = RGB(1e9, t2, 1e9);
	v[0][2] = RGB(1e9, 1e9, t3);

	for (int i = 1; i < n - 1; i++) {
		int r, g, b;
		cin >> r >> g >> b;

		v[i][0] = RGB(min(v[i - 1][1].n1, v[i - 1][2].n1) + r, min(v[i - 1][1].n2, v[i - 1][2].n2) + r, min(v[i - 1][1].n3, v[i - 1][2].n3) + r);
		v[i][1] = RGB(min(v[i - 1][0].n1, v[i - 1][2].n1) + g, min(v[i - 1][0].n2, v[i - 1][2].n2) + g, min(v[i - 1][0].n3, v[i - 1][2].n3) + g);
		v[i][2] = RGB(min(v[i - 1][0].n1, v[i - 1][1].n1) + b, min(v[i - 1][0].n2, v[i - 1][1].n2) + b, min(v[i - 1][0].n3, v[i - 1][1].n3) + b);
	}
	int r, g, b;
	cin >> r >> g >> b;
	int ans = r + min({v[n - 2][1].n2, v[n - 2][2].n2, v[n - 2][1].n3, v[n - 2][2].n3});
	ans = min(ans, g + min({v[n - 2][0].n1, v[n - 2][2].n1, v[n - 2][0].n3, v[n - 2][2].n3}));
	ans = min(ans, b + min({v[n - 2][0].n1, v[n - 2][1].n1, v[n - 2][0].n2, v[n - 2][1].n2}));
	cout << ans;
	return 0;
}