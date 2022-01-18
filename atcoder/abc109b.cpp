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
	bool ans = true;
	set<string> st;
	string prev;
	cin >> prev;
	st.insert(prev);
	for (int i = 1; i < n; i++) {
		string w;
		cin >> w;

		if (w[0] != prev[prev.length() - 1] || st.find(w) != st.end()) ans = false;

		prev = w;
		st.insert(w);
	}

	cout << (ans ? "Yes" : "No");

	return 0;
}