#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

string solution(vector<int> numbers, string hand) {
    char curl = , curr;
	string ans = "";
	vector<int> key(13);
	pii key[10] = {{3, 1},{0, 0},{0, 1},{0, 2},{1, 0},{1, 1},{1, 2},
					{2, 0},{2, 1},{2, 2},};

	int lval = 0, rval = 0;
	if (hand == "right") rval--;
	else lval--;

	pii l = {3, 0}, r = {3, 2};
    for (int i = 0; i < number.size(); i++) {
        int cur = number[i];

		if (cur == 1 || cur == 3 || cur == 7) {l = key[cur]; ans += "L"}

		if (cur == 3 || cur == 6 || cur == 9) {R = key[cur]; ans += "R"}

		if (cur == 2 || cur == 5 || cur == 8 || cur == 0) {
			int distl = abs(key[cur].first - l.first) + abs(key[cur].second - l.second) + lval;
			int distr = abs(key[cur].first - r.first) + abs(key[cur].second - r.second) + rval;
			if (distl < distr) { l = key[cur]; ans += "L";}
			else if (distl > distr) { r = key[cur]; ans += "R";}
		}
    }
	
    return ans;
}