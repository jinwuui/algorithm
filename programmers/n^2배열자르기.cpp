#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> ans;
    for (; left <= right; left++) {
        ans.push_back(left / n >= left % n ? left / n + 1 : left % n + 1);
    }
    return ans;
}