#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    map<string, int> mp;
    int ans = 0;

    for (int i = 0; i < 9; i++) mp[discount[i]]++;

    for (int i = 9; i < discount.size(); i++) {
        mp[discount[i]]++;

        bool isOk = true;
        for (int j = 0; j < want.size(); j++) {
            if (mp[want[j]] < number[j]) {
                isOk = false;
                break;
            }
        }
        if (isOk) ans++;

        mp[discount[i - 9]]--;
    }

    return ans;
}