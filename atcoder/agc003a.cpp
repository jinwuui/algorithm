#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string str;
	cin >> str;

	int n, w, s, e;
	n = w = s = e = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'N') {
			n++;
		} else if (str[i] == 'S') {
			s++;
		} else if (str[i] == 'W') {
			w++;
		} else {
			e++;
		}
	}
	
	if (((n + s) && (n * s == 0)) || ((w + e) && (w * e == 0))) {
		cout << "No";
	} else {
		cout << "Yes";
	}

	return 0;
}