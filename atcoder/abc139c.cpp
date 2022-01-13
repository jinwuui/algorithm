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
	int prev, cnt = 0, maxv = 0;
	cin >> prev;
	for (int i = 1; i < n; i++) {
		int tmp;
		cin >> tmp;

		if (prev < tmp) {
			cnt = 0;
		} else {
			cnt++;
		}
		prev = tmp;
		maxv = max(maxv, cnt);
	}

	cout << maxv;
	return 0;
}