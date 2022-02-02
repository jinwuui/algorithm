#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

bool arr[2000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int x;
	cin >> x;

	arr[1] = true;
	for (int i = 2; i < 33; i++) {
		int cur = i * i;
		while (cur < 2000) {
			arr[cur] = true;
			cur *= i;
		}
	}

	while (!arr[x]) {
		x--;
	}
	cout << x;

	return 0;
}