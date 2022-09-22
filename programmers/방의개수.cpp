#include <bits/stdc++.h>

using namespace std;

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int buf[222222];
set<pair<int, int>> vis;

int ans = 0;
int findSet(int nd) {
    if (buf[nd] == nd)
        return nd;
    return buf[nd] = findSet(buf[nd]);
}

void unionSet(int a, int b) {
    int pa = findSet(a), pb = findSet(b);
    if (a > b)
        swap(a, b);

    if (pa == pb) {
        if (vis.find({a, b}) == vis.end())
            ans++;
    } else
        buf[pb] = pa;

    vis.insert({a, b});
}

int solution(vector<int> arrows) {
    iota(buf, buf + 222222, 0);
    ans = 0;

    pair<int, int> cur = {0, 0};
    map<pair<int, int>, int> mp;
    int idx = 1;
    mp[cur] = idx++;

    bool retry = true;
    for (int i = 0; i < arrows.size(); i++) {
        int prevIdx = mp[cur], go = arrows[i];

        cur.first += dr[go];
        cur.second += dc[go];

        if (!mp[cur])
            mp[cur] = idx++;

        int curIdx = mp[cur];

        if (!(i > 0 && abs(arrows[i - 1] - arrows[i]) == 4))
            unionSet(prevIdx, curIdx);

        if (retry) {
            i--;
            retry = false;
        } else
            retry = true;
    }
    return ans;
}