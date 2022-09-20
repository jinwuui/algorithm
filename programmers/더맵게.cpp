#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scov, int K) {
    priority_queue<long long> pq;
    for (int i = 0; i < scov.size(); i++)
        pq.push(-scov[i]);

    int ans = 0;
    while (pq.size() > 1 && pq.top() > -K) {
        long long first = pq.top();
        pq.pop();

        long long second = pq.top();
        pq.pop();

        pq.push(first + second * 2);
        ans++;
    }

    if (pq.top() > -K)
        return -1;
    return ans;
}