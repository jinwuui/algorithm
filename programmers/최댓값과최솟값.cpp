#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string s, char deli) {
    istringstream iss(s);
    string sb;
    vector<string> ret;
    ret.clear();
    while (getline(iss, sb, deli)) ret.push_back(sb);
    return ret;
}

string solution(string s) {
    vector<string> splited = split(s, ' ');
    int minv = 1e9, maxv = -1e9;
    for (int i = 0; i < splited.size(); i++) {
        int cur = stoi(splited[i]);
        minv = min(minv, cur);
        maxv = max(maxv, cur);
    }

    return to_string(minv) + " " + to_string(maxv);
}