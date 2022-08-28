#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id, vector<string> v, int k) {
    vector<int> ans;
    map<string, int> mp;
	map<string, int> ansmp;
	map<string, vector<string>> list;
	set<string> st;
	set<string> log;
    
    for (int i = 0; i < v.size(); i++) {
		if (log.find(v[i]) == log.end()) {
			log.insert(v[i]);
			int idx = v[i].find(" ");
			string caller = v[i].substr(0, idx);
			string bad = v[i].substr(idx + 1, v[i].length());

			mp[bad]++;
			list[bad].push_back(caller);
		}
    }
	for (int i = 0; i < id.size(); i++) {
		string s = id[i];
		if (mp[s] >= k) st.insert(bad);
	}

	int buf[id.size()];
	memset(buf, 0, sizeof(buf));
	for (int i = 0; i < id.size(); i++) {
		string s = id[i];
		if (st.find(s) != st.end()) {
			for (int j = 0; j < list[s].size(); j++) {
				ansmp[list[s][j]]++;
			}
		}
	}

	for (int i = 0; i < id.size(); i++) {
		ans.push_back(ansmp[id[i]]);
	}
    
    return ans;
}