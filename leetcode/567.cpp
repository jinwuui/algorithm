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