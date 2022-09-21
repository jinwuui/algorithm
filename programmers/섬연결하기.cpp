#include <bits/stdc++.h>

using namespace std;

vector<int> buf(111);

int findSet(int nd) {
    if (buf[nd] == nd)
        return nd;
    return buf[nd] = findSet(buf[nd]);
}

bool unionSet(int n1, int n2) {
    int p1 = findSet(n1);
    int p2 = findSet(n2);

    if (p1 == p2)
        return false;

    buf[p1] = p2;
    return true;
}

bool comp(vector<int> &v1, vector<int> &v2) { return v1[2] < v2[2]; }

int solution(int n, vector<vector<int>> costs) {
    iota(buf.begin(), buf.end(), 0);
    sort(costs.begin(), costs.end(), comp);

    int ans = 0;
    for (int i = 0; i < costs.size(); i++) {
        if (unionSet(costs[i][0], costs[i][1]))
            ans += costs[i][2];
    }
    return ans;
}