#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    vector<int> weapon(number + 1);
    int answer = 0;
    for (int i = 1; i <= number; i++) {
        weapon[i]++;
        for (int j = i * 2; j <= number; j += i) weapon[j]++;
        answer += weapon[i] > limit ? power : weapon[i];
    }

    return answer;
}