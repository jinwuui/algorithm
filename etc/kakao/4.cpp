#include <string>
#include <vector>
#include <iostream>

using namespace std;

int apeach[11], maxv = 0;
int lion[11];
int save[11];

int cal() {
	int scoreL = 0, scoreA = 0;

	for (int i = 0; i < 11; i++) {
		if (lion[i] > apeach[i]) {
			scoreL += i;
		}
		else if (lion[i] < apeach[i]) {
			scoreA += i;
		}
		else if (lion[i] != 0 && lion[i] == apeach[i]) {
			scoreA += i;
		}
	}

	return scoreL - scoreA;
}

void swap() {
	for (int i = 0; i < 11; i++) {
		if (lion[i] > save[i]) {
			for (int j = 0; j < 11; j++) {
				save[j] = lion[j];
			}
			return;
		}
		else if (lion[i] < save[i]) {
			return;
		}
	}
}

void solve(int cnt, int n, int idx) {
	if (idx == 0 && cnt != n) {
		lion[idx] = n - cnt;
		cnt = n;
	}
	if (cnt == n) {
		int score = cal();
		if (score >= maxv) {
			if (score == maxv) swap();
			else {
				for (int i = 0; i < 11; i++) {
					save[i] = lion[i];
				}
			}
			maxv = score;
		}

		lion[0] = 0;
		return;
	}

	for (int i = 0; i <= n - cnt; i++) {
		lion[idx] = i;
		solve(cnt + i, n, idx - 1);
		lion[idx] = 0;
	}
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
	for (int i = 0; i < 11; i++) {
		apeach[10 - i] = info[i];
	}

	solve(0, n, 10);

	if (maxv == 0) answer.push_back(-1);
	else {
		for (int i = 10; i >= 0; i--)
			answer.push_back(save[i]);
	}
    return answer;
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < 11; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	vector<int> ans = solution(n, v);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}

/*
5 2 1 1 1 0 0 0 0 0 0 0
1 1 0 0 0 0 0 0 0 0 0 0 
9 0 0 1 2 0 1 1 1 1 1 1 
*/
