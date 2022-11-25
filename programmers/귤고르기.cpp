#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int solution(int k, vector<int> v) {
    unordered_map<int, int> count;
    for (int i = 0; i < v.size(); i++) count[v[i]]++;

    vector<int> buf;
    for (auto it = count.begin(); it != count.end(); it++) {
        buf.push_back(it->second);
    }
    sort(buf.begin(), buf.end());

    int answer = 0, cnt = 0;
    while (k > cnt) {
        cnt += buf[buf.size() - answer - 1];
        answer++;
    }

    return answer;
}
