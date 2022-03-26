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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	priority_queue<int, vector<int>, less<int>> lq;
	priority_queue<int, vector<int>, greater<int>> rq;
	int tmp;
	cin >> tmp;
	lq.push(tmp);
	for (int i = 1; i < n; i++) {
		cout << lq.top() << endl;
		cin >> tmp;
		if (tmp > lq.top()) rq.push(tmp);
		else lq.push(tmp);

		if (lq.size() < rq.size()) {
			lq.push(rq.top());
			rq.pop();
		} else if (lq.size() > rq.size() + 1) {
			rq.push(lq.top());
			lq.pop();
		}
	}
	cout << lq.top();

	return 0;
}