#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<string> split(string s, char deli) {
	istringstream iss(s);
	string sb; vector<string> ret;
	ret.clear();
	while (getline(iss, sb, deli)) ret.push_back(sb);
	return ret;
}

int convertToSeconds(string &time) {
	vector<string> tv = split(time, ':');
	return stoi(tv[0]) * 3600 + stoi(tv[1]) * 60 + stoi(tv[2]);
}

string convertToTime(ll sec) {
    string h = to_string(sec / 3600);
    if (h.length() < 2) h = "0" + h;
    
    string m = to_string(sec % 3600 / 60);
    if (m.length() < 2) m = "0" + m;
    
    string s = to_string(sec % 60);
    if (s.length() < 2) s = "0" + s;
    
    return h + ":" +  m + ":" + s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
	int play = convertToSeconds(play_time);
	int adv = convertToSeconds(adv_time);

	vector<int> log(play + 1);
	vector<int> buf(play + 1);
	for (int i = 0; i < logs.size(); i++) {
		vector<string> tmp = split(logs[i], '-');
		int s = convertToSeconds(tmp[0]);
		int e = convertToSeconds(tmp[1]);

		log[s]++;
		log[e]--;
	}

	ll sum = 0;
	int val = 0;
	for (int i = 0; i < adv; i++) {
		val += log[i];
		sum += val;
		buf[i] = val;
	}

	ll maxv = max(0LL, sum);
    int ans = 0;
	for (int i = adv; i < play; i++) {
		val += log[i];
		sum += val - buf[i - adv];
		buf[i] = val;

        if (maxv < sum) {
            maxv = sum;
            ans = i - adv + 1;
        }
	}

	return convertToTime(ans);
}