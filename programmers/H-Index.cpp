#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());

    int ans = -1;
    for (int i = 0; i < 10000; i++) {
        int idx = lower_bound(citations.begin(), citations.end(), i) -
                  citations.begin();
        if (citations.size() - idx >= i)
            ans = i;
    }
    return ans;
}