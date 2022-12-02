#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> sticker) {
    if (sticker.size() <= 2)
        return *max_element(sticker.begin(), sticker.end());

    vector<int> dp(sticker.size());
    int answer = 0;

    // [0]=O, [last]=X
    dp[0] = sticker[0], dp[1] = max(dp[0], sticker[1]);
    for (int i = 2; i < sticker.size() - 1; i++)
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);

    answer = max(answer, *max_element(dp.begin(), dp.end() - 1));

    // [0]=X, [last]=O
    dp[1] = sticker[1], dp[2] = max(dp[1], sticker[2]);
    for (int i = 3; i < sticker.size(); i++)
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);

    answer = max(answer, *max_element(dp.begin() + 1, dp.end()));

    // [0]=X, [last]=X
    dp[1] = sticker[1], dp[2] = max(dp[1], sticker[2]);
    for (int i = 3; i < sticker.size() - 1; i++)
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);

    answer = max(answer, *max_element(dp.begin() + 1, dp.end() - 1));

    return answer;
}