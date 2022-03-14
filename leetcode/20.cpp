class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2) return false;
        
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            if (stk.empty()) {
                stk.push(s[i]);
                continue;
            }
            
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
            else {
                if (s[i] == ')' && stk.top() != '(') return false;
                else if (s[i] == ']' && stk.top() != '[') return false;
                else if (s[i] == '}' && stk.top() != '{') return false;
                
                stk.pop();
            }
        }
        
        return stk.empty();
    }
};