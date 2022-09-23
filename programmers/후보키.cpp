#include <bits/stdc++.h>

using namespace std;

vector<int> vis;
vector<vector<int>> v;
int ans;

bool isOk(vector<vector<string>> &relation) {
    if (*max_element(vis.begin(), vis.end()) == 0) return false;

    set<string> st;
    for (int i = 0; i < relation.size(); i++) {
        string s = "";
        for (int j = 0; j < vis.size(); j++) {
            if (vis[j]) s += relation[i][j];
        }

        if (st.find(s) != st.end()) return false;

        st.insert(s);
    }

    return true;
}

void brute(int k, vector<vector<string>> &relation) {
    if (k == vis.size()) {
        for (int i = 0; i < v.size(); i++) {
            int cnt = 0, match = 0;
            for (int j = 0; j < v[i].size(); j++) {
                if (v[i][j] == 1) cnt++;
                if (vis[j] == 1 && v[i][j] == 1) match++;
            }

            if (cnt == match) return;
        }

        if (isOk(relation)) {
            v.push_back(vis);
            ans++;
        }

        return;
    }

    vis[k] = 0;
    brute(k + 1, relation);

    vis[k] = 1;
    brute(k + 1, relation);
}

int solution(vector<vector<string>> relation) {
    vis.resize(relation[0].size());
    brute(0, relation);
    return ans;
}