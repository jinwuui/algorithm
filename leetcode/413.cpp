class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        
        int gap = nums[1] - nums[0], ans = 0, cnt = 0;
        for (int i = 2; i < nums.size(); i++) {
            int nGap = nums[i] - nums[i - 1];
            
            if (gap == nGap) cnt++;
            else {
                gap = nGap;
                cnt = 0;
            }
            
            ans += cnt;
        }
        
        return ans;
    }
};