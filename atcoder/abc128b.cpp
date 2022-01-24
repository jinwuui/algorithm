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
	vector<pair<string, pair<int, int>>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second.first;
		v[i].second.first = -v[i].second.first;
		v[i].second.second = i;
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		cout << v[i].second.second + 1 << endl;
	}

	return 0;
}