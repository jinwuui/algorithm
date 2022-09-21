#include <bits/stdc++.h>
using namespace std;

const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

int bfs(vector<vector<int>> &maps, int m, int n) {
    vector<vector<int>> vis(m, vector<int>(n));
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;

    while (q.size()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + cur.first;
            int nc = dc[i] + cur.second;

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;
            if (vis[nr][nc] || !maps[nr][nc])
                continue;

            q.push({nr, nc});
            vis[nr][nc] = vis[cur.first][cur.second] + 1;
            if (nr == m - 1 && nc == n - 1)
                return vis[nr][nc];
        }
    }
    return -1;
}
int solution(vector<vector<int>> maps) {
    return bfs(maps, maps.size(), maps[0].size());
}