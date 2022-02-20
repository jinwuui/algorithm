#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int d, n;
	cin >> d >> n;
	if (d == 0) d = 1;
	else if (d == 1) d = 100;
	else d = 10000;

	cout << d * n + (n == 100) * d;
	return 0;
}