#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {

    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < edge.size(); i++) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }

    vector<int> vis(n + 1);
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    int maxv = 0;
    while (q.size()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int nx = adj[cur][i];

            if (vis[nx])
                continue;

            q.push(nx);
            vis[nx] = vis[cur] + 1;
            maxv = max(maxv, vis[nx]);
        }
    }

    int cnt = 0;
    for (int i = 0; i < vis.size(); i++)
        if (vis[i] == maxv)
            cnt++;

    return cnt;
}