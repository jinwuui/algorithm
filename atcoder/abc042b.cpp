#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, l;
	cin >> n >> l;
	vector<string> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		cout << v[i];
	}
	

	return 0;
}