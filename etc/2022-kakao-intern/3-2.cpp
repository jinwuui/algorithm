#include <bits/stdc++.h>
#define A first
#define C second
#define pii pair<int, int>
using namespace std;

int solution(int alp, int cop, vector<vector<int>> prob) {
	int answer = 1e9, n = prob.size();
	vector<vector<int>> can;
	vector<vector<int>> minw(200, vector<int>(200, 1e9));
	sort(prob.begin(), prob.end());

	minw[alp][cop] = 0;
	queue<pii> q;
	q.push({alp, cop});

	pii maxR = {alp, cop}, maxL = {alp, cop};
	pii bossR = {-1, -1}, bossL = {-1, -1};
	for (int i = 0; i < n; i++) {
		vector<int> cur = prob[i];
		if (bossR.A < cur[0] && bossR.C < cur[1])
		cout << i << " " << cur[0] << " " << cur[1] << endl;
		if ((cur[0] <= maxR.A && cur[1] <= maxR.C) || (cur[0] <= maxL.A && cur[1] <= maxL.C)) {
			if (cur[2] + cur[3] > cur[4]) can.push_back(cur);
			continue;
		}

		while (true) {
			int qsize = q.size();
			bool isChange = false;
			
			while (qsize--) {
				pii p = q.front(); q.pop();

				cout << "	" << p.A << " " << p.C << endl;
				if (cur[0] <= p.A && cur[1] <= p.C) {
					q.push({p.A, p.C});
					continue;
				}

				if (cur[0] > p.A && cur[1] > p.C &&
					minw[cur[0]][cur[1]] > minw[p.A][p.C] + (cur[0] - p.A) + (cur[1] - p.C)) {
					minw[cur[0]][cur[1]] = minw[p.A][p.C] + (cur[0] - p.A) + (cur[1] - p.C);
					q.push({cur[0], cur[1]});
				}

				for (int j = 0; j < can.size(); j++) {
					vector<int> exer = can[j];
					int newA = p.A + exer[2], newC = p.C + exer[3], time = exer[4];
					cout << "	new " << newA << " " << newC << endl;
					if (minw[newA][newC] <= minw[p.A][p.C] + time) continue;

					minw[newA][newC] = minw[p.A][p.C] + time;
					isChange = true;
					if (newA > newC && maxL.A >= newA && maxL.C >= newC) maxL = {newA, newC};
					if (newA <= newC && maxR.A >= newA && maxR.C >= newC) maxR = {newA, newC};
					q.push({newA, newC});
				}
			}

			if (!isChange) break;
		}

		cout << minw[20][20] << endl;
		if (cur[2] + cur[3] > cur[4])
			can.push_back(cur);
	}

	vector<int> boss = prob[prob.size() - 1];
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++) {
			// if (i >= boss[0] && j >= boss[1]) continue;
			bool isOk = true;
			for (int k = 0; k < prob.size(); k++) {
				if (prob[k][0] > i || prob[k][1] > j) isOk = false;
			}
			if (isOk)
				answer = min(answer, minw[i][j]);
		}
	}

	return answer;
}

int main() {

	vector<vector<int>> v;
	v.push_back({0,0,2,1,2});
	v.push_back({4,5,3,1,2});
	v.push_back({4,11,4,0,2});
	v.push_back({10,4,0,4,2});

	cout << solution(0, 0, v);
	return 0;
}