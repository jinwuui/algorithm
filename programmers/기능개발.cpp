#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calculateDays(int now, int speed) {
    return (100 - now) / speed + ((100 - now) % speed != 0);
}
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day = calculateDays(progresses[0], speeds[0]);
    int cur = day;
    answer.push_back(1);

    for (int i = 1; i < progresses.size(); i++) {
        day = calculateDays(progresses[i], speeds[i]);

        if (cur >= day)
            answer.back()++;
        else {
            answer.push_back(1);
            cur = day;
        }
    }

    return answer;
}