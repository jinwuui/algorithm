#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    stack<int> stk;
    int cur = 1, ans = 0, index = 0;
    while (index < order.size() && cur <= order.size() + 1) {
        if (order[index] == cur) {
            ans++, cur++;
            index++;
        } else if (stk.size() && order[index] == stk.top()) {
            ans++, index++;
            stk.pop();
        } else {
            stk.push(cur++);
        }
    }
    return ans;
}