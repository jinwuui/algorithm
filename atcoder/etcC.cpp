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

	if (n >= 2000) {
		cout << "1";
	} else {
		if (n / 100 * 5 < n % 100 || n < 100) {
			cout << "0";
		} else {
			cout << "1";
		}
	}

	return 0;
}