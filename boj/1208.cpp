#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
#define C first
#define X second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

int n, s;
ll result;

void solve(vector<int> &v, vector<int> &ans, int idx, int val, int choice) {
	if (idx >= v.size()) {
		if (choice) {
			ans.push_back(val);
			if (val == s) {
				result++;
				// cout << "find answer " << result << sp << val << endl;
			}
		}
		return;
	}
	
	// not choide
	solve(v, ans, idx + 1, val, choice);

	// choice
	solve(v, ans, idx + 1, val + v[idx], choice + 1);
}

/*
6 0
-7 -3 -2 5 8 3
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> s;

	vector<int> v1(n / 2);
	vector<int> v2(n / 2 + (n % 2));
	for (int i = 0; i < n / 2; i++) {
		cin >> v1[i];
	}
	for (int i = 0; i < n / 2 + (n % 2); i++) {
		cin >> v2[i];
	}
	
	vector<int> ans1;
	solve(v1, ans1, 0, 0, 0);
	vector<int> ans2;	
	solve(v2, ans2, 0, 0, 0);
	// for (int i = 0; i < ans1.size(); i++) {
	// 	cout << ans1[i] << sp;
	// }
	// cout << endl;
	// for (int i = 0; i < ans2.size(); i++) {
	// 	cout << ans2[i] << sp;
	// }
	
	sort(ans2.begin(), ans2.end());
	
	for (int i = 0; i < ans1.size(); i++) {

		int low = 0, high = ans2.size(), target = s - ans1[i];
		int aa = upper_bound(ans2.begin(), ans2.end(), target) - lower_bound(ans2.begin(), ans2.end(), target);
		if (aa) {
			// cout << "find answer " << aa << endl;
			result += aa;
		}
	}
	cout << result;
	// solve(v2);

	return 0;
}