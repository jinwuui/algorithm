#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b;
	if (a > b) return gcd(b, a);
	return gcd(b % a, a);
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 1; i < n; i++) {
		int gcdv = gcd(v[0], v[i]);
		cout << v[0] / gcdv << "/" << v[i] / gcdv << endl;
	}

	return 0;
}