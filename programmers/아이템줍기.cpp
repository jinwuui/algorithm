#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

bool isInside(vector<vector<int>> &rect, int y, int x) {
    for (int i = 0; i < rect.size(); i++) {
        int lx = rect[i][0], ly = rect[i][1], rx = rect[i][2], ry = rect[i][3];

        if (lx < x && x < rx && ly < y && y < ry) return true;
    }
    return false;
}

bool onEdge(int x, int y, vector<int> &rect) {
    if (rect[0] <= x && x <= rect[2] && rect[1] <= y && y <= rect[3]) {
        if (rect[0] == x || rect[2] == x || rect[1] == y || rect[3] == y)
            return true;
    }
    return false;
}

int dist = 1;
void dfs(int cx, int cy, int curRect, vector<vector<int>> &rect,
         vector<vector<int>> &vis) {
    vis[cy][cx] = dist++;

    for (int i = 0; i < 4; i++) {
        int nx = dx[i] + cx;
        int ny = dy[i] + cy;

        if (isInside(rect, ny, nx)) continue;

        int cnt = 0, newRect = -1;
        for (int j = 0; j < rect.size(); j++) {
            // nx, ny 가 사각형 변 위의 점인지 확인
            if (onEdge(nx, ny, rect[j])) {
                cnt++;
                newRect = j != curRect ? j : newRect;
            }
        }

        if (vis[ny][nx]) continue;

        if (cnt == 1 && newRect == -1) {
            // 현재 사각형의 변 위에서 이동
            dfs(nx, ny, curRect, rect, vis);
        } else if (cnt == 2 && newRect != -1) {
            // 새로운 사각형과 맞닿은 점임
            // 새로운 사각형 위에서 이동
            dfs(nx, ny, newRect, rect, vis);
        }
    }
}

int solution(vector<vector<int>> rect, int sx, int sy, int ix, int iy) {
    dist = 1;

    int initRect, initX = 1e9, initY;
    for (int i = 0; i < rect.size(); i++) {
        rect[i][0] *= 2, rect[i][1] *= 2, rect[i][2] *= 2, rect[i][3] *= 2;
        if (initX > rect[i][0])
            initX = rect[i][0], initY = rect[i][1], initRect = i;
    }

    vector<vector<int>> vis(222, vector<int>(222));
    dfs(initX, initY, initRect, rect, vis);

    sy *= 2, sx *= 2, ix *= 2, iy *= 2;
    int startToItem = abs(vis[sy][sx] - vis[iy][ix]);
    int maxv = -1;
    for (int i = 0; i < 222; i++)
        for (int j = 0; j < 222; j++)
            maxv = max(maxv, vis[i][j]);

    return min(startToItem, maxv - startToItem) / 2;
}