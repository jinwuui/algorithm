#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define L first
#define R second

string solution(int n, int k, vector<string> cmd) {
	stack<int> del;
	vector<pii> v(n + 2);

	for (int i = 0; i < n; i++)
		v[i] = {i - 1, i + 1};
	v[0].L = -1;
	v[n - 1].R = -1;

	int updown = 0, cur = k;
	for (int i = 0; i < cmd.size(); i++) {
		string s = cmd[i];

		if (s[0] == 'U') {
			int val = stoi(s.substr(2, s.length() - 2));
			while (val-- && cur != v[cur].L) cur = v[cur].L;

		} else if (s[0] == 'D') {
			int val = stoi(s.substr(2, s.length() - 2));
			while (val-- && cur != v[cur].R) cur = v[cur].R;
			
		} else if (s[0] == 'C') {
			del.push(cur);
            if (v[cur].R == -1) {
                int prev = v[cur].L;
                v[prev].R = -1;
                cur = prev;
            } else if (v[cur].L == -1) {
                int next = v[cur].R;
                v[next].L = -1;
                cur = next;
            } else {
                int prev = v[cur].L, next = v[cur].R;
                v[prev].R = next;
                v[next].L = prev;
                cur = next;
            }

		} else {
			int revi = del.top(); del.pop();
			int prev = v[revi].L, next = v[revi].R;
			if (prev != -1) v[prev].R = revi;
			if (next != -1) v[next].L = revi;
		}
	}

	vector<char> ans(n, 'O');
	while (del.size()) {
		int pos = del.top();
        del.pop();
		ans[pos] = 'X';
	}

	return string(ans.begin(), ans.end());
}