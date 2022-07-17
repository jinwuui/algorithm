#include <bits/stdc++.h>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> buf(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 0; i <= n; i++) buf[i][i] = 0;

    for (int i = 0; i < fares.size(); i++) {
        int t1 = fares[i][0], t2 = fares[i][1], cost = fares[i][2];
        buf[t1][t2] = cost, buf[t2][t1] = cost;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k) continue;
            for (int j = 1; j <= n; j++) {
                if (i == j || k == j) continue;
                buf[i][j] = min(buf[i][j], buf[i][k] + buf[k][j]);
            }
        }
    }

    int ans = 1e9;
    for (int i = 1; i <=n; i++) {
        ans = min(ans, buf[s][i] + buf[a][i] + buf[b][i]);
    }
    return ans;
    
    // // s -> mid
    // for (int i = 1; i <= n; i++) {
    //     int cost = buf[s][i];
    //     if (cost >= 1e9) continue;

    //     // mid -> a
    //     cost += buf[i][a];
    //     // mid -> b
    //     cost += buf[i][b];
    //     ans = min(ans, cost);
    // }

    // return ans;
}