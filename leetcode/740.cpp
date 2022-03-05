class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> dp(nums.size() + 1);
        dp[1] = nums[0];
        int idx = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                dp[idx] += nums[i];
                continue;
            }
            
            dp[idx++] = max(dp[idx], dp[idx - 1]);
            
            if (nums[i] == nums[i - 1] + 1)
                dp[idx] = dp[idx - 2] + nums[i];
            else
                dp[idx] = max(dp[idx - 2], dp[idx - 1]) + nums[i];
        }
        
        return max(dp[idx], dp[idx - 1]);
    }
};