#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int ans = s.length();

    for (int i = 1; i <= s.length() / 2; i++) {
        vector<string> v;
        for (int j = 0; j < s.length(); j += i) v.push_back(s.substr(j, i));

        int cnt = 0, len = 0;
        for (int j = 1; j < v.size(); j++) {
            if (v[j] == v[j - 1])
                cnt++;
            else {
                len += (cnt ? to_string(cnt + 1).length() : 0) + i;
                cnt = 0;
            }
        }

        len += (cnt ? to_string(cnt + 1).length() : 0) + v.back().length();
        ans = min(ans, len);
    }

    return ans;
}