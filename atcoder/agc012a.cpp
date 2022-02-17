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
	vector<int> v(3 * n);

	for (int i = 0; i < 3 * n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	ll sum = 0;
	for (int i = 0; i < 2 * n ; i+=2) {
		sum += v[3 * n - i - 2];
	}
	cout << sum;
	return 0;
}