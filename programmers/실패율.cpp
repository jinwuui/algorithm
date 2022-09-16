#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> cnt(N + 2);
    vector<pair<double, int>> arr;
    for (int i = 0; i < stages.size(); i++)
        cnt[stages[i]]++;
    
    int user = cnt[N + 1];
    for (int i = N; i > 0; i--) {
        user += cnt[i];
        if (user == 0) arr.push_back({0.0, i});
        else
            arr.push_back({-(cnt[i] * 1.0 / user), i});
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
        answer.push_back(arr[i].second);
    return answer;
}