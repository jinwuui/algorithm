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

int n, c, sqrtn, m;
vector<int> buf, v;
struct Picture {
	int s, e, n;
	Picture(): Picture(0, 0, -1) {}
	Picture(int s1, int e1, int n1): s(s1), e(e1), n(n1) {}

	bool operator <(const Picture &comp) const {
		if (s / sqrtn != comp.s / sqrtn) return s / sqrtn < comp.s / sqrtn;
		return e < comp.e;
	}
};

int isYes(vector<int> &v, int cnt) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > cnt)
			return i;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> c;
	v.resize(c);
	sqrtn = sqrt(n);
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		buf.push_back(--tmp);
	}

	cin >> m;
	Picture p[m];
	string result[m];
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		p[i] = Picture(--s, --e, i);
	}

	sort(p, p + m);
	
	int s = p[0].s, e = p[0].e;
	for (int i = s; i <= e; i++) {
		v[buf[i]]++;
	}
	int val = isYes(v, (e - s + 1) / 2);
	if (val != -1)
		result[p[0].n] = "yes " + to_string(val + 1);
	else
		result[p[0].n] = "no";


	for (int i = 1; i < m; i++) {
		while (p[i].s < s) {
			s--;
			v[buf[s]]++;
		}
		while (p[i].s > s) {
			v[buf[s]]--;
			s++;
		}
		while (p[i].e < e) {
			v[buf[e]]--;
			e--;
		}
		while (p[i].e > e) {
			e++;
			v[buf[e]]++;
		}
		int val = isYes(v, (e - s + 1) / 2);
		if (val != -1)
			result[p[i].n] = "yes " + to_string(val + 1);
		else
			result[p[i].n] = "no";
	}
	
	for (int i = 0; i < m; i++) {
		cout << result[i] << endl;
	}
	
	return 0;
}