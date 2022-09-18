// #include <bits/stdc++.h>

// using namespace std;

// map<string, int> mp;

// void brute(const string &s, string part, vector<int> &course, int cur, int k)
// {
//     if (cur == s.length()) {
//         for (int i = 0; i < course.size(); i++)
//             if (k == course[i]) mp[part]++;

//         return;
//     }

//     // choice
//     brute(s, part + s[cur], course, cur + 1, k + 1);

//     // not choice
//     brute(s, part, course, cur + 1, k);
// }

// bool comp(pair<string, int> &p1, pair<string, int> &p2) {
//     if (p1.first.length() != p2.first.length())
//         return p1.first.length() < p2.first.length();
//     return p1.second > p2.second;
// }

// vector<string> solution(vector<string> orders, vector<int> course) {
//     vector<string> answer;

//     for (int i = 0; i < orders.size(); i++) {
//         sort(orders[i].begin(), orders[i].end());
//         brute(orders[i], "", course, 0, 0);
//     }

//     vector<pair<string, int>> v;
//     auto it = mp.begin();
//     for (; it != mp.end(); it++) {
//         if (it->second >= 2) v.push_back({it->first, it->second});
//     }

//     sort(v.begin(), v.end(), comp);

//     int curSize = -1, curMax;
//     for (int i = 0; i < v.size(); i++) {
//         if (curSize != v[i].first.length()) {
//             curSize = v[i].first.length(), curMax = v[i].second;
//         }

//         if (curMax == v[i].second) answer.push_back(v[i].first);
//     }
//     sort(answer.begin(), answer.end());

//     return answer;
// }

#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

void brute(const string &src, string sub, int k, int depth) {
    if (sub.length() == depth) {
        mp[sub]++;
        return;
    }

    for (int i = k; i < src.length(); i++) {
        brute(src, sub + src[i], i + 1, depth);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }

    for (int i = 0; i < course.size(); i++) {
        for (int j = 0; j < orders.size(); j++)
            brute(orders[j], "", 0, course[i]);

        int maxv = -1;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            maxv = max(maxv, it->second);
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (maxv == it->second && it->second >= 2) {
                answer.push_back(it->first);
            }
        }

        mp.clear();
    }

    sort(answer.begin(), answer.end());

    return answer;
}