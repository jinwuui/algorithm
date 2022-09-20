#include <stack>
#include <string>
#include <vector>
#define PRICE first
#define IDX second
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int>> stk; // first: price, second: idx
    for (int i = 0; i < prices.size(); i++) {
        while (stk.size() && stk.top().PRICE > prices[i]) {
            answer[stk.top().IDX] = i - stk.top().IDX;
            stk.pop();
        }

        stk.push({prices[i], i});
    }

    while (stk.size()) {
        answer[stk.top().IDX] = prices.size() - stk.top().IDX - 1;
        stk.pop();
    }

    return answer;
}