class Solution {
public:
    string removeKdigits(string num, int k) {
        int cnt = 0;
        stack<char> stk;
        for (int i = 0; i < num.length(); i++) {
            while (!stk.empty() && stk.top() > num[i] && k > cnt) {
                stk.pop();
                cnt++;
            }
            
            if (stk.size() == 0 && num[i] == '0') continue;
            stk.push(num[i]);
        }
        while (k > cnt) {
            stk.pop();
            cnt++;
        }
        string s;
        for (int i = stk.size() - 1; i >= 0; i--) {
            s += stk.top();
            stk.pop();
        }
        if (s.length() == 0) s = "0";
        reverse(s.begin(), s.end());
        return s;
    }
};