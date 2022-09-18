
#include <bits/stdc++.h>

using namespace std;

const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < 5; i++) {
        vector<string> buf = places[i];

        bool isOk = true;
        for (int j = 0; j < 5 && isOk; j++) {
            for (int k = 0; k < 5 && isOk; k++) {
                if (buf[j][k] != 'P') continue;

                queue<pair<int, int>> q;
                vector<vector<int>> vis(5, vector<int>(5));

                q.push({j, k});
                vis[j][k] = 1;
                while (q.size() && isOk) {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++) {
                        int nr = cur.first + dr[i];
                        int nc = cur.second + dc[i];

                        if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
                        if (vis[nr][nc]) continue;
                        if (buf[nr][nc] == 'P') {
                            if (buf[cur.first][cur.second] == 'O' ||
                                buf[cur.first][cur.second] == 'P') {
                                isOk = false;
                                break;
                            }
                            continue;
                        }

                        vis[nr][nc] = vis[cur.first][cur.second] + 1;
                        if (vis[nr][nc] < 3) q.push({nr, nc});
                    }
                }
            }
        }

        answer.push_back(isOk);
    }

    return answer;
}