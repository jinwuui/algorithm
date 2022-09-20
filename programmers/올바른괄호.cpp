#include <stack>
#include <string>
using namespace std;

bool solution(string s) {
    stack<char> stk;
    for (int i = 0; i < s.length(); i++) {
        if (stk.size() && stk.top() == '(' && s[i] == ')')
            stk.pop();
        else
            stk.push(s[i]);
    }

    return stk.empty();
}