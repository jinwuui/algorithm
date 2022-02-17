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
	int prev;
	cin >> prev;

	for (int i = 1; i < n; i++) {
		int cur;
		cin >> cur;
		if (cur < prev) 

		prev = cur;
	}
	return 0;
}