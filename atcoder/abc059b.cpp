#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;


	if (a.length() != b.length()) {
		if (a.length() > b.length()) {
			cout << "GREATER";
		} else {
			cout << "LESS";
		}
	} else {
		if (a > b) {
			cout << "GREATER";
		} else if (a < b) {
			cout << "LESS";
		} else {
			cout << "EQUAL";
		}
	}

	return 0;
}