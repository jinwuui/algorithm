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
	vector<int> v(n);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	int t;
	cin >> t;
	while (t--) {
		int idx, save;
		cin >> idx >> save;
		idx--;
		cout << sum - v[idx] + save << endl;
	}
	
	return 0;
}