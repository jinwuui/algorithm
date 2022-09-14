/// Version1 ///
#include <string>
#include <map>
using namespace std;

void format(string &s) {
    for (int i = 0; i < s.length(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') s[i] = 'a' + (s[i] - 'A');
        else if (!('a' <= s[i] && s[i] <= 'z')) s[i] = ' ';
    }
}

int solution(string str1, string str2) {
    map<string, int> mp;
    format(str1);
    format(str2);

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < str1.length() - 1; i++) {
        if (str1[i] == ' ' || str1[i + 1] == ' ') continue;
        string piece = str1.substr(i, 2);
        mp[piece]++, cnt1++;
    }
    int duple = 0;
    for (int i = 0; i < str2.length() - 1; i++) {
        if (str2[i] == ' ' || str2[i + 1] == ' ') continue;
        string piece = str2.substr(i, 2);

        cnt2++;
        if (mp[piece] > 0) {
            mp[piece]--;
            duple++;
        }
    }

    int all = cnt1 + cnt2 - duple;
    if (all <= 0) return 65536;

    return (duple * 1.0 / all * 65536);
}



/// Version2 ///
#include <string>
#include <map>
using namespace std;

int solution(string str1, string str2) {
    map<string, int> mp;
    
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < str1.length() - 1; i++) {
        if (!isalpha(str1[i]) || !isalpha(str1[i + 1])) continue;
        str1[i] = str1[i] <= 'Z' ? str1[i] - 'A' + 'a' : str1[i];
        str1[i+1] = str1[i+1] <= 'Z' ? str1[i+1] - 'A' + 'a' : str1[i+1];
        string piece = str1.substr(i, 2);
        mp[piece]++, cnt1++;
    }
    int duple = 0;
    for (int i = 0; i < str2.length() - 1; i++) {
        if (!isalpha(str2[i]) || !isalpha(str2[i + 1])) continue;
        str2[i] = str2[i] <= 'Z' ? str2[i] - 'A' + 'a' : str2[i];
        str2[i+1] = str2[i+1] <= 'Z' ? str2[i+1] - 'A' + 'a' : str2[i+1];
        string piece = str2.substr(i, 2);
        cnt2++;
        if (mp[piece] > 0) mp[piece]--, duple++;
    }

    int all = cnt1 + cnt2 - duple;
    return all > 0 ? duple * 1.0 / all * 65536 : 65536; 
}