#include <math.h>
#include <vector>
using namespace std;

int solution(vector<int> nums) {
    vector<int> vis(200001);
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (!vis[nums[i]])
            cnt++;
        vis[nums[i]]++;
    }

    return cnt < nums.size() / 2 ? cnt : nums.size();
}