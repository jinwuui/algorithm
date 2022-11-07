#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cards) {
    vector<int> vis(cards.size());
    pair<int, int> maxv;

    for (int i = 0; i < cards.size(); i++) {
        if (vis[i]) continue;

        int s = i, idx = i, count = 1;
        vis[idx] = 1;
        while (s != cards[idx] - 1) {
            idx = cards[idx] - 1;
            count++;
            vis[idx] = 1;
        }

        if (maxv.first <= count) {
            maxv = {count, maxv.first};
        } else if (maxv.second < count) {
            maxv = {maxv.first, count};
        }
    }
    return maxv.first * maxv.second;
}