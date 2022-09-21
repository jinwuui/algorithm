#include <bits/stdc++.h>

using namespace std;

int sum = 0, cnt = 0;
void brute(vector<int> &nums, int val, int k, int target) {
    if (k == nums.size()) {
        if (2 * val - sum == target)
            cnt++;
        return;
    }

    brute(nums, val + nums[k], k + 1, target);
    brute(nums, val, k + 1, target);
}

int solution(vector<int> numbers, int target) {
    sum = cnt = 0;
    for (int i = 0; i < numbers.size(); i++)
        sum += numbers[i];

    brute(numbers, 0, 0, target);
    return cnt;
}