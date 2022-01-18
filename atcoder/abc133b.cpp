#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, d;
	cin >> n >> d;
	vector<vector<int>> v(n, vector<int>(d));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			cin >> v[i][j];
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = 0;
			for (int k = 0; k < d; k++) {
				sum += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
			}

			int sqr = (int)(sqrt((double)sum));
			if (sqr * sqr == sum) cnt++;
		}
	}
	cout << cnt;

	return 0;
}