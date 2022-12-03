#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    vector<int> order(26);
    for (int i = 0; i < skill.length(); i++) order[skill[i] - 'A'] = i + 1;

    int answer = 0;
    for (int i = 0; i < skill_trees.size(); i++) {
        string cur = skill_trees[i];

        int idx = 1, isOk = 1;
        for (int j = 0; j < cur.length(); j++) {
            int ord = order[cur[j] - 'A'];
            if (!ord) continue;

            if (ord == idx) {
                idx++;
            } else {
                isOk = 0;
                break;
            }
        }

        answer += isOk;
    }
    return answer;
}
