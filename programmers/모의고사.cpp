#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == (i % 5) + 1)
            a++;
    }

    int barr[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == barr[i % 8])
            b++;
    }

    int carr[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == carr[i % 10])
            c++;
    }
    vector<pair<int, int>> v({
        {-a, 1},
        {-b, 2},
        {-c, 3},
    });

    sort(v.begin(), v.end());

    vector<int> answer;

    answer.push_back(v[0].second);
    if (v[0].first == v[1].first)
        answer.push_back(v[1].second);
    if (v[0].first == v[2].first)
        answer.push_back(v[2].second);

    return answer;
}