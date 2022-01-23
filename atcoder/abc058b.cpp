#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string o, e;
	cin >> o >> e;

	for (int i = 0; i < o.length() + e.length(); i++) {
		if (i % 2) {
			cout << e[i / 2];
		} else {
			cout << o[i / 2];
		}
	}

	return 0;
}