class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        
        while (--n) {
            int seat = n * 2 + 1;
            ans = (ans * (seat * (1 + seat)) / 2) % 1000000007;
        }
        
        return ans;
    }
};