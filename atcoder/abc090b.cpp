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
	int cnt = 0;
	for (int i = a; i <= b; i++) {
		string s = to_string(i);
		string tmp = s;
		reverse(s.begin(), s.end());
		if (tmp == s) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}