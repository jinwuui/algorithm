#include <bits/stdc++.h>
using namespace std;
#define VER first
#define HOR second
#define R first
#define C second
#define pii pair<int, int>

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int solution(vector<vector<int>> board) {
	int n = board.size(), m = board[0].size();

	vector<vector<pii>> buf(n, vector<pii>(m, make_pair(1e9, 1e9)));

	queue<pii> q;
    q.push({0, 0});
	buf[0][0] = {0, 0};

	while (q.size()) {
		pii cur = q.front();
		q.pop();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int r = buf[i][j].VER, c = buf[i][j].HOR;
				if (r >= 1e9) r = -1;
				if (c >= 1e9) c = -1;

				cout << r << "," << c << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < 4; i++) {
			int nr = cur.R + dr[i];
			int nc = cur.C + dc[i];
			int curVer = buf[cur.R][cur.C].VER;
			int curHor = buf[cur.R][cur.C].HOR;

			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

			if (i > 1) {
				if (buf[nr][nc].HOR > min(buf[cur.R][cur.C].VER + 6, buf[cur.R][cur.C].HOR + 1)) {
					buf[nr][nc].HOR = min(buf[cur.R][cur.C].VER + 6, buf[cur.R][cur.C].HOR + 1);
					q.push({nr, nc});
				}
			} else {
				if (buf[nr][nc].VER > min(buf[cur.R][cur.C].VER + 1, buf[cur.R][cur.C].HOR + 6)) {
					buf[nr][nc].VER = min(buf[cur.R][cur.C].VER + 1, buf[cur.R][cur.C].HOR + 6);
					q.push({nr, nc});
				}
			}
		}
	}
	
    return min(buf[n - 1][m - 1].VER, buf[n - 1][m - 1].HOR) * 100;
}
