class Solution {
public:
    int maximumWealth(vector<vector<int>>& acc) {
        int max = 0, m = acc.size(), n = acc[0].size();
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += acc[i][j];
            }
            if (max < sum) max = sum;
        }
        return max;
    }
};