#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int sum = 0;
	int less = min(x, y);
	if (a + b > 2 * c) {
		sum += less * 2 * c;
	} else {
		sum += less * a + less * b;
	}

	sum += (x - less) * a + (y - less) * b;
	if (sum > max(x, y) * 2 * c) {
		cout << max(x, y) * 2 * c;
	} else {
		cout << sum;
	}
	return 0;
}