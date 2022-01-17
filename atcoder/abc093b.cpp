#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b, k;
	cin >> a >> b >> k;

	if (k + k >= b - a + 1) {
		for (int i = a; i <= b; i++) {
			cout << i << endl;
		}
	} else {
		for (int i = a; i < a + k; i++) {
			cout << i << endl;
		}
		for (int i = b - k + 1; i <= b; i++) {
			cout << i << endl;
		}
	}
	

	return 0;
}