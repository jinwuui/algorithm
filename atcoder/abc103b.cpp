#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string s, t;
	cin >> s >> t;
	string s2 = s + s;
	
	for (int i = 0; i < s.length(); i++) {
		int j = 0;
		for (; j < t.length(); j++) {
			if (s2[i + j] != t[j]) break;
		}
		if (j == t.length()) {
			cout << "Yes";
			return 0;
		}
	}

	cout << "No";

	return 0;
}