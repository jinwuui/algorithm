#include <bits/stdc++.h>

using namespace std;

int ans;
vector<int> vis;

void brute(int idx, int cnt, vector<vector<int>> &adj, vector<string> &words,
           string &target) {
    if (words[idx] == target) {
        ans = min(ans, cnt);
        return;
    }

    for (int i = 0; i < adj[idx].size(); i++) {
        if (vis[adj[idx][i]])
            continue;

        vis[adj[idx][i]] = 1;
        brute(adj[idx][i], cnt + 1, adj, words, target);
        vis[adj[idx][i]] = 0;
    }
}

bool canBe(string &w1, string &w2) {
    int cnt = 0;
    for (int i = 0; i < w1.length(); i++)
        if (w1[i] != w2[i])
            cnt++;
    return cnt == 1;
}

int solution(string begin, string target, vector<string> words) {
    ans = 1e9;
    words.push_back(begin);
    vis.resize(words.size());

    vector<vector<int>> adj(words.size(), vector<int>());
    for (int i = 0; i < words.size() - 1; i++) {
        for (int j = i + 1; j < words.size(); j++) {
            if (!canBe(words[i], words[j]))
                continue;

            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    brute(words.size() - 1, 0, adj, words, target);
    return ans == 1e9 ? 0 : ans;
}