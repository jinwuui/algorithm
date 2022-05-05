#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
	map<string, int> mp;

	int kinds = 0;
	vector<int> v;
	for (int i = 0; i < gems.size(); i++) {
		int idx = kinds + 1;
		if (mp.find(gems[i]) == mp.end()) {
			mp[gems[i]] = ++kinds;
		} else {
			idx = mp[gems[i]];
		}
        v.push_back(idx);
	}

	int s = 0, e = 0, val = 1;
	int mins = -1e9, mine = 1e9;
	vector<int> cnt(v.size() + 1);
	cnt[v[e]]++;
    while (e < v.size()) {
        if (val < kinds) {
			e++;
			if (e == v.size()) break;
			cnt[v[e]]++;
			if (cnt[v[e]] == 1) {
				val++;
			}
		} else {
			if (mine - mins > e - s || (mine - mins == e - s && mins > s)) {
				mine = e;
				mins = s;
			}
			cnt[v[s]]--;
			s++;
			if (cnt[v[s - 1]] == 0) {
				val--;
			}
		}
    }

	answer[0] = mins + 1;
	answer[1] = mine + 1;

    return answer;
}