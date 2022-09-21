#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &v1, vector<int> &v2) {
    if (v1[1] != v2[1])
        return v1[1] < v2[1];
    return v1[0] < v2[0];
}
int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), comp);

    int cur = routes[0][1], cnt = 1;
    for (int i = 1; i < routes.size(); i++) {
        if (routes[i][0] > cur) {
            cur = routes[i][1];
            cnt++;
        }
    }
    return cnt;
}