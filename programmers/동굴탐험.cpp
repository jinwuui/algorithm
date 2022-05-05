#include <bits/stdc++.h>

using namespace std;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    vector<vector<int>> adj(200001, vector<int>());
    vector<int> vis(200001);
    vector<int> locked(200001);

    for (int i = 0; i < path.size(); i++) {
        int a = path[i][0], b = path[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < order.size(); i++) {
        int a = order[i][0], b = order[i][1];
        locked[a] = b;
        locked[b] = -1;
    }

    queue<int> q;
	q.push(0);
    vis[0] = 1;
    int cntOpen = 0;
    while (true) {
        bool progressed = false;
        int count = q.size();
        while (count--) {
            int cur = q.front(); q.pop();
            int unlock = locked[cur];

            if (unlock > 0) {
                locked[unlock] = 0;
                if (vis[unlock]) q.push(unlock);
                locked[cur] = 0;
                cntOpen++;
                progressed = true;
            }
            
            for (int i = 0; i < adj[cur].size(); i++) {
                int nx = adj[cur][i];

                if (vis[nx]) continue;

                vis[nx] = 1;
                progressed = true;
                if (locked[nx] != -1) q.push(nx);
            }
        }
        if (!progressed) return false;
        if (cntOpen == order.size()) return true;
    }

    return false;
}