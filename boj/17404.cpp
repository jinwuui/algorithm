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
	int r = 0, g = 0, b = 0;
	RGB() {}
	RGB(int nr, int ng, int nb) {
		r = nr, g = ng, b = nb;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<vector<RGB>> dp(3, vector<RGB>(n));

	// 재귀 DP로 풀어보기
	for (int i = 0; i < 3; i++) {
		int tmp;
		cin >> tmp;
		dp[i][0] = RGB(tmp, tmp, tmp);
	}
	for (int i = 1; i < n - 1; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		dp[0][i] = RGB(-1, r + dp[0][i - 1].g, r + dp[0][i - 1].b);
		dp[1][i] = RGB(g + dp[0][i - 1].r, -1, g + dp[0][i - 1].b);
		dp[2][i] = RGB(b + dp[0][i - 1].r, b + dp[0][i - 1].g, -1);
	}
	
	return 0;
}