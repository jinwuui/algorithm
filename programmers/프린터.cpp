#include <algorithm>
#include <deque>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    deque<pair<int, int>> q;
    vector<int> vis(priorities.size());

    for (int i = 0; i < priorities.size(); i++)
        q.push_back({priorities[i], i});

    int order = 1;
    while (q.size() && !vis[location]) {
        int curP = q.front().first;
        if (curP < max_element(q.begin(), q.end())->first) {
            q.push_back(q.front());
            q.pop_front();
        } else {
            vis[q.front().second] = order++;
            q.pop_front();
        }
    }

    return vis[location];
}