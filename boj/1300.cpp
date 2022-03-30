#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	int n, k;
	cin >> n >> k;

	ll sk = sqrt(k);
	ll tmp = sk * sk;
	if (tmp == k) {
		cout << tmp;
	} else {
		k -= tmp;
		vector<ll> v;
		int cnt = 0;
		for (int i = 1; i <= sk; i++) {
			v.push_back((sk + 1) * i);
			v.push_back((sk + 1) * i);
			cnt += 2;
			if (cnt >= k) {
				cout << v.back();
				return 0;
			}
		}
		v.push_back((sk + 1) * (sk + 1));
	}

	return 0;
}