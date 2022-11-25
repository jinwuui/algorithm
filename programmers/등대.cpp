#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using pii = pair<int, int>;

pii bfs(vector<vector<int>> &adj, priority_queue<pii> &pq,
        priority_queue<pii> &nextq, vector<int> &count, vector<int> &vis) {
    pii answer;

    while (pq.size()) {
        int cur = pq.top().second;
        cout << cur << " " << vis[cur] << " " << count[cur] << endl;
        pq.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int nx = adj[cur][i];

            // 만약 nx를 방문 했었다면 가지 않음
            if (count[nx] <= 0) continue;
            // 만약 nx에 색칠을 해서 길을 없앨 수 있다면 색칠함
            // 단, cur가 이미 색칠 되어 있다면 패스
            if (count[nx] && vis[cur] == 1) {
                answer.first++;
                answer.second += count[nx];  // 색칠함
                count[nx] = 0;
                for (int j = 0; j < adj[nx].size(); j++) count[adj[nx][j]]--;
                vis[nx] = -1;
            } else {
                vis[nx] = 1;
            }

            pq.push({count[nx], nx});
        }
    }

    return answer;
}

int solution(int n, vector<vector<int>> lighthouse) {
    // 말단 노드에서 진행
    // 말단 노드 바로 다음 노드를 색칠 -> 색칠하면서 지운 간선을 카운트
    vector<int> count(n + 1);

    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < lighthouse.size(); i++) {
        int a = lighthouse[i][0], b = lighthouse[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
        count[a]++, count[b]++;
    }

    vector<int> vis(n + 1);
    priority_queue<pii> q;
    for (int i = 1; i <= n; i++)
        if (adj[i].size() == 1) {
            q.push({1, i});
            vis[i] = 1;
        }

    int answer = 0, cnt = 0;

    while (cnt < lighthouse.size()) {
        priority_queue<pii> nextq;
        pii result = bfs(adj, q, nextq, count, vis);
        cnt += result.second;
        answer += result.first;
        q = nextq;
    }

    return answer;
}