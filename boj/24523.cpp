
#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> ans(n + 1, -1);
	stack<pii> stk;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		while (!stk.empty() && stk.top().first != tmp) {
			ans[stk.top().second] = i;
			stk.pop();
		}
		stk.push({tmp, i});
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << sp;
	}
	return 0;
}