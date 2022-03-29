
#include <bits/stdc++.h>
#define R first
#define C second
#define W first
#define ND second
#define endl '\n'
#define sp ' '
#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, start, n) for (int i = start; i < (n); i++)
#define all(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};
const int MOD = 1000000007; 
vector<string> split(string s, char deli) {
	istringstream iss(s);
	string sb; vector<string> ret;
	ret.clear();
	while (getline(iss, sb, deli)) ret.push_back(sb);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s, protocol, host, port, path;
		cin >> s;

		protocol = s.substr(0, s.find(':'));
		s = s.substr(s.find(':') + 3, s.size() - (s.find(':') + 3));

		if (s.find(':') != string::npos && s.find('/') != string::npos && s.find(':') > s.find('/')) {
			host = s.substr(0, s.find('/'));
			port = "<default>";
			path = s.substr(s.find('/') + 1, s.size() - s.find('/'));
		} else {
			vector<string> v = split(s, ':');
			if (v.size() == 1) {
				port = "<default>";
				if (v[0].find('/') == string::npos) {
					host = v[0];
					path = "<default>";
				} else {
					host = v[0].substr(0, v[0].find('/'));
					path = v[0].substr(v[0].find('/') + 1, v[0].size() - v[0].find('/'));
				}
			} else {
				host = v[0];
				if (v[1].find('/') == string::npos) {
					port = v[1];
					path = "<default>";
				} else {
					port = v[1].substr(0, v[1].find('/'));
					path = v[1].substr(v[1].find('/') + 1, v[1].size() - v[1].find('/'));
					for (int j = 2; j < v.size(); j++)
						path += ":" + v[j];
				}
			}
		}

		cout << "URL #" << i << endl;
		cout << "Protocol = " << protocol << endl;
		cout << "Host     = " << host << endl;
		cout << "Port     = " << port << endl;
		cout << "Path     = " << path << endl << endl;
	}
	return 0;
}