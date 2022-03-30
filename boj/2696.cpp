#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << (n / 2) + (n % 2 == 1) << endl;
		priority_queue<int, vector<int>, less<int>> lq;
		priority_queue<int, vector<int>, greater<int>> rq;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int cur; cin >> cur;
			
			if (lq.empty() || lq.top() >= cur) {
				lq.push(cur);
			} else {
				rq.push(cur);
			}

			if (lq.size() > rq.size() + 1) {
				rq.push(lq.top());
				lq.pop();
			} else if (lq.size() < rq.size()) {
				lq.push(rq.top());
				rq.pop();
			}

			if (i % 2 == 0) {
				cout << lq.top() << " ";
				cnt++;
				if (cnt == 10) {
					cout << endl;
					cnt = 0;
				}
			}
		}
		cout << endl;
	}

	return 0;
}