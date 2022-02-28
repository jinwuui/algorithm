#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;


int main() {
	int n;
	cin >> n;

	vector<vector<int>> v(n, vector<int>(3));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[i][j];
		}
	}

	vector<int> score(n);
	for (int i = 0; i < 3; i++) {
		vector<pii> cnt(101);
		for (int j = 0; j < n; j++) {
			cnt[v[j][i]].first++;
			cnt[v[j][i]].second = j;
		}

		for (int j = 0; j < 101; j++) {
			if (cnt[j].first == 1) score[cnt[j].second] += j;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << score[i] << endl;
	}

	return 0;
}