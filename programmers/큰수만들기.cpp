#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int cnt = 0;
    for (int i = 1; i < number.length() && cnt < k; i++) {
        if (number[i - 1] < number[i]) {
            number.erase(i - 1, 1);
            cnt++;
            i = 0;
        }
    }

    for (int i = number.length() - 1; i > 0 && cnt < k; i--) {
        if (number[i - 1] > number[i]) {
            number.erase(i, 1);
            cnt++;
            i = number.length();
        }
    }

    return number;
}