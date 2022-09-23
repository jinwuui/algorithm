#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int ans;
vector<pair<int, pii>> cards;
vector<int> vis;

int bfs(vector<vector<int>> &board, int sr, int sc, int er, int ec) {
    vector<vector<int>> visit(4, vector<int>(4));
    queue<pii> q;
    q.push({sr, sc});
    visit[sr][sc] = 1;

    while (q.size()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.first, nc = cur.second;

            for (int j = 0; j < 4; j++) {
                nr += dr[i], nc += dc[i];

                // 맵을 벗어나버리면 그 이전 부분에 +1 로 기록하고 탈출
                if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4 || board[nr][nc]) {
                    if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4)
                        nr -= dr[i], nc -= dc[i];
                    if (visit[nr][nc] == 0 ||
                        visit[nr][nc] > visit[cur.first][cur.second] + 1) {
                        q.push({nr, nc});
                        visit[nr][nc] = visit[cur.first][cur.second] + 1;
                    }

                    break;
                } else {
                    // 둘다 아니면 + 1
                    if (visit[nr][nc] == 0 ||
                        visit[nr][nc] > visit[cur.first][cur.second] + 1) {
                        q.push({nr, nc});
                        visit[nr][nc] = visit[nr - dr[i]][nc - dc[i]] + 1;
                    }
                }
            }
        }
    }

    return visit[er][ec];
}

void brute(vector<vector<int>> &board, int r, int c, int dist, int ord,
           int prev) {
    if (ord == cards.size()) {
        ans = min(ans, dist);
        return;
    }

    for (int i = 0; i < cards.size(); i++) {
        if (vis[i]) continue;
        if (prev != -1 && cards[prev].first != cards[i].first) continue;

        pii target = cards[i].second;
        int cnt = bfs(board, r, c, target.first, target.second);
        vis[i] = 1;
        board[target.first][target.second] = 0;
        brute(board, target.first, target.second, dist + cnt, ord + 1,
              prev == -1 ? i : -1);
        vis[i] = 0;
        board[target.first][target.second] = cards[i].first;
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    ans = 1e9;
    cards.clear();
    vis.resize(20);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j]) cards.push_back({board[i][j], {i, j}});

    cout << cards.size() << endl;
    brute(board, r, c, 0, 0, -1);

    return ans;
}