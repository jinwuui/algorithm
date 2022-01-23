#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a = -1, z = -1;
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (a == -1 && s[i] == 'A') {
			a = i;
		} else if (s[i] == 'Z') {
			z = i;
		}
	}
	cout << z - a + 1;
	return 0;
}