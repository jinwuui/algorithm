#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;
using pii = pair<int, int>;

int ans[10000];
pii mp[10000];
int vis[10000];
int cars[10000];

vector<string> split(string str, char c) {
	vector<string> ret;
	stringstream ss(str);
	string tmp;

	while (getline(ss, tmp, c)) {
		ret.push_back(tmp);
	}

	return ret;
}

int cal(int gt, int gc, int ut, int uc, int sum) {
	int ret = 0;
	ret += gc;
	sum -= gt;

	if (sum > 0) {
		sum--;
		int cnt = sum / ut + 1;
		ret += cnt * uc;
	}
	return ret;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int gt = fees[0], gc = fees[1], ut = fees[2], uc = fees[3];

	for (int i = 0; i < records.size(); i++) {
		vector<string> rec = split(records[i], ' ');
		int car = stoi(rec[1]);
		int h = stoi(rec[0].substr(0, 2));
		int m = stoi(rec[0].substr(3, 5));

		if (rec[2] == "IN") {
			mp[car].first = h, mp[car].second = m;
			vis[car] = 1;
			cars[car] = 1;
		}
		else {	// "OUT"
			int start = mp[car].first * 60 + mp[car].second, sum;
			int end = h * 60 + m;

			ans[car] += end - start;
			vis[car] = 0;
		}
	}

	for (int i = 0; i < 10000; i++) {
		if (vis[i]) {
			int start = mp[i].first * 60 + mp[i].second, sum;
			int end = 23 * 60 + 59;
			ans[i] += end - start;
		}
	}

	for (int i = 0; i < 10000; i++) {
		if (cars[i])
			answer.push_back(cal(gt, gc, ut, uc, ans[i]));
	}
    return answer;
}

/*
16:00 3961 IN
16:00 0202 IN
18:00 3961 OUT
18:00 0202 OUT
23:58 3961 IN
120 0 60 591


05:34 5961 IN
06:00 0000 IN
06:34 0000 OUT
07:59 5961 OUT
07:59 0148 IN
18:59 0000 IN
19:09 0148 OUT
22:59 5961 IN
23:00 5961 OUT
180 5000 10 600
*/

int main() {
	vector<int> tmp1;
	vector<string> tmp2;

	for (int i = 0; i < 9; i++) {
		string tmp;
		getline(cin, tmp);
		tmp2.push_back(tmp);
	}

	for (int i = 0; i < 4; i++) {
		int tmp; cin >> tmp;
		tmp1.push_back(tmp);
	}

	vector<int> ans = solution(tmp1, tmp2);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}