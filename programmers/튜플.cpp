#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> split(string s, char deli) {
	istringstream iss(s);
	string sb; vector<int> ret;
	ret.clear();
	while (getline(iss, sb, deli))
        ret.push_back(stoi(sb));
	return ret;
}

vector<vector<int>> parse(string s) {
    vector<vector<int>> v;
    int sidx = 2;
    string longs = "";
    while (sidx < s.length()) {
        int eidx = s.find('}', sidx);
        string slice = s.substr(sidx, eidx - sidx);
        sidx = eidx + 3;

        vector<int> splitv = split(slice, ',');
        sort(splitv.begin(), splitv.end());
        v.push_back(splitv);
    }
    return v;
}

bool comp(vector<int> &v1, vector<int> &v2) {
    return v1.size() < v2.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> result = parse(s);

    sort(result.begin(), result.end(), comp);

    answer.push_back(result[0][0]);
    
    for (int i = 1; i < result.size(); i++) {
        bool findDifferent = false;
        for (int j = 0; j < result[i].size() - 1; j++) {
            if (result[i][j] != result[i - 1][j]) {
                findDifferent = true;
                answer.push_back(result[i][j]);
                break;
            }
        }

        if (!findDifferent)
            answer.push_back(result[i][result[i].size() - 1]);
    }

    return answer;
}