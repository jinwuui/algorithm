#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string n;
	cin >> n;

	if (n.length() == 1) {
		cout << n;
	} else {
		int maxv = (n.length() - 1) * 9;

		int sum = 0;
		for (int i = 0; i < n.length(); i++) {
			sum += n[i] - '0';
		}
		maxv = max(maxv, sum);

		for (int i = n.length() - 1; i > 0; i--) {
			sum = sum - 1 - (n[i] - '0') + 9;
			cout << sum << endl;
			n[i - 1] = (char)(n[i - 1] - 1);
			maxv = max(maxv, sum);
		}
		cout << maxv;
	}

	return 0;
}