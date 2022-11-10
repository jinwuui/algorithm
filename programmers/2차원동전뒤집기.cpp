#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int n = beginning.size(), m = beginning[0].size();
    string begin, end;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) begin += (char)(beginning[i][j] + '0');
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) end += (char)(target[i][j] + '0');

    if (begin == end) return 0;
    unordered_map<string, int> vis;
    queue<string> q;
    q.push(begin);
    vis[begin] = 1;
    while (q.size()) {
        string cur = q.front();
        int value = vis[cur];
        q.pop();

        // 행 바꿔서 q에 넣기
        for (int i = 0; i < n; i++) {
            string nx = cur;
            for (int j = 0; j < m; j++)
                nx[i * m + j] = nx[i * m + j] == '1' ? '0' : '1';
            if (vis.find(nx) != vis.end()) continue;
            if (nx == end) return value;

            q.push(nx);
            vis[nx] = value + 1;
        }

        // 열 바꿔서 q에 넣기
        for (int i = 0; i < m; i++) {
            string nx = cur;
            for (int j = 0; j < n; j++) {
                nx[i + j * m] = nx[i + j * m] == '1' ? '0' : '1';
            }
            if (vis.find(nx) != vis.end()) continue;
            if (nx == end) return value;

            q.push(nx);
            vis[nx] = value + 1;
        }
    }

    return -1;
}