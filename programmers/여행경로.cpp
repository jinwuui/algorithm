#include <bits/stdc++.h>

using namespace std;

vector<string> ans;
map<string, int> mp;
vector<string> mem;
void dfs(vector<string> &path, vector<vector<int>> &adj, int cur, int k) {
    if (ans.size() != 0)
        return;

    path.push_back(mem[cur]);

    if (k == mp.size()) {
        ans.resize(k);
        copy(path.begin(), path.end(), ans.begin());
        return;
    }

    for (int i = 0; i < adj[cur].size(); i++) {
        int nx = adj[cur][i];
        dfs(path, adj, nx, k + 1);
    }

    path.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    mp.clear();
    ans.clear();
    mem.resize(10001);

    int idx = 0;
    mp["ICN"] = idx++;
    mem[0] = "ICN";

    vector<vector<int>> adj(10001, vector<int>());
    for (int i = 0; i < tickets.size(); i++) {
        string s = tickets[i][0], e = tickets[i][1];
        if (mp.find(s) == mp.end()) {
            mem[idx] = s;
            mp[s] = idx++;
        }
        if (mp.find(e) == mp.end()) {
            mem[idx] = e;
            mp[e] = idx++;
        }

        adj[mp[s]].push_back(mp[e]);
    }

    for (int i = 0; i < idx; i++)
        sort(adj[i].begin(), adj[i].end());

    vector<string> path;
    dfs(path, adj, 0, 0);
    return ans;
}