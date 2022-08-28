#include <string>
#include <vector>

using namespace std;

int n, buf[20];
vector<int> v[20];
int ans = 0;

void dfs(int cur, int sheep, int wolf, int vis[], queue<int> q) {
	vis[cur] = 1;
	if (sheep > wolf) {
		ans = max(ans, sheep);
	}
	else {
		vis[cur] = 0;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (vis[i]) {
			for (int j = 0; j < v[i].size(); j++) {
				if (vis[v[i][j]]) continue;

				q.push(v[i][j]);
			}
		}
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();

		if (vis[now]) continue;

		if (buf[now]) {
			dfs(now, sheep, wolf + 1, des);
		}
		else {
			dfs(now, sheep + 1, wolf, des);
		}
	}
	// for (int i = 0; i < v[cur].size(); i++) {
	// 	int now = v[cur][i];

	// 	if (buf[now])
	// 		sheep += dfs(v[cur][i], sheep, wolf + 1);
	// 	else
	// 		dfs(v[cur][i], sheep + 1, wolf);
	// }
	vis[cur] = 0;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
	n = info.size();
	for (int i = 0; i < info.size(); i++) {
		buf[i] = info[i];
	}

	for (int i = 0; i < edges.size(); i++) {
		int a = edges[i][0], b = edges[i][1];
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> tmp;
	int vis[n];
	memset(vis, 0, sizeof(vis));
	vis[0] = 1;
	dfs(0, 1, 0, vis, tmp);

	answer = ans;
    return answer;
}