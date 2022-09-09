#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int changeTimeTypeStringToInt(string &t) {
    int idx = t.find(":");
    int h = stoi(t.substr(0, idx));
    int m = stoi(t.substr(idx + 1, t.size()));

    return h * 60 + m;
}

string changeTimeTypeIntToString(int t) {
    int h = t / 60, m = t % 60;

    string result = h < 10 ? "0" + to_string(h) : to_string(h);
    result += ":" + (m < 10 ? "0" + to_string(m) : to_string(m));
    return result;
}

string solution(int n, int t, int m, vector<string> timetable) {
    int end = 9 * 60 + t * (n - 1);

    vector<int> v;
    for (int i = 0; i < timetable.size(); i++)
        v.push_back(changeTimeTypeStringToInt(timetable[i]));

    sort(v.begin(), v.end());

    int bus = 9 * 60, wait = 0;
    for (int i = 0; i < n - 1; i++) {
        wait = min((int)(upper_bound(v.begin(), v.end(), bus) - v.begin()), wait + m);
        bus += t;
    }

    int ans;
    if (wait + m - 1 < v.size())
        ans = min(v[wait + m - 1] - 1, bus);
    else
        ans = bus;

    return changeTimeTypeIntToString(ans);
}