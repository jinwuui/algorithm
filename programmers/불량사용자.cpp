#include <bits/stdc++.h>

using namespace std;
set<vector<int>> st;
vector<int> v;

bool match(string &user, string &ban) {
	if (user.length() != ban.length()) return false;

	for (int i = 0; i < user.length(); i++) {
		if (ban[i] == '*') continue;
		if (ban[i] != user[i]) return false;
	}
	return true;
}

void solve(vector<string> &user_id, vector<string> &banned_id, int cnt) {
	if (cnt == banned_id.size()) {
		vector<int> copy(v);
		sort(copy.begin(), copy.end());
		st.insert(copy);
		return;
	}

	for (int i = 0; i < user_id.size(); i++) {
		string user = user_id[i];
		string ban = banned_id[cnt];
        
        if (find(v.begin(), v.end(), i) != v.end()) continue;
		if (!match(user, ban)) continue;

		v.push_back(i);
		solve(user_id, banned_id, cnt + 1);
		v.pop_back();
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	solve(user_id, banned_id, 0);
	return st.size();
}