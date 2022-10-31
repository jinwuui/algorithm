#include <stack>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    stack<int> stk;
    int ans = 0;
    for (int i = 0; i < ingredient.size(); i++) {
        int cur = ingredient[i];

        if (cur == 1 && stk.size() >= 3) {
            int n1 = stk.top();
            stk.pop();
            int n2 = stk.top();
            stk.pop();
            int n3 = stk.top();
            stk.pop();
            if (n1 == 3 && n2 == 2 && n3 == 1)
                ans++;
            else {
                stk.push(n3);
                stk.push(n2);
                stk.push(n1);
                stk.push(cur);
            }
        } else {
            stk.push(cur);
        }
    }
    return ans;
}