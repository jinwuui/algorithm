#include <algorithm>
#include <vector>

using namespace std;

int solution(int distance, vector<vector<int>> scope,
             vector<vector<int>> times) {
    int answer = distance;
    for (int i = 0; i < scope.size(); i++) {
        int s = scope[i][0], e = scope[i][1];
        if (s > e) swap(s, e);
        int work = times[i][0], rest = times[i][1];

        for (int cur = s; cur <= e; cur++) {
            int guard_status = cur % (work + rest);
            if (0 < guard_status && guard_status <= work)
                answer = min(answer, cur);
        }
    }
    return answer;
}