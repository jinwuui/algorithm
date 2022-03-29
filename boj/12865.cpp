#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
#define W first
#define V second
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void debug(vector<vector<int>> &v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << sp;
		}
		cout << endl;
	}
	cout << endl;
}
void debug(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << sp;
	}
	cout << endl;
} 


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> dp(k + 1);
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		for (int j = k; j >= w; j--)
			dp[j] = max(dp[j], dp[j - w] + v);
		debug(dp);
	}

	cout << *max_element(dp.begin(), dp.end());
	return 0;
}