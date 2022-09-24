#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> ans;
    map<string, string> mp;

    for (int i = 0; i < record.size(); i++) {
        if (record[i][0] == 'E') {
            int idx = record[i].rfind(' ');
            string id = record[i].substr(6, idx - 6);
            mp[id] = record[i].substr(idx + 1);
            ans.push_back("E " + id);
        } else if (record[i][0] == 'L') {
            int idx = record[i].rfind(' ');
            string id = record[i].substr(6, idx - 6);
            ans.push_back("L " + id);
        } else if (record[i][0] == 'C') {
            int idx = record[i].rfind(' ');
            string id = record[i].substr(7, idx - 7);
            mp[id] = record[i].substr(idx + 1);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        if (ans[i][0] == 'E')
            ans[i] = mp[ans[i].substr(2)] + "님이 들어왔습니다.";
        else
            ans[i] = mp[ans[i].substr(2)] + "님이 나갔습니다.";
    }

    return ans;
}
