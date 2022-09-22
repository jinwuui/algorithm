#include <string>
#include <vector>

using namespace std;

vector<int> visCnt;

void dfs(int cur, int start, vector<vector<int>> &adj, vector<int> &vis) {
    for (int i = 0; i < adj[cur].size(); i++) {
        int nx = adj[cur][i];
        if (vis[nx])
            continue;

        visCnt[start]++, visCnt[nx]++;
        vis[nx] = 1;
        dfs(nx, start, adj, vis);
    }
}

int solution(int n, vector<vector<int>> results) {
    visCnt.resize(n + 1);

    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < results.size(); i++)
        adj[results[i][0]].push_back(results[i][1]);

    for (int i = 1; i <= n; i++) {
        vector<int> vis(n + 1);
        dfs(i, i, adj, vis);
    }

    int ans = 0;
    for (int i = 0; i < visCnt.size(); i++)
        if (visCnt[i] == n - 1)
            ans++;
    return ans;
}
