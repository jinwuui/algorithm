#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int n = topping.size();
    vector<int> cnt(11111);
    int total = 0, cnt_a = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[topping[i]] == 0) total++;
        cnt[topping[i]]++;
    }
    vector<int> a(11111);
    for (int i = 0; i < n; i++) {
        if (a[topping[i]] == 0) cnt_a++;
        a[topping[i]]++;
        if (a[topping[i]] == cnt[topping[i]]) total--;
        if (total == cnt_a) ans++;
    }
    return ans;
}