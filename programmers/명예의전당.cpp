#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> answer(score.size());
    for (int i = 0; i < score.size(); i++) {
        int cur = score[i];
        if (pq.size() < 3) {
            pq.push(cur);
        } else if (pq.top() < cur) {
            pq.pop();
            pq.push(cur);
        }

        answer.push_back(pq.top());
    }
    return answer;
}