#include <string>
#include <vector>

using namespace std;

int ans = 0, ord = 0;
void brute(string &src, string s, string &word) {
    ord++;
    if (s == word)
        ans = ord - 1;

    if (ans != 0 || s.length() == src.length())
        return;

    for (int i = 0; i < src.length(); i++) {
        brute(src, s + src[i], word);
    }
}

int solution(string word) {
    string src = "AEIOU";
    ans = ord = 0;
    brute(src, "", word);

    return ans;
}