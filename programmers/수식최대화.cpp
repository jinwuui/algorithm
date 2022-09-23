#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<string> op;

vector<int> vis;

string calculate(string n1, string n2, string val) {
    int i1 = stoi(n1), i2 = stoi(n2);

    if (val == "*")
        return to_string(i1 * i2);
    else if (val == "+")
        return to_string(i1 + i2);
    else
        return to_string(i1 - i2);
}

ll ans;
void brute(vector<string> split) {
    if (split.size() == 1) {
        ans = max(ans, abs(stoll(split[0])));
        return;
    }

    for (int i = 0; i < op.size(); i++) {
        if (vis[i]) continue;

        vector<string> newSplit;
        for (int i = 0; split.size(); i++) {
            if (split[i] == op[i]) {
                string result =
                    calculate(newSplit.back(), split[i + 1], split[i]);
                newSplit.pop_back();
                newSplit.push_back(result);
            } else {
                newSplit.push_back(split[i]);
            }
        }

        vis[i] = 1;
        brute(newSplit);
        vis[i] = 0;
    }
}

ll solution(string expression) {
    vector<string> split;
    set<string> st;

    int idx = 0;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '+' || expression[i] == '-' ||
            expression[i] == '*') {
            split.push_back(expression.substr(idx, i - idx));
            split.push_back(expression.substr(i, 1));
            idx = i + 1;

            st.insert(expression.substr(i, 1));
        }
    }
    split.push_back(expression.substr(idx, expression.length() - idx));

    for (auto it = st.begin(); it != st.end(); it++)
        op.push_back(*it);

    vis.resize(op.size());

    // brute(split);
    return ans;
}