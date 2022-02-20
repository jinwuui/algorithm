// #include <bits/stdc++.h>
// #define endl '\n'
// #define sp ' '
// using namespace std;
// using ll = long long;
// using pii = pair<int, int>;

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

// 	ll n, m = 0;
// 	cin >> n;

// 	vector<ll> v(n + 1);
// 	for (int i = 0; i < n + 1; i++) {
// 		cin >> v[i];
// 		m += v[i];
// 	}

// 	ll one = 0, two;
// 	for (int i = 0; i < n; i++) {
// 		cin >> two;

// 		v[i] -= one;
// 		if (v[i] > 0) {
// 			ll minv = min(v[i], two);
// 			v[i] -= minv;
// 			two -= minv;
// 		} else v[i] = 0;
// 		one = two;

// 		// for (int j = 0; j < n + 1; j++) {
// 		// 	cout << v[j] << sp;
// 		// }
// 		// cout << endl;
// 	}
// 	v[v.size() - 1] = v[v.size() - 1] > one ? v[v.size() - 1] - one : 0;
// 	ll sum = 0;
// 	for (int i = 0; i < n + 1; i++) {
// 		sum += v[i];
// 	}
// 	cout << m - sum;
// 	return 0;
// }
#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> m(n + 1);
	for (int i = 0; i < n + 1; i++) {
		cin >> m[i];
	}

	vector<int> h(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	ll sum = 0;
	for (int i = 0; i < n + 1 ; i++) {
		int minv = min(m[i], h[i]);
		m[i] -= minv;
		h[i] -= minv;
		sum += minv;

		minv = min(m[i], h[i + 1]);
		m[i] -= minv;
		h[i + 1] -= minv;
		sum += minv;
	}
	cout << sum;
	return 0;
}