#include <algorithm>
#include <queue>
#include <string>
#include <vector>

#define COST first
#define START second

using namespace std;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>> pq; // first: 걸리는 시간, second: 인덱스;

    bool onDisk = false;
    int t = 0, wait = 0, i = 0;

    while (1) {
        if (onDisk) {
            while (i < jobs.size() && t >= jobs[i][0]) {
                pq.push({-jobs[i][1], jobs[i][0]});
                i++;
            }

            if (pq.empty()) {
                onDisk = false;
                continue;
            }

            pair<int, int> nx = pq.top();
            pq.pop();

            wait += (t + -nx.COST) - nx.START;
            t += -nx.COST;
        } else if (!onDisk && i < jobs.size()) {
            t = jobs[i][1] + jobs[i][0];
            wait += jobs[i][1];
            i++;
            onDisk = true;
        } else {
            break;
        }
    }

    return wait / jobs.size();
}