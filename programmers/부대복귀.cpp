#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources,
                     int destination) {
    vector<int> adj[n + 1];
    for (int i = 0; i < roads.size(); i++) {
        int a = roads[i][0], b = roads[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(n + 1);
    queue<int> q;
    q.push(destination);
    vis[destination] = 1;
    while (q.size()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int nx = adj[cur][i];
            if (vis[nx]) continue;

            vis[nx] = vis[cur] + 1;
            q.push(nx);
        }
    }

    vector<int> answer(sources.size());
    for (int i = 0; i < sources.size(); i++) {
        answer[i] = vis[sources[i]] - 1;
    }
    return answer;
}
