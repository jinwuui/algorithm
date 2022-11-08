#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
    unordered_map<string, int> mp;
    vector<int> answer;
    int maxv = 27;
    for (int i = 0; i < 26; i++) mp[string(1, (char)(i + 'A'))] = i + 1;

    for (int i = 0; i < msg.length();) {
        int j = msg.length() - i;
        for (; j >= 1; j--) {
            string cur = msg.substr(i, j);
            int value = mp[cur];
            if (value != 0) {
                answer.push_back(value);
                cur.push_back(msg[i + j]);
                mp[cur] = maxv++;
                break;
            }
        }
        i += j;
    }
    return answer;
}