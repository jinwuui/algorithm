#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    int cnt_x = 0, cnt_notx = 0;
    char x, notx;

    for (int i = 0; i < s.length(); i++) {
        if (!cnt_x) {
            x = s[i];
            cnt_x++;
            continue;
        }

        if (s[i] == x)
            cnt_x++;
        else
            cnt_notx++;

        if (cnt_x == cnt_notx) {
            answer++;
            cnt_x = 0, cnt_notx = 0;
        }
    }

    if (cnt_x) answer++;
    return answer;
}