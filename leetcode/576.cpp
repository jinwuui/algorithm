#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

class Solution {
public:
	int dr[4] = {1, 0, -1, 0};
	int dc[4] = {0, 1 , 0, -1};
    int mod = 1000000000 + 7;
	int findPaths(int m, int n, int maxM, int r, int c) {
        
		vector<vector<int>> dp(m, vector<int>(n));
		dp[r][c] = 1;
		int cnt = 0;

		for (int move = 0; move < maxM; move++) {
			vector<vector<int>> tmp(m, vector<int>(n));

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
                    
					if (i == m - 1) cnt = (cnt + dp[i][j]) % mod;
                    if (j == n - 1) cnt = (cnt + dp[i][j]) % mod;
                    if (i == 0) cnt = (cnt + dp[i][j]) % mod;
                    if (j == 0) cnt = (cnt + dp[i][j]) % mod;
						
					for (int k = 0; k < 4; k++) {
						int nr = i + dr[k];
						int nc = j + dc[k];
						if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

						tmp[i][j] = (tmp[i][j] + dp[nr][nc]) % mod;
					}
				}
			}
			dp = tmp;
		}

		return cnt;
	}
};
