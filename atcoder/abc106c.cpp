#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int k;
	cin >> k;
	vector<int> v(s.length());
	for (int i = 0; i < k - 1; i++) {
		if (s[i] != '1') {
			cout << s[i];
			return 0;
		}
	}
	cout << s[k - 1];

	return 0;
}