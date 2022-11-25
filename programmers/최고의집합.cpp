#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if (n > s) return vector<int>(1, -1);
    vector<int> answer(n, s / n);
    for (int i = 0; i < s % n; i++) answer[n - i - 1]++;
    return answer;
}