#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for (int i = 0; i < s.length(); i++) {
        if ((i == 0 || s[i - 1] == ' ') && ('a' <= s[i] && s[i] <= 'z')) {
            s[i] = s[i] - 'a' + 'A';
        } else if (!(i == 0 || s[i - 1] == ' ') &&
                   ('A' <= s[i] && s[i] <= 'Z')) {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}