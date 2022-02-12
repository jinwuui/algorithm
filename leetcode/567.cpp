class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(26);
        for (int i = 0; i < s1.length(); i++) {
            cnt[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.length(); i++) {
            if (cnt[s2[i] - 'a']) {
                vector<int> v(26);
                copy(cnt.begin(), cnt.end(), v.begin());
                
                int ok = 0;
                for (int j = i; j < i + s1.length() && j < s2.length(); j++) {
                    if (v[s2[j] - 'a']) {
                        v[s2[j] - 'a']--;
                        ok++;
                    } else {
                        i == j;
                        break;
                    }
                }
                
                if (ok == s1.length()) return true;
            }
        }
        
        return false;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        vector<int> s1cnt(26);
        vector<int> s2cnt(26);
        for (int i = 0; i < s1.length(); i++) {
            s1cnt[s1[i] - 'a']++;
            s2cnt[s2[i] - 'a']++;
        }
        
        for (int i = 0; i < s2.length() - s1.length() + 1; i++) {
            bool isOk = true;
            for (int j = 0; j < 26; j++) {
                if (s1cnt[j] != s2cnt[j]) {
                    isOk = false;
                    break;
                }
            }
            if (isOk) return true;
            
            s2cnt[s2[i] - 'a']--;
            if (i + s1.length() < s2.length())
                s2cnt[s2[i + s1.length()] - 'a']++;
        }
        
        return false;
    }
};