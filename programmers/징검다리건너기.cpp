#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define IDX second
#define VAL first

vector<int> buf(200000);
vector<int> cnt(200000);
int maxCnt;

int findSet(int a) {
	if (a == buf[a]) return a;
	return buf[a] = findSet(buf[a]);
}

void unionSet(int a, int b) {
	int ap = findSet(a), bp = findSet(b);
	if (ap == bp) return;

	buf[ap] = bp;
	cnt[bp] += cnt[ap];
	maxCnt = max(maxCnt, cnt[bp]);
}

int solution(vector<int> stones, int k) {
	if (k == 1) return *min_element(stones.begin(), stones.end());
	
	iota(buf.begin(), buf.end(), 0);
	fill(cnt.begin(), cnt.end(), 1);

	long long ans = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;

	for (int i = 0; i < stones.size(); i++)
		pq.push({stones[i], i});

	int round = 0, prev = 0;
	while (true) {
        int val = pq.top().VAL;
        int idx = pq.top().IDX;
		pq.pop();

		stones[idx] = 0;
		ans += val - prev;
        prev = val;

		if (idx > 0 && stones[idx - 1] == 0) unionSet(idx, idx - 1);
		if (idx < stones.size() - 1 && stones[idx + 1] == 0) unionSet(idx, idx + 1);
		
		if (maxCnt >= k) break;
	}

	return ans;
}