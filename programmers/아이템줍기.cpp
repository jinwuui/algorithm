#include <bits/stdc++.h>

using namespace std;

const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

bool isInside(vector<vector<int>> &rect, int y, int x) {
    for (int i = 0; i < rect.size(); i++) {
        int lx = rect[i][0], ly = rect[i][1], rx = rect[i][2], ry = rect[i][3];

        if (lx < x && x < rx && ly < y && y < ry)
            return true;
    }
    return false;
}

int solution(vector<vector<int>> rect, int sx, int sy, int ix, int iy) {
    vector<vector<int>> buf(100, vector<int>(100)), vis(100, vector<int>(100));

    for (int i = 0; i < rect.size(); i++) {
        int lx = rect[i][0], ly = rect[i][1], rx = rect[i][2], ry = rect[i][3];

        int idx = i + 1;
        for (int j = lx; j <= rx; j++)
            buf[ly][j] = buf[ry][j] = idx;

        for (int j = ly; j <= ry; j++)
            buf[j][lx] = buf[j][rx] = idx;
    }

    for (int i = 20; i >= 0; i--) {
        for (int j = 0; j < 20; j++) {
            cout << buf[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    queue<pair<int, int>> q;
    q.push({sy, sx});
    vis[sy][sx] = 1;

    while (q.size()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + cur.first;
            int nc = dc[i] + cur.second;

            if (nr < 0 || nr >= 100 || nc < 0 || nc >= 100)
                continue;

            if (nr == iy && nc == ix) {
                vis[nr][nc] = -1;
                cout << endl;

                for (int i = 20; i >= 0; i--) {
                    for (int j = 0; j < 20; j++) {
                        cout << vis[i][j] << ' ';
                    }
                    cout << endl;
                }

                cout << endl;
                return vis[cur.first][cur.second];
            }
            if (vis[nr][nc] || !buf[nr][nc] || isInside(rect, nr, nc))
                continue;

            q.push({nr, nc});
            vis[nr][nc] = vis[cur.first][cur.second] + 1;
        }
    }

    cout << endl;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    return -1;
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    vector<vector<int>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int n1, n2, n3, n4;
        cin >> n1 >> n2 >> n3 >> n4;

        v.push_back({n1, n2, n3, n4});
    }

    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;

    cout << solution(v, n1, n2, n3, n4);
    return 0;
}