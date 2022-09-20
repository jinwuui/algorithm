#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, pair<int, set<pair<int, int>>>> mp;
    for (int i = 0; i < genres.size(); i++) {
        mp[genres[i]].first -= plays[i];
        mp[genres[i]].second.insert({-plays[i], i});
    }

    vector<pair<int, set<pair<int, int>>>> order;
    for (auto it = mp.begin(); it != mp.end(); it++)
        order.push_back(it->second);
    sort(order.begin(), order.end());

    vector<int> answer;
    for (int i = 0; i < order.size(); i++) {
        auto setIt = order[i].second.begin();
        answer.push_back(setIt->second);
        setIt++;
        if (setIt != order[i].second.end())
            answer.push_back(setIt->second);
    }

    return answer;
}