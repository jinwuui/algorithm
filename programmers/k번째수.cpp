#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> ans;

    for (int i = 0; i < commands.size(); i++) {
        int s = commands[i][0], e = commands[i][1], target = commands[i][2];

        vector<int> tmp(e - s + 1);
        copy(array.begin() + s - 1, array.begin() + e, tmp.begin());
        sort(tmp.begin(), tmp.end());
        ans.push_back(tmp[target - 1]);
    }

    return ans;
}