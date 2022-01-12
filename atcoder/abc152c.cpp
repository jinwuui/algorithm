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

	vector<pii> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());

	int minidx = v[0].second, cnt = 1;
	for (int i = 1; i < n; i++) {
		if (v[i].second < minidx) {
			minidx = v[i].second;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}