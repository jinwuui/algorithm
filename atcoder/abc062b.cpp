#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int r, c;
	cin >> r >> c;
	
	for (int i = 0; i < c + 2; i++) {
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c + 2; j++) {
			if (j == 0 || j >= c + 1) cout << "#";
			else  {
				char tmp; cin >> tmp;
				cout << tmp;
			}
		}
		cout << endl;
	}
	for (int i = 0; i < c + 2; i++) {
		cout << "#";
	}
	

	return 0;
}