#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	for (int i = 8; i <= 1000; i++) {
		if ((int)(i * 0.08) == a && (int)(i * 0.1) == b) {
			cout << i;
			return 0;
		}
	}
	cout << -1;

	return 0;
}