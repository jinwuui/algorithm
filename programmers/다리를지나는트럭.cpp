#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> q; // first: time, second: weight

    int time = 0, qSum = 0, i = 0;
    while (i < truck_weights.size()) {
        if (q.size() && q.front().first == time) {
            qSum -= q.front().second;
            q.pop();
        }

        if (qSum + truck_weights[i] <= weight) {
            q.push({time + bridge_length, truck_weights[i]});
            qSum += truck_weights[i];
            i++;
        }

        time++;
    }

    return q.back().first + 1;
}