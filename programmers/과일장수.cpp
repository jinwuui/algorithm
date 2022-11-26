#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end());
    int answer = 0;
    for (int i = score.size() - m; i >= 0; i -= m) answer += m * score[i];
    return answer;
}