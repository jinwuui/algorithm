#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a]++;
		v[b]++;
	}
	for (int i = 1; i <= n; i++) {
		cout << v[i] << endl;
	}

	return 0;
}