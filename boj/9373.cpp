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

struct Node {
	ll x, y;
	double r;
	Node() {}
	Node(ll nx, ll ny, double nr) {
		x = nx, y = ny, r = nr;
	}
};

vector<int> grp;

int findSet(int a) {
	if (a == grp[a]) return a;
	return grp[a] = findSet(grp[a]);
}

void unionSet(int a, int b) {
	int ap = findSet(a);
	int bp = findSet(b);
	grp[bp] = ap;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int w, n;
		cin >> w >> n;

		if (n == 0) {
			cout << w / 2.0 << endl;
			continue;
		}

		vector<Node> v(n);
		grp.resize(n + 2);
		iota(grp.begin(), grp.end(), 0);

		for (int i = 0; i < n; i++) {
			ll x, y, r;
			cin >> x >> y >> r;

			v[i] = Node(x, y, r);
		}

		vector<pair<double, pii>> edge;
		for (int i = 0; i < v.size() - 1; i++) {
			Node cur = v[i];
			for (int j = i + 1; j < v.size(); j++) {
				Node nx = v[j];
				double dist = sqrt((cur.x - nx.x) * (cur.x - nx.x) + (cur.y - nx.y) * (cur.y - nx.y)) - cur.r - nx.r;
				edge.push_back({dist, {i, j}});
			}
		}

		for (int i = 0; i < v.size(); i++) {
				edge.push_back({v[i].x - v[i].r, {n, i}});
				edge.push_back({w - v[i].x - v[i].r, {n + 1, i}});
		}
		
		sort(edge.begin(), edge.end());

		for (int i = 0; i < edge.size(); i++) {
			if (findSet(edge[i].second.first) == findSet(edge[i].second.second)) continue;

			unionSet(edge[i].second.first, edge[i].second.second);

			if (findSet(n) == findSet(n + 1)) {
				if (edge[i].first < 0) cout << 0 << endl;
				else {
					cout << fixed;
					cout.precision(6);	
					cout << edge[i].first / 2 << endl;
				}
				break;
			}
		}
	}
	
	return 0;
}