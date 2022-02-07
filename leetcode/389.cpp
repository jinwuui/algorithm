// Solution 1
class Solution {
public:
    char findTheDifference(string s, string t) {
        multiset<char> st;
        
        for (int i = 0; i < t.length(); i++) {
            st.insert(t[i]);
        }
        
        for (int i = 0; i < s.length(); i++) {
            st.erase(st.find(s[i]));
        }
        
        return *st.begin();
    }
};

// Solution 2
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26);
        
        for (int i = 0; i < s.length(); i++) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']++;
        }
        cnt[t[s.length()] - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) return (char)(i + 'a');
        }
        
        return '_';
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        int ret = 0;
        for (int i = 0; i < s.length(); i++) {
            ret += t[i];
            ret -= s[i];
        }
        ret += t[s.length()];
        
        return ret;
    }
};