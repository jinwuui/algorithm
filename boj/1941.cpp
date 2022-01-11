#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

char buf[5][5];
int check[5][5];
int ans;
int ts = 0, ty = 0;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
set<vector<pii>> st;

void debug() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << check[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

vector<pii> result;
vector<pii> path() {
	vector<pii> result;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (!check[i][j]) continue;

			result.push_back({i, j});
		}
	}
	return result;
}

void solve(int r, int c) {
	if (ts + ty >= 7) {
		if (ts > ty) {
			// result.clear();
			// path();
			st.insert(path());
			ans++;
		}
		
		return;
	}

	queue<pii> q;
	q.push({r, c});
	set<pii> cango;
	vector<vector<int>> vis(5, vector<int>(5));
	vis[r][c] = 1;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
			if (vis[nr][nc]) continue;
			vis[nr][nc] = 1;
			if (check[nr][nc]) {
				q.push({nr, nc});
			} else {
				cango.insert({nr, nc});
			}
		}
	}

	for (pii p : cango) {
		int nr = p.first;
		int nc = p.second;
		if (buf[nr][nc] == 'S') ts++;
		else ty++;

		check[nr][nc] = 1;
		solve(nr, nc);
		check[nr][nc] = 0;

		if (buf[nr][nc] == 'S') ts--;
		else ty--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> buf[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ts = 0, ty = 0;

			if (buf[i][j] == 'S') ts++;
			else ty++;

			check[i][j] = 1;
			solve(i, j);
			check[i][j] = 0;
		}
	}

	cout << st.size();

	return 0;
}