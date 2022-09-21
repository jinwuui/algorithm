#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 0; i < wires.size(); i++) {
        adj[wires[i][0]].push_back(wires[i][1]);
        adj[wires[i][1]].push_back(wires[i][0]);
    }

    int minv = 1e9;
    for (int i = 0; i < wires.size(); i++) {

        queue<int> q;
        vector<bool> vis(n + 1);
        q.push(1);
        vis[1] = true;
        int cnt = 1;

        while (q.size()) {
            int cur = q.front();
            q.pop();

            for (int j = 0; j < adj[cur].size(); j++) {
                int nx = adj[cur][j];

                if ((wires[i][0] == cur && wires[i][1] == nx) ||
                    (wires[i][1] == cur && wires[i][0] == nx))
                    continue;
                if (vis[nx])
                    continue;

                vis[nx] = true;
                q.push(nx);
                cnt++;
            }
        }

        minv = min(minv, abs(n - 2 * cnt));
    }
    return minv;
}