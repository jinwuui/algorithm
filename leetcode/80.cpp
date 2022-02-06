class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> result(nums.size());
        
        result[0] = nums[0];
        int cnt = 1;
        if (nums.size() > 1) {
            result[1] = nums[1];
            cnt++;            
        }

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != result[cnt - 1] || nums[i] != result[cnt - 2]) {
                result[cnt++] = nums[i];
            }
        }
        
        nums = result;
        return cnt;
    }
};