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

	if (s[0] == 'A' && s[2] == 'C') {
		for (int i = 0; i < s.length(); i++) {
			if (i == 0 || i == 2) continue;

			if ('B' <= s[i] && s[i] <= 'Z') {
				cout << "WA";
				return 0;
			}
		}
		cout << "AC";
	} else {
		cout << "WA";
	}

	return 0;
}