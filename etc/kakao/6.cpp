#include <string>
#include <vector>

using namespace std;

int n, m;
int buf[1001][1001];
int minus[1001][1001];
int plus[1001][1001];

void solve(int r1, int c1, int r2, int c2, int d) {
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			buf[i][j] += d;
		}
	}
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
	n = board.size(); m = board[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			buf[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < skill.size(); i++) {
		vector<int> v = skill[i];
		int type = v[0], r1 = v[1], c1 = v[2], r2 = v[3], c2 = v[4], d = v[5];

		if (type == 1) {
			for (int i = r1; i <= r2; i++) {
				for (int j = c1; j <= c2; j++) {
					buf[i][j] += d;
				}
			}
		}
		else
			solve(r1, c1, r2, c2, d);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (buf[i][j] > 0) answer++;
		}
	}
    return answer;
}
