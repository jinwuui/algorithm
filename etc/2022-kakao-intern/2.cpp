#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> q1, vector<int> q2) {
	int ans = 0, sum1 = 0, sum2 = 0, i1 = 0, i2 = 0, maxv = q1.size();
	for (int i = 0; i < q1.size(); i++) sum1 += q1[i];
	for (int i = 0; i < q2.size(); i++) sum2 += q2[i];
	
	if ((sum1 + sum2) % 2 == 1) return -1;

	int cnt = 0;
	while (true) {
		if (sum1 == sum2) return ans;
		if (cnt > maxv * 3) return -1;

		int tmp1 = q1[i1], tmp2 = q2[i2];
		int gap1 = abs((sum1 - tmp1) - sum2);
		int gap2 = abs((sum2 - tmp2) - sum1);

		if (gap1 < gap2) {
			sum1 -= tmp1;
			q2.push_back(tmp1);
			i1++;
		} else {
			sum2 -= tmp2;
			q1.push_back(tmp2);
			i2++;
		}

		cnt++;
	}

	return -1;
}