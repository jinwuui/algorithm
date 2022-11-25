#include <algorithm>
#include <map>
#include <vector>

using namespace std;
using pii = pair<int, int>;

bool comp(vector<int> &n1, vector<int> &n2) {
    if (n1[1] != n2[1]) return n1[1] > n2[1];
    return n1[0] < n2[0];
}

vector<int> vis;
map<pii, int> index_map;

void preorder(vector<int> &ans, vector<vector<int>> &nodeinfo, int minx,
              int maxx, pii parent) {
    for (int i = 0; i < nodeinfo.size(); i++) {
        if (vis[i]) continue;

        int curx = nodeinfo[i][0], cury = nodeinfo[i][1];

        if (curx < minx || curx > parent.first) continue;
        if (cury >= parent.second) continue;

        vis[i] = 1;
        ans.push_back(index_map[{curx, cury}]);
        preorder(ans, nodeinfo, minx, parent.first, {curx, cury});
        break;
    }

    for (int i = 0; i < nodeinfo.size(); i++) {
        if (vis[i]) continue;

        int curx = nodeinfo[i][0], cury = nodeinfo[i][1];

        if (curx < parent.first || curx > maxx) continue;
        if (cury >= parent.second) continue;

        vis[i] = 1;
        ans.push_back(index_map[{curx, cury}]);
        preorder(ans, nodeinfo, parent.first, maxx, {curx, cury});
        break;
    }
}

void postorder(vector<int> &ans, vector<vector<int>> &nodeinfo, int minx,
               int maxx, pii parent) {
    for (int i = 0; i < nodeinfo.size(); i++) {
        if (vis[i]) continue;

        int curx = nodeinfo[i][0], cury = nodeinfo[i][1];

        if (curx < minx || curx > parent.first) continue;
        if (cury >= parent.second) continue;

        vis[i] = 1;
        postorder(ans, nodeinfo, minx, parent.first, {curx, cury});
        break;
    }

    for (int i = 0; i < nodeinfo.size(); i++) {
        if (vis[i]) continue;

        int curx = nodeinfo[i][0], cury = nodeinfo[i][1];

        if (curx < parent.first || curx > maxx) continue;
        if (cury >= parent.second) continue;

        vis[i] = 1;
        postorder(ans, nodeinfo, parent.first, maxx, {curx, cury});
        break;
    }

    ans.push_back(index_map[parent]);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    index_map.clear();

    for (int i = 0; i < nodeinfo.size(); i++)
        index_map[{nodeinfo[i][0], nodeinfo[i][1]}] = i + 1;

    sort(nodeinfo.begin(), nodeinfo.end(), comp);

    vector<vector<int>> answer(2, vector<int>());

    vis.clear();
    vis.resize(nodeinfo.size());
    preorder(answer[0], nodeinfo, 0, 1e9, {1e9, 1e9});

    vis.clear();
    vis.resize(nodeinfo.size());
    postorder(answer[1], nodeinfo, 0, 1e9, {1e9, 1e9});
    answer[1].pop_back();

    return answer;
}