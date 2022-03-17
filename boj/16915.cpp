#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '

using namespace std;

vector<int> st(222222);
vector<int> buf(111111);
vector<vector<int>> room(111111, vector<int>());

int findSet(int val) {
	if (val == st[val]) return val;
	return st[val] = findSet(st[val]);
}

void unionSet(int a, int b) {
	int ap = findSet(a);
	int bp = findSet(b);
	st[ap] = bp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	iota(st.begin(), st.end(), 0);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> buf[i];
	}

	for (int i = 1; i <= m; i++) {
		int tmp; cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			int r;
			cin >> r;
			room[r].push_back(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		int on1 = room[i][0] * 2 - 1, off1 = room[i][0] * 2;
		int on2 = room[i][1] * 2 - 1, off2 = room[i][1] * 2;
		if (buf[i]) {
			if (findSet(on1) != findSet(on2)) unionSet(on1, on2);
			if (findSet(off1) != findSet(off2)) unionSet(off1, off2);
		} else {
			if (findSet(on1) != findSet(off2)) unionSet(on1, off2);
			if (findSet(off1) != findSet(on2)) unionSet(off1, on2);
		}
	}
	
	for (int i = 1; i <= m; i++) {
		if (findSet(i * 2) == findSet(i * 2 + 1)) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;

	return 0;
}