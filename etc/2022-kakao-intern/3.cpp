#include <bits/stdc++.h>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
	int ans = 0;
	vector<int> maxv = {-1, -1, -1, -1, -1};
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	vector<vector<int>> can;

	for (int i = 0; i < problems.size(); i++) {
		pq.push(problems[i]);
		if (maxv < problems[i]) maxv = problems[i];
	}

	while (pq.size()) {
		vector<int> cur = pq.top();

		cout << cur[0] << " "  << cur[1] << " "  << cur[2] << " "  << cur[3] << " "  << cur[4] << " " << endl;
		
		// 문제 못품 -> 수련 필요
		if (cur[0] > alp && cur[1] > cop) {
			int ga = cur[0] - alp, gc = cur[1] - cop;

			int need = ga + gc, needIdx = -1, needCnt = -1;
			for (int i = 0; i < can.size(); i++) {
				vector<int> prob = can[i];
				int cnt = max(ga / prob[2] + ((ga % prob[2]) != 0), gc / prob[3] + ((gc % prob[3]) != 0));
				int tmp = cnt * prob[4];
				if (need > tmp) {
					need = tmp;
					needIdx = i, needCnt = cnt;
				}
			}

			if (needIdx == -1) {
				ans += need;
				alp = cur[0], cop = cur[1];
				cout << "	노가다 " << alp << " " << cop << endl;
			} else {
				ans += need;
				alp = needCnt * can[needIdx][2];
				cop = needCnt * can[needIdx][3];
				cout << "	독서  " << can[needIdx][0] << " "  << can[needIdx][1] << " "  << can[needIdx][2] << " "  << can[needIdx][3] << " "  << can[needIdx][4] << " " << endl;
			}
		}
		
		// 문제 풀수 있음 -> can 에 저장
		// } else {
			can.push_back(cur);
			pq.pop();
		// }
	}

	return ans;
}