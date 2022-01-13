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
	int b = 0;
	int w = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i % 2) {
			if (s[i] == '1') b++;
			else w++;
		} else {
			if (s[i] == '1') w++;
			else b++;
		}
	}
	cout << min(w, b);

	return 0;
}