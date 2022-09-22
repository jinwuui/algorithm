#include <bits/stdc++.h>

using namespace std;

vector<string> path;
vector<string> ans;

void dfs(vector<vector<string>> &tickets, vector<int> &used, int usedCnt,
         string cur) {
    if (!ans.empty()) return;
    path.push_back(cur);

    if (usedCnt == tickets.size()) {
        if (ans.empty()) {
            ans.resize(path.size());
            copy(path.begin(), path.end(), ans.begin());
        }
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (used[i]) continue;
        if (tickets[i][0] != cur) continue;

        used[i]++;
        dfs(tickets, used, usedCnt + 1, tickets[i][1]);
        used[i]--;
    }

    path.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    path.clear();
    sort(tickets.begin(), tickets.end());
    vector<int> used(tickets.size());

    dfs(tickets, used, 0, "ICN");
    return ans;
}