#include <string>
#include <vector>

using namespace std;

vector<int> vis;

int brute(int k, int cnt, vector<vector<int>> &dungeons) {

    int result = cnt;
    for (int i = 0; i < dungeons.size(); i++) {
        if (vis[i] || k < dungeons[i][0])
            continue;

        vis[i] = 1;
        result = max(result, brute(k - dungeons[i][1], cnt + 1, dungeons));
        vis[i] = 0;
    }

    return result;
}

int solution(int k, vector<vector<int>> dungeons) {
    vis.resize(10);

    return brute(k, 0, dungeons);
}