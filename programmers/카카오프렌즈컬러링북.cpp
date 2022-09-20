#include <math.h>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int bfs(int sr, int sc, vector<vector<int>> &pic, vector<vector<int>> &vis) {
    int m = pic.size(), n = pic[0].size(), cnt = 1;

    queue<pii> q;
    q.push({sr, sc});
    vis[sr][sc] = 1;

    while (q.size()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;
            if (vis[nr][nc] || pic[sr][sc] != pic[nr][nc])
                continue;

            cnt++;
            q.push({nr, nc});
            vis[nr][nc] = 1;
        }
    }
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<vector<int>> vis(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || !picture[i][j])
                continue;

            int area = bfs(i, j, picture, vis);
            number_of_area++;
            max_size_of_one_area = max(max_size_of_one_area, area);
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}