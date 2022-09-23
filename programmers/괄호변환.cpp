#include <bits/stdc++.h>

using namespace std;

bool isCorrect(string &s) {
    stack<char> stk;
    for (int i = 0; i < s.length(); i++) {
        if (stk.size() && stk.top() == '(' && s[i] == ')') {
            stk.pop();
        } else {
            stk.push(s[i]);
        }
    }

    return stk.empty();
}

string solution(string p) {
    if (p.length() == 0) return "";
    if (isCorrect(p)) return p;

    int l = 0, r = 0;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(')
            l++;
        else
            r++;

        if (l == r) break;
    }

    string u = p.substr(0, l + r);
    string v = p.substr(l + r, p.length() - l - r);
    string newV = solution(v);

    if (isCorrect(u)) {
        return u + newV;
    } else {
        string tmp = "(" + newV + ")";
        u.erase(u.begin());
        u.pop_back();

        for (int i = 0; i < u.length(); i++)
            if (u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';

        return tmp + u;
    }
}