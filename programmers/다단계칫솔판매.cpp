#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

void dfs(int cur, vector<int> &parent, vector<int> &sells) {
    if (cur == 0) return;

    int sum = 0;
    for (int i = 0; i < sells.size(); i++) {
        int tax = sells[i] / 10;
        sum += sells[i] - tax;
        sells[i] = tax;
    }

    dfs(parent[cur], parent, sells);
    ans[cur] += sum;
}

vector<int> solution(vector<string> enroll, vector<string> referral,
                     vector<string> seller, vector<int> amount) {
    ans.resize(enroll.size() + 1);

    map<string, int> nameToIdx;
    int idx = 0;
    nameToIdx["-"] = idx++;
    for (int i = 0; i < enroll.size(); i++)
        nameToIdx[enroll[i]] = idx++;

    vector<int> parent(enroll.size() + 1);
    for (int i = 0; i < referral.size(); i++)
        parent[nameToIdx[enroll[i]]] = nameToIdx[referral[i]];

    vector<vector<int>> sells(enroll.size() + 1, vector<int>());
    for (int i = 0; i < seller.size(); i++) {
        int cur = nameToIdx[seller[i]];
        int profit = amount[i] * 100;

        sells[cur].push_back(profit);
    }

    for (int i = 0; i < sells.size(); i++) {
        if (sells[i].size() == 0) continue;

        dfs(i, parent, sells[i]);
    }

    ans.erase(ans.begin());
    return ans;
}